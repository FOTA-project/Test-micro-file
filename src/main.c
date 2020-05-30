// libs
#include "STD_TYPES.h"
#include "BIT_MAN.h"
#include "Delay_interface.h"
// MCAL
#include "RCC_interface.h"
#include "DIO_interface.h"

#include "DIO_registers.h"
#include <diag/Trace.h>

void main(void)
{
	/* init clocks */
	RCC_init();

	/* enable and config. PLL */
	RCC_setClockState(RCC_CLOCK_HSE, 1);
	RCC_setPLLHSEdiv2(0);
	RCC_setPLLmul(RCC_PLL_MUL9);
	RCC_setPLLsource(RCC_PLL_SOURCE_HSE);
	RCC_changeSysClock(RCC_CLOCK_PLL);
	RCC_setClockState(RCC_CLOCK_HSI, 0);

	RCC_changeSysClock(RCC_CLOCK_HSE);

	/* enable clocks for ports C */
	RCC_setPeripheralClock(RCC_BUS_APB2, RCC_PERI_GPIOC, 1);

	/* set C13 to output push-pull 50MHz */
	DIO_setPinMode('C', 13, DIO_PIN_MODE_OUT_PUSH_PULL_50MHZ);
	DIO_setPinVal('C', 13, 1);

	trace_printf("Before config delay\n");

	/* configure delay function */
	delay_setCPUclockFactor(8000000);

   trace_printf("After config delay\n");

	while (1)
	{
		//DIO_setPinVal('C', 13, 0);
		PORTC_ODR = 0x00000000;
		delay_ms(1000);

		//DIO_setPinVal('C', 13, 1);
		PORTC_ODR = 0x00002000;
		delay_ms(1000);
	}
}
