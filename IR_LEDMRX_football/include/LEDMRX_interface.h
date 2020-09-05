/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 31 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);
void HLEDMRX_voidAnimation(u8 *Copy_u8Data);
void HLEDMRX_voidAnimateFrames(u8 Copy_u8FramesVal[][8], u8 Copy_u8FramesNum);
void HLEDMRX_voidPauseAnimating(void);
void HLEDMRX_voidResumeAnimating(void);
void HLEDMRX_voidSpeedDown(void);
void HLEDMRX_voidSpeedUp(void);


#endif
