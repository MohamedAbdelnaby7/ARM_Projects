/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 22 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define LINE0		0
#define LINE1		1
#define LINE2		2
#define LINE3		3
#define LINE4		4
#define LINE5		5
#define LINE6		6
#define LINE7		7
#define LINE8		8
#define LINE9		9
#define LINE10		10
#define LINE11		11
#define LINE12		12
#define LINE13		13
#define LINE14		14
#define LINE15		15

#define FALLING		0
#define RISING		1
#define CHANGING	2

void MEXTI_voidInit();
void MEXTI_voidSetSignallatch(u8 Copy_u8Line, u8 Copy_u8SenseMode);
void MEXTI_voidEnableEXTI(u8 Copy_uLine);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSoftWareTrigger(u8 Copy_u8Line);

void MEXTI_voidSetCallBack(void(*ptr)(void), u8 Copy_u8Line);

#endif
