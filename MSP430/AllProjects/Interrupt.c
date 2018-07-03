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
	P1OUT|=BIT3; //

	P1IE|=BIT3; // setting BIT3 to receive the interrupt
	P1IES|=BIT3; // using high-to-low transition as interrupt
	__bis_SR_register(GIE); //setting the function register GIE

	while(1); // infinite loop to prevent the exiting of the program
}

#pragma vector=PORT1_VECTOR // telling the compiler its a PORT1 interrupt n specifies the interrupt address in the IVT so the following ISR sits there
__interrupt void button(void) // telling the compiler its a ISR
{
	P1IES^=BIT3; // prevents multiple presses; ON when only pressed
	P1IFG&=~BIT3; // clearing the interrupt flag to acknowledge it
	P1OUT^=BIT0; // toggling of the led; first press ON n next OFF

}

