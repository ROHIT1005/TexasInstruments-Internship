#include<msp430g2553.h>

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	TA0CTL |= TASSEL_1 + MC_1 + TACLR; // setting the source, count mode and clearing the timer
	TACCTL0 |= CCIE; // enabling the counter interrupt
	TA0CCR0 = 32767/10; //upto what number should the timer count / capturing the timer

	P1DIR|=BIT6+BIT0;

	__bis_SR_register(GIE);
	while(1);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer(void)
{
	TACCTL0&=~CCIFG; // clearing the interrupt flag
	P1OUT^=BIT6+BIT0;
}
