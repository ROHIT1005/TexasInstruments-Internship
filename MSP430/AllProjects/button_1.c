/*
 * button.c
 *
 *  Created on: Dec 20, 2017
 *      Author: HD
 */
#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	P1DIR|=BIT0; // making BIT0 as o/p
	P1OUT&=~BIT0; // passing 3.3V to BIT0

	P1DIR|=BIT6; // making BIT6 GREEN_LED as o/p
	P1OUT&=~BIT6; // passing 3.3V to BIT6

	P1DIR&=~BIT3; // making BIT3 as i/p
	P1REN|=BIT3; // enabling pull-up n pull-down
	P1OUT|=BIT3; // make it pull-up



	while(1) // continuous evaluation for button to be pressed
	{
	if(P1IN&BIT3) // Here BIT3 when pressed becomes 0 or GND and in if() we get 0
	{
		P1OUT&=~BIT6;// GREEN_LED is kept off
		P1OUT&=~BIT0;
			}
	else // Here true condition is achieved
	{
		P1OUT|=BIT6; // GREEN_LED is turned on
		P1OUT&=~BIT0;
	}
	while(1&BIT6)
	{
	if (P1IN&BIT3)
	{
		P1OUT&=~BIT0;
		P1OUT&=~BIT6;
	}
	else
	{
		P1OUT|=BIT0;
		P1OUT&=~BIT6;
	}
	}
	}


	return 0;
}








