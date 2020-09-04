/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 19 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

/*00xE000E100  NCIV base address*/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0		*((volatile u32*)0xE000E100) /*Enable external interrupts 0:31	*/
#define NVIC_ISER1		*((volatile u32*)0xE000E104) /*Enable external interrupts 32:59	*/

#define NVIC_ICER0		*((volatile u32*)0xE000E180) /*Disable external interrupts 0:31	*/
#define NVIC_ICER1		*((volatile u32*)0xE000E184) /*Disable external interrupts 32:59*/

#define NVIC_ISPR0		*((volatile u32*)0xE000E200) /*Set the pending flag 0:31*/
#define NVIC_ISPR1		*((volatile u32*)0xE000E204) /*Set the pending flag 32:59*/

#define NVIC_ICPR0		*((volatile u32*)0xE000E280) /*Clear the pending flag 0:31*/
#define NVIC_ICPR1		*((volatile u32*)0xE000E284) /*Clear the pending flag 32:59*/

#define NVIC_IABR0		*((volatile u32*)0xE000E300)
#define NVIC_IABR1		*((volatile u32*)0xE000E304)

#define NVIC_IPR		((volatile u8*)0xE000E400)

#define MVIC_GROUP_4_SUB_0	0x05FA0300	//4 bits for group and 0 bit for sub
#define MVIC_GROUP_3_SUB_1	0x05FA0400	//3 bits for Group and 1 bit for sub
#define MVIC_GROUP_2_SUB_2	0x05FA0500	//2 bits for Group and 2 bit for sub
#define MVIC_GROUP_1_SUB_3	0x05FA0600	//1 bits for Group and 3 bit for sub
#define MVIC_GROUP_0_SUB_4	0x05FA0700	//0 bits for Group and 1 bit for sub


#endif
