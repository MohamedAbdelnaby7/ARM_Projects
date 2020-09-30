/********************************************************************/
/* Author	: MOHAMED ABDELNABY									 	*/
/* Date		: 08 Aug 2020                                           */
/* Version	: V01                                                   */
/********************************************************************/

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H
 
/*Register configuration*/
/* base add of RCC is ox40021000*/

#define RCC_CR 			*((volatile u32*)0x40021000)
#define RCC_CFGR		*((volatile u32*)0x40021004)
#define RCC_CIR 		*((volatile u32*)0x40021008)
#define RCC_APB2RSTR 	*((volatile u32*)0x4002100c)
#define RCC_APB1RSTR 	*((volatile u32*)0x40021010)
#define RCC_AHBENR 		*((volatile u32*)0x40021014)
#define RCC_APB2ENR 	*((volatile u32*)0x40021018)
#define RCC_APB1ENR 	*((volatile u32*)0x4002101c)
#define RCC_BDCR 		*((volatile u32*)0x40021020)
#define RCC_CSR 		*((volatile u32*)0x40021024)

/*Define Clock types*/
#define RCC_HSE_CRYSTAL	0
#define RCC_HSE_RC		1	
#define RCC_HSI			2
#define RCC_PLL			3

/*PLL types*/
#define RCC_PLL_IN_HSI_DIV_2			0
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2	1
#define RCC_PLL_IN_HSE_RC_DIV_2			2
#define RCC_PLL_IN_HSE_CRYSTAL 			3
#define RCC_PLL_IN_HSE_RC				4
		
/*Multiplication factor types*/
#define NO_CLOCK_FACTOR                                0b0000
#define PLL_CLOCK_MULTIPLE_BY_2                        0b0000
#define PLL_CLOCK_MULTIPLE_BY_3					       0b0001
#define PLL_CLOCK_MULTIPLE_BY_4                        0b0010
#define PLL_CLOCK_MULTIPLE_BY_5                        0b0011
#define PLL_CLOCK_MULTIPLE_BY_6                        0b0100
#define PLL_CLOCK_MULTIPLE_BY_7                        0b0101
#define PLL_CLOCK_MULTIPLE_BY_8                        0b0110
#define PLL_CLOCK_MULTIPLE_BY_9                        0b0111
#define PLL_CLOCK_MULTIPLE_BY_10                       0b1000
#define PLL_CLOCK_MULTIPLE_BY_11                       0b1001
#define PLL_CLOCK_MULTIPLE_BY_12                       0b1010
#define PLL_CLOCK_MULTIPLE_BY_13                       0b1011
#define PLL_CLOCK_MULTIPLE_BY_14                       0b1100
#define PLL_CLOCK_MULTIPLE_BY_15                       0b1101
#define PLL_CLOCK_MULTIPLE_BY_16                       0b1110

#endif
