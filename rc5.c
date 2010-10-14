/**
*  RC5 Remote Receiver 
*  Based on code by Peter Dannegger (danni@specs.de)
**/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "rc5.h"


uint8_t rc5_bit;				// bit value
uint8_t rc5_time;				// count bit time
uint16_t rc5_tmp;				// shift bits in


void rc5_init(void) {
  RC5_DDR &= ~(1 << RC5_PIN);		//set pin as input
  TCCR0B = 1<<CS02;			//divide by 256
  TIMSK0 = 1<<TOIE0;			//enable timer interrupt
}

ISR (SIG_OVERFLOW0)
{
  uint16_t tmp = rc5_tmp;			// for faster access

  TCNT0 = -2;					// 2 * 256 = 512 cycle

  if( ++rc5_time > RC5_PULSE_MAX ){			// count pulse time
    if( !(tmp & 0x4000) && tmp & 0x2000 )	// only if 14 bits received
      rc5_data = tmp;
    tmp = 0;
  }

  if( (rc5_bit ^ RC5_PORT) & 1<<RC5_PIN ){		// change detect
    rc5_bit = ~rc5_bit;				// 0x00 -> 0xFF -> 0x00

    if( rc5_time < RC5_PULSE_MIN )			// to short
      tmp = 0;

    if( !tmp || rc5_time > RC5_PULSE_1_2 ){		// start or long pulse time
      if( !(tmp & 0x4000) )			// not to many bits
        tmp <<= 1;				// shift
      if( !(rc5_bit & 1<<RC5_PIN) )		// inverted bit
        tmp |= 1;				// insert new bit
      rc5_time = 0;				// count next pulse time
    }
  }

  rc5_tmp = tmp;
}
