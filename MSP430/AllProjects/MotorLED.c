#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    P1DIR|=BIT0; // making BIT1 as o/p
    P1OUT&=~BIT0; // passing 3.3V to BIT1

    P1DIR|=BIT6; // making BIT1 as o/p
    P1OUT&=~BIT6; // passing 3.3V to BIT1

	P1DIR|=BIT1; // making BIT1 as o/p
	P1OUT&=~BIT1; // passing 3.3V to BIT1

	P1DIR|=BIT2; // making BIT2 as o/p
	P1OUT&=~BIT2; // passing 3.3V to BIT2

	P1DIR|=BIT4; // making BIT3 as o/p
	P1OUT&=~BIT4; // passing 3.3V to BIT3

	P1DIR|=~BIT3; // making BIT3 as i/p
	P1REN|=BIT3; // making pull-up
	P1OUT|=BIT3; //

	P1IE|=BIT3; // setting BIT3 to receive the interrupt
	P1IES|=BIT3; // using high-to-low transition as interrupt
	__bis_SR_register(GIE); //setting the function register GIE

	P1OUT|=BIT1; // keeping the enable pin always high

	P1OUT|=BIT6; // keeping GRREN_LED on
	P1OUT|=BIT2; // keeping  one of the direction on

	P1OUT&=~BIT0;
	P1OUT&=~BIT4;

	while(1); // infinite loop to prevent the exiting of the program
	}

	#pragma vector=PORT1_VECTOR // telling the compiler its a PORT1 interrupt n specifies the interrupt address in the IVT so the following ISR sits there
	__interrupt void button(void) // telling the compiler its a ISR
	{
		P1IES^=BIT3;
		P1IFG&=~BIT3; // clearing the interrupt flag to acknowledge it

		P1OUT^=BIT0; // toggling of the led; first press ON n next OFF
		P1OUT^=BIT2;
		P1OUT^=BIT4;
		P1OUT^=BIT6;
	}
