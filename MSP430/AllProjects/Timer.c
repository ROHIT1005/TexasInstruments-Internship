#include<msp430g2553.h>
void main(void)
{
	WDTCTL=WDT_ADLY_1000;
	//WDTCTL=WDT_MDLY_32;
	P1DIR|=BIT0;
	IE1|=WDTIE;
	__bis_SR_register(GIE);
	while(1);
}

#pragma vector=WDT_VECTOR
__interrupt void myWDT(void)
{
	P1OUT^=BIT0;
}
