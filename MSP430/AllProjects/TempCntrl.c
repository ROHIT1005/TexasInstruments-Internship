#include<msp430g2553.h>

float value=0,mV=0,TempC=0;

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop WDT
	ADC10CTL1 = INCH_3 + ADC10DIV_3; // Channel 3, ADC
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON;
	ADC10AE0 |= BIT3; // ADC i/p enable


	while(1)
	{
		__delay_cycles(1000); // Waiting for ADC ref
		ADC10CTL0 |= ENC + ADC10SC; // Sampling
		value = ADC10MEM;
		mV = ((value/1023)*3300);
		TempC = mV/10;

	}
}
