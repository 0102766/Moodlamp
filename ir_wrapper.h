
/* 		RC Commands		*/



//	Functions on Remote Control
#define RC_CHINARGB_BRIGHTER	5		
#define RC_CHINARGB_DARKER		4
#define RC_CHINARGB_OFF			6		
#define RC_CHINARGB_ON			7		
#define RC_CHINARGB_FLASH		15		
#define RC_CHINARGB_STROBE		23	
#define RC_CHINARGB_FADE		27
#define RC_CHINARGB_SMOOTH		19

//	Colors on Remote Control
#define RC_CHINARGB_RED			9		
#define RC_CHINARGB_GREEN		8
#define RC_CHINARGB_BLUE		10
#define RC_CHINARGB_WHITE		11

#define RC_CHINARGB_RED1		13
#define RC_CHINARGB_RED2		21
#define RC_CHINARGB_RED3		25
#define RC_CHINARGB_RED4		17

#define RC_CHINARGB_GREEN1		12
#define RC_CHINARGB_GREEN2		20
#define RC_CHINARGB_GREEN3		24
#define RC_CHINARGB_GREEN4		16

#define RC_CHINARGB_BLUE1		14
#define RC_CHINARGB_BLUE2		22
#define RC_CHINARGB_BLUE3		26
#define RC_CHINARGB_BLUE4		18


void ir_init();
void ir_handler();
