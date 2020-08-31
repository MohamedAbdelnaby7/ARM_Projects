#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

u8 DataArray[38] = {120, 4, 8, 16, 8, 4, 120, 0, 56, 68, 68, 56, 0, 124, 16, 112, 0, 120, 20, 20, 120, 0, 124, 8, 120, 8, 120, 0, 124, 84, 92, 0, 112, 80, 124, 0, 0, 0};

void main (void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(APB2, IOPA);
	MRCC_voidEnableClock(APB2, IOPB);

	MSTK_voidInit();
	HLEDMRX_voidInit();

	HLEDMRX_voidAnimation(DataArray);
}
