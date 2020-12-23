/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 26 NOV 2020                                */
/* Version   : V02                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"

const u8 NameArrayIndex=8;
u8 DisplayArray[8];
u8 count;
u8 index ;
u8 DataIndex;
u8 LedMatrixIndex;


void NameDisplay(u8 * Copy_u8DataArray ,u8 Copy_u8DataArrayIndex)
{

		for( DataIndex=0 ; DataIndex<Copy_u8DataArrayIndex-NameArrayIndex ; DataIndex++)
		{
			for( LedMatrixIndex=0 ;LedMatrixIndex<NameArrayIndex ; LedMatrixIndex++)
			{

				DisplayArray[LedMatrixIndex] = Copy_u8DataArray[DataIndex+LedMatrixIndex];

			}

			count =0;
			while (count!=20)
			{
				HLEDMRX_VoidDisplay(DisplayArray);
				count++;
			}
		}

}

void PlayFootBall(u8 * Copy_u8Play1 , u8 * Copy_u8Play2)
{

		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Play1);
			count++;
		}
		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Play2);
			count++;
		}

}
void BellyDance(u8 * Copy_u8Dance1 , u8 * Copy_u8Dance2 , u8 * Copy_u8Dance3 , u8 * Copy_u8Dance4)
{

		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance1);
			count++;
		}
		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance2);
			count++;
		}
		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance3);
			count++;
		}
		count =0;
		while (count!=20)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance4);
			count++;
		}


}
