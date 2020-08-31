/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 08 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/*clock options:  	RCC_HSE_CRYSTAL
					RCC_HSE_RC
					RCC_HSI
					RCC_PLL 		*/
			
#define RCC_CLOCK_TYPE RCC_HSE_CRYSTAL


#if RCC_CLOCK_TYPE == RCC_PLL
	/*PLL options:	RCC_PLL_IN_HSI_DIV_2
					RCC_PLL_IN_HSE_CRYSTAL_DIV_2
					RCC_PLL_IN_HSE_RC_DIV_2
					RCC_PLL_IN_HSE_CRYSTAL 
					RCC_PLL_IN_HSE_RC				   
				   */		
	/*Note: Select value only if you have chosen PLL as input clock source */
	#define RCC_PLL_INPUT		RCC_PLL_IN_HSE_DIV_2
	
	//********************************************/
	/*          ClockFactor For PLL  Maybe :     */
	/*          0-NO_CLOCK_FACTOR                */
	/*          1-PLL_Clock_MULTIPLE_BY_2        */
	/*          2-PLL_Clock_MULTIPLE_BY_3        */
	/*          3-PLL_Clock_MULTIPLE_BY_4        */
	/*          4-PLL_Clock_MULTIPLE_BY_5        */
	/*          5-PLL_Clock_MULTIPLE_BY_6        */
	/*          6-PLL_Clock_MULTIPLE_BY_7        */
	/*          7-PLL_Clock_MULTIPLE_BY_8        */
	/*          8-PLL_Clock_MULTIPLE_BY_9        */
	/*          9-PLL_Clock_MULTIPLE_BY_10       */
	/*          10-PLL_Clock_MULTIPLE_BY_11      */
	/*          11-PLL_Clock_MULTIPLE_BY_12      */
	/*          12-PLL_Clock_MULTIPLE_BY_13      */
	/*          13-PLL_Clock_MULTIPLE_BY_14      */
	/*          14-PLL_Clock_MULTIPLE_BY_15      */
	/*          15-PLL_Clock_MULTIPLE_BY_16      */
	/*********************************************/
	
	#define CLOCK_FACTOR     PLL_CLOCK_MULTIPLE_BY_4
	
#endif

#endif			   