#include<msp430g2553.h>
float value=0,mV=0,TempC=0;
void main(void)
{

	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	//PWM Initialization

	P1DIR|=BIT2; // P1.2--PWM pin
	P1SEL|=BIT2; // P1.2--PWM pin

	CCR0 = 1023; // Pull Period
	TA0CCTL1 = OUTMOD_7; // CCR1 reset/set
	TA0CTL = TASSEL_2 + MC_1; // SMCLK, UP-Mode

	//ADC Initialization


//	ADC10CTL0|= ADC10ON+ADC10IE+ADC10SHT_2; // Turn ON ADC + Enable ADC Interrupt + ADC Sample n Hold time

//	ADC10CTL1|= INCH_1+ADC10SSEL_3; // Select PIN 1 as i/p channel and SM_CLK as the source

//	ADC10AE0|= BIT1; // Analog i/p from channel 1


	ADC10CTL1 = INCH_3 + ADC10DIV_3; // Channel 3, ADC
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10AE0 |= BIT3; // ADC i/p enable


	while(1)
	{
		ADC10CTL0|= ENC + ADC10SC; // Enable Conversion n start conversion
		__bis_SR_register(GIE);
		__no_operation();

		value = ADC10MEM;
		mV = ((value/1023)*3300);
		TempC = mV/10;

	}
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC(void)
{
	TA0CCR1=ADC10MEM;

}

