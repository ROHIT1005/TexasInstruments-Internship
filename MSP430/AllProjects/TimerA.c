#include<msp430g2553.h>
#define TASSEL_1 (1*0x100u)     /* Timer A clock source select: 1 - ACLK  */
#define TAIV TA0IV          /* Timer A Interrupt Vector Word */
#define TACTL TA0CTL         /* Timer A Control */
#define TAR TA0R           /* Timer A Counter Register */
#define TACCR0 TA0CCR0        /* Timer A Capture/Compare 0 */


void main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
	P1DIR|=BIT0;
	TACCR0|=32767;
	TAIFG
	TACCR0 CCIFG|=
	__bis_SR_register(GIE);
	while(1);
}

#pragma vector=TAIV
__interrupt void myWDT(void)
{
	P1OUT^=BIT0;
}
