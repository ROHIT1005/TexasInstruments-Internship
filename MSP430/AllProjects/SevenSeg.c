#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    P1DIR|=BIT0; // making BIT1 as o/p
    P1OUT&=~BIT0; // passing 3.3V to BIT1

    P1DIR|=BIT1; // making BIT1 as o/p
    P1OUT&=~BIT1; // passing 3.3V to BIT1

	P1DIR|=BIT2; // making BIT1 as o/p
	P1OUT&=~BIT2; // passing 3.3V to BIT1

	P1DIR|=BIT3; // making BIT2 as o/p
	P1OUT&=~BIT3; // passing 3.3V to BIT2

	P1DIR|=BIT4; // making BIT3 as o/p
	P1OUT&=~BIT4; // passing 3.3V to BIT3

	P1DIR|=BIT5; // making BIT3 as o/p
	P1OUT&=~BIT5; // passing 3.3V to BIT3

	P1DIR|=BIT6; // making BIT3 as o/p
	P1OUT&=~BIT6; // passing 3.3V to BIT3

	P2DIR|=BIT0;
	P2OUT&=~BIT0;

	P2OUT|=BIT0;

	while(1){

		P1OUT|=~BIT0;
		P1OUT|=~BIT1;
		P1OUT|=~BIT2;
		P1OUT|=~BIT3;
		P1OUT|=~BIT4;
		P1OUT|=~BIT5;
		P1OUT|=~BIT6;
	}
}

