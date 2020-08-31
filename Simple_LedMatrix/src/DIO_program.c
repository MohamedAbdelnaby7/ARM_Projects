/********************************************************************/
/* Author	: MOHAMED ABDELNABY								 	 	*/
/* Date		: 12 Aug 2020                                           */
/* Version	: V01                                                	*/
/********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
		 
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8MODE)
{
	//Check which port A, B, C, D, E, F, G is selected
	switch(Copy_u8PORT)
	{
		/*After knowing the port, check if the the pin between 0:7 -> CRL
		  or 8:15 -> CRH
		  */
		case GPIOA:
					if(Copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOA_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					else if (Copy_u8PIN <= 15)              
					{                                       
						Copy_u8PIN -= 8;                    
						GPIOA_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOA_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					break;                                  
		case GPIOB:                                         
					if(Copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOB_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					else if (Copy_u8PIN <= 15)              
					{                                       
						Copy_u8PIN -= 8;                    
						GPIOB_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOB_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					break;  
		case GPIOC:
					if(Copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOC_CRL |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					else if (Copy_u8PIN <= 15)              
					{                                       
						Copy_u8PIN -= 8;                    
						GPIOC_CRH &= ~ 	((0b1111) 		<< (Copy_u8PIN * 4));
						GPIOC_CRH |= 	((Copy_u8MODE)  << (Copy_u8PIN * 4));
					}                                       
					break; 
		default:
					break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
	//Check on the port Number
	switch(Copy_u8PORT)
	{
		//set or clear the value of that pin
		case GPIOA:
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOA_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOA_ODR, Copy_u8PIN);
					}
					break;
		case GPIOB:
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOB_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOB_ODR, Copy_u8PIN);
					}
					break;
		case GPIOC:
					if(Copy_u8Value == HIGH)
					{
						SET_BIT(GPIOC_ODR, Copy_u8PIN);
					}
					else
					{
						CLR_BIT(GPIOC_ODR, Copy_u8PIN);
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

u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 loc_u8Result = 0;
	switch(Copy_u8PORT)
	{
		case GPIOA:
					loc_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);
					break;
		case GPIOB:
					loc_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);
					break;
		case GPIOC:
					loc_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);
					break;
		default:
					break;
	}
	return loc_u8Result;
}