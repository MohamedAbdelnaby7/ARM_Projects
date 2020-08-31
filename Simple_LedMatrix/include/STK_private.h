/*********************************************************************************/
/* Author    : shimo		                                                     */
/* Version   : V01                                                               */
/* Date      : 26 Aug 2020                                                       */
/*********************************************************************************/
#ifndef SysTick_PRIVATE_H
#define SysTick_PRIVATE_H

/* Register Definitions */
typedef struct{
	volatile u32 CTRL	; 		/* controls the clock, enable and interrupt enable, flag bit */
	volatile u32 LOAD	;		/* stores the const value */
	volatile u32 VAL	; 		/* counts down from the value i the load */
	volatile u32 CALIB	;
}SysTick_t;

#define SysTick ((SysTick_t *) 0xE000E010)


/* bits difinitions */

#define ENABLE		0
#define TICK_IRQ 	1
#define CLK_SRC 	2
#define COUNT_FLAG  16

#endif
