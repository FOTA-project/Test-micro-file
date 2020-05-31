// libs
#include "STD_TYPES.h"
// MCAL
#include "DIO_registers.h"
#include "RCC_registers.h"

void main(void)
{
   int i;

   RCC_APB2ENR |= 1 << 4;

	/* set C13 to output push-pull 50MHz */
   PORTC_CR &= ~((u64)0b1111 << (13 * 4));
   PORTC_CR |= (u64)0b0010 << (13 * 4);

	while (1)
	{
		//DIO_setPinVal('C', 13, 0);
		PORTC_ODR = 0x00000000;
		for (i = 0; i < 300000; i++)
		{

		}

		//DIO_setPinVal('C', 13, 1);
		PORTC_ODR = 0x00002000;
      for (i = 0; i < 300000; i++)
      {

      }
	}
}
