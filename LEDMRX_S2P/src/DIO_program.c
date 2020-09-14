/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 08 Sep 2020                                           */
/* Version	: V03                                               	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
		 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8MODE)
{
	//Check which port A, B, C, D, E, F, G is selected
	switch(copy_u8PORT)
	{
		/*After knowing the port, check if the the pin between 0:7 -> CRL
		  or 8:15 -> CRH
		  */
		case GPIOA:
					if(copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOA_CRL |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					else if (copy_u8PIN <= 15)              
					{                                       
						copy_u8PIN -= 8;                    
						GPIOA_CRH &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOA_CRH |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					break;                                  
		case GPIOB:                                         
					if(copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOB_CRL |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					else if (copy_u8PIN <= 15)              
					{                                       
						copy_u8PIN -= 8;                    
						GPIOB_CRH &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOB_CRH |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					break;  
		case GPIOC:
					if(copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOC_CRL |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					else if (copy_u8PIN <= 15)              
					{                                       
						copy_u8PIN -= 8;                    
						GPIOC_CRH &= ~ 	((0b1111) 		<< (copy_u8PIN * 4));
						GPIOC_CRH |= 	((copy_u8MODE)  << (copy_u8PIN * 4));
					}                                       
					break; 
		default:
					break;
	}
}

void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
					if(copy_u8Value == HIGH)
					{
						SET_BIT(GPIOA_ODR, copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOA_ODR, copy_u8PIN);
					}
					break;
		case GPIOB:
					if(copy_u8Value == HIGH)
					{
						SET_BIT(GPIOB_ODR, copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOB_ODR, copy_u8PIN);
					}
					break;
		case GPIOC:
					if(copy_u8Value == HIGH)
					{
						SET_BIT(GPIOC_ODR, copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOC_ODR, copy_u8PIN);
					}
					break;
		default:
					break;
	}
}

void MGPIO_VoidTogPin(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					TOG_BIT(GPIOA_ODR, Copy_u8PIN);
					break;
		case GPIOB :
					TOG_BIT(GPIOB_ODR, Copy_u8PIN);
					break;
		case GPIOC :
					TOG_BIT(GPIOC_ODR, Copy_u8PIN);
					break;
		default	:	
					break;
	}
}

u8 MGPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 loc_u8Result = 0;
	switch(copy_u8PORT)
	{
		case GPIOA:
					loc_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN);
					break;
		case GPIOB:
					loc_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN);
					break;
		case GPIOC:
					loc_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN);
					break;
		default:
					break;
	}
	return loc_u8Result;
}

void MGPIO_voidSetPortValue(u8 Copy_u8PORT, u8 Copy_u8PortValue)
{
	switch(Copy_u8PORT)
		{
			case GPIOA :
						GPIOA_ODR = Copy_u8PortValue;
						break;
			case GPIOB :
						GPIOB_ODR = Copy_u8PortValue;
						break;
			case GPIOC :
						GPIOC_ODR = Copy_u8PortValue;
						break;
			default	:
						break;
		}
}

void MGPIO_voidSetRestPortValue(u8 Copy_u8PORT, u8 Copy_u8PortValue)
{
	u16 Local_BSRRValue = ( ( (~Copy_u8PortValue) << 8) | (Copy_u8PortValue) );
	switch(Copy_u8PORT)
			{
				case GPIOA :
							GPIOA_BSRR = Local_BSRRValue;
							break;
				case GPIOB :
							GPIOB_BSRR = Local_BSRRValue;
							break;
				case GPIOC :
							GPIOC_BSRR = Local_BSRRValue;
							break;
				default	:
							break;
			}
}

void MGPIO_voidSetPinsValue(u8 Copy_u8PORT, u8 Copy_u8PortValue)
{
	switch(Copy_u8PORT)
			{
				case GPIOA :
							GPIOA_BSRR = Copy_u8PortValue;
							break;
				case GPIOB :
							GPIOB_BSRR = Copy_u8PortValue;
							break;
				case GPIOC :
							GPIOC_BSRR = Copy_u8PortValue;
							break;
				default	:
							break;
			}
}

void MGPIO_voidRestPinsValue(u8 Copy_u8PORT, u8 Copy_u8PortValue)
{
	switch(Copy_u8PORT)
			{
				case GPIOA :
							GPIOA_BRR = Copy_u8PortValue;
							break;
				case GPIOB :
							GPIOB_BRR = Copy_u8PortValue;
							break;
				case GPIOC :
							GPIOC_BRR = Copy_u8PortValue;
							break;
				default	:
							break;
			}
}
