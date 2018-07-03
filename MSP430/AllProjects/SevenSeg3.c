#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {

	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timerm,
    P1DIR|=0xFF;
    P1OUT&=~0xFF;
    P2DIR|=0xFF;
    //P2OUT&=~0xFF;


    while(1){

    	P1OUT=BIT7;
    	P1OUT=~0x06; //1
    	_delay_cycles(1000);

    	P2OUT=BIT2;
    	P1OUT=~0x5B; //2
    	_delay_cycles(1000);

    	P2OUT=BIT1;
    	P1OUT=~0x4F; //3
    	_delay_cycles(1000);

    	P2OUT=BIT0;
    	P1OUT=~0x66; //4
    	_delay_cycles(1000);

    	   }
}
