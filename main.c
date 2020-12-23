/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 17 DEC 2020                                */
/* Version   : V01                                        */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "LEDMRX_interface.h"

#include "IR_interface.h"
#include "EXTI0_interface.h"
#include "NVIC_interface.h"

#include "LEDMRX_interface.h"

void NameDisplay(u8 * Copy_u8DataArray ,u8 Copy_u8DataArrayIndex);
void PlayFootBall(u8 * Copy_u8Play1 , u8 * Copy_u8Play2);
void BellyDance(u8 * Copy_u8Dance1 , u8 * Copy_u8Dance2 , u8 * Copy_u8Dance3 , u8 * Copy_u8Dance4);

extern volatile u32 u32RemoteData;

u8 DataArrayIndex =27;
u8 DataArray[27]={0, 2, 30, 2, 0, 12, 18, 18, 12, 0, 30, 12, 18, 0, 28, 10, 10, 28 ,0 };
u8 index =0 ;
u8 LedMatrixIndex =8;
u8 PlayerAcc1[8]={0, 0, 214, 126, 214, 0, 128, 0};
u8 PlayerAcc2[8]={0, 0, 214, 126, 86, 64, 4, 0};
u8 u8Dance1[8]={0, 8, 203, 127, 203, 8, 0, 0};
u8 u8Dance2[8]={0, 8, 203, 127, 75, 88, 0, 0};
u8 u8Dance3[8]={0, 88, 75, 127, 203, 8, 0, 0};
u8 u8Dance4[8]={0, 88, 75, 127, 75, 88, 0, 0};
void voidPlay(void)
{
	switch (u32RemoteData)
	{

		case ZERO:NameDisplay(DataArray, DataArrayIndex); break;
		case ONE:PlayFootBall(PlayerAcc1 , PlayerAcc2); break;
		case TWO:BellyDance(u8Dance1 , u8Dance2 , u8Dance3 , u8Dance4); break;

	}
}
void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2, 3);  /* GPIOB Enable Clock */

	/* IO Pins Initialization */
	GPIO_voidSetPinDirection(GPIOA,0,0b0100);  /*  A0 Input Floating  */

	HLEDMRX_VoidInit();
	IR_voidInit();



	for(u8 DataIndex= DataArrayIndex-LedMatrixIndex ; DataIndex< DataArrayIndex ; DataIndex++)
	{
		DataArray[DataIndex]=DataArray[index];
		index++;
	}
	while(1)
	{

			voidPlay();

	}

}

