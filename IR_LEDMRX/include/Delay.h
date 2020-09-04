/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 15 Aug 2020                                                       */
/*********************************************************************************/
#ifndef DELAY_H_
#define DELAY_H_

/* defining the system clock */
#ifndef SYSTEM_CLOCK
#define SYSTEM_CLOCK 8000000
#endif

/* public functions prototypes */

/******************************************************************************
* Description : generating a micro second delay 
* Parameters  : Copy_u32Time (the required delay in micro seconds)
* Return type : void
******************************************************************************/
void delay_ms(u32 Copy_u32Time) ;

#endif
