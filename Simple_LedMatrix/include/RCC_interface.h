/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	    */
/* Date		: 08 Aug 2020                                           */
/* Version	: V01                                                   */
/********************************************************************/

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

//RCC BUSES
#define AHB		0
#define APB2	1 
#define APB1	2	

//Peripherals on AHB bus
#define DMA1   	0
#define DMA2	1
#define SRAM    2
#define FLIT    4
#define CRCE    6
#define FSMC    8
#define SDIO    10

//Peripherals on APB2
#define AFIO	0
#define IOPA	2
#define IOPB	3
#define IOPC	4
#define IOPD	5
#define IOPE	6
#define IORF	7
#define IORG	8
#define ADC1	9
#define ADC2	10
#define TIM1	11
#define SPI1	12
#define TIM8	13
#define USART1	14
#define ADC3	15
#define TIM9	19
#define TIM10	20
#define TIM11	21

//Peripherals on APB1 bus
#define	TIM2	0
#define	TIM3	1
#define	TIM4	2
#define	TIM5	3
#define	TIM6	4
#define	TIM7	5
#define	TIM12	6
#define	TIM13	7
#define	TIM14	8
#define	WWD		11
#define	SPI2	14
#define	SPI3	15
#define	USART2	17
#define	USART3	18
#define	UART4	19
#define	UART5	20
#define	I2C1	21
#define	I2C2	22
#define	USB		23
#define	CAN		25
#define	BKP		27
#define	PWR		28
#define DAC		29

void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidInitSysClock(void);


#endif