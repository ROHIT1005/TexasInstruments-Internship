#include <msp430g2553.h>

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
    P1DIR|=0xFF;
    P1OUT&=~0xFF;
    P2DIR|=BIT0;

    while(1){

    	P2OUT|=BIT0;
    	P1OUT=~0x3F; //0
    	_delay_cycles(1000000);
    	P1OUT=~0x06; //1
    	_delay_cycles(1000000);
    	P1OUT=~0x5B; //2
    	_delay_cycles(1000000);
    	P1OUT=~0x4F; //3
    	_delay_cycles(1000000);
    	P1OUT=~0x66; //4
    	_delay_cycles(1000000);
    	P1OUT=~0x6D; //5
    	_delay_cycles(1000000);
    	P1OUT=~0x7D; //6
    	_delay_cycles(1000000);
    	P1OUT=~0x07; //7
    	_delay_cycles(1000000);
    	P1OUT=~0x7F; //8
    	_delay_cycles(1000000);
    	P1OUT=~0x6F; //9
    	_delay_cycles(1000000);
    }
}
