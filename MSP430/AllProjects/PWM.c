#include<msp430g2553.h>

void main(void)
{

	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	//P1DIR|=BIT3+BIT5;
	//P1OUT&=~(BIT3+BIT5);
	int i;
	P1DIR|=BIT2; // P1.2--PWM pin
	P1SEL|=BIT2; // P1.2--PWM pin

	CCR0 = 1000-1; // Pull Period
	TA0CCTL1 = OUTMOD_7; // CCR1 reset/set
	TA0CTL = TASSEL_2 + MC_1; // SMCLK, UP-Mode

	//P1DIR|=BIT6+BIT0;

	while(1)
	{
		//P1OUT|=BIT3;
		for(i=0;i<1000;i++)
		{
			TA0CCR1=i;
			__delay_cycles(5000);
		}
		for(i=999;i>100;i--)
		{
			TA0CCR1=i;
			__delay_cycles(5000);
		}
	}
}


