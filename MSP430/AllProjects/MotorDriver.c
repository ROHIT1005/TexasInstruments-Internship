#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	P1DIR|=BIT1; // making BIT1 as o/p
	P1OUT&=~BIT1; // passing 3.3V to BIT1

	P1DIR|=BIT2; // making BIT2 as o/p
	P1OUT&=~BIT2; // passing 3.3V to BIT2

	P1DIR|=BIT3; // making BIT3 as o/p
	P1OUT&=~BIT3; // passing 3.3V to BIT3


	while(1)
	{
		P1OUT|=BIT1; // Enable pin always high

		P1OUT|=BIT2; // Driving motor in clockwise direction

	}


	return 0;
}
