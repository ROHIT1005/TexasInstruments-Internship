#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	P1DIR|=BIT0; // making BIT0 as o/p
	P1OUT&=~BIT0; // passing 3.3V to BIT0

	P1DIR|=BIT6; // making BIT6 as o/p
	P1OUT&=~BIT6; // passing 3.3V to BIT6

	P1DIR|=~BIT3; // making BIT3 as i/p

	P1REN|=BIT3; // making pull-up
	P1OUT|=BIT3;




	if(P1OUT)

	while(1)
	{
		P1OUT|=BIT6;
		_delay_cycles(100000); //delay between on n off
		P1OUT&=~BIT6;

		P1OUT|=BIT0;
		_delay_cycles(100000); //delay between on n off
		P1OUT&=~BIT0;


	}

	
	return 0;
}
