/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 03 Sep 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

#define STOP		69
#define MODE		70
#define MUTE		71
#define ON			68
#define NEXT		64
#define BACK		67
#define EQ			128
#define VOL_DOWN	21
#define VOL_UP		9
#define ZERO		72
#define RPT			25
#define U_SD		13
#define ONE			12
#define TWO			24
#define THREE		94
#define FOUR		132
#define FIVE		28
#define SIX			90
#define SEVEN		66
#define EIGHT		82
#define NINE		74

void HIR_voidGetFrame(void);
void HIR_voidExtractKey(void);
void HIR_voidGetKey(void);

void HIR_voidSetCallBack(void(*ptr)(u8 Copy_u8Key));

#endif
