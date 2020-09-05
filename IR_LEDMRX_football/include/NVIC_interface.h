/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidInit(void);
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 copy_s8PerIdx, u8 copy_u8Priority);

#endif
