#include<msp430g2553.h>
int value=0;
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	P1DIR|=BIT0;
	P1OUT&=~BIT0;


	ADC10CTL0|= ADC10ON+ADC10IE+ADC10SHT_2; // Turn ON ADC + Enable ADC Interrupt + ADC Sample n Hold time

	ADC10CTL1|= INCH_1+ADC10SSEL_3; // Select PIN 1 as i/p channel and SM_CLK as the source

	ADC10AE0|= BIT1; // Analog i/p from channel 1


	while(1)
	{
		ADC10CTL0|= ENC + ADC10SC; // Enable Conversion n start conversion
		__bis_SR_register(GIE);
		__no_operation();
	}
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC(void)
{
	value=ADC10MEM;


	if(ADC10MEM>=730) // greater than 1.65V | 3.3V corresponds to 1024
	{
		P1OUT|=BIT0; // RED_LED is turned on
	}
	else
	{
		P1OUT&=~BIT0; // RED_LED is off
	}
}
