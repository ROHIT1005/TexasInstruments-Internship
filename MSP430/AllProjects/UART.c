#include<msp430g2553.h>

void main(void)
{

	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

	P1DIR|=BIT6; // making BIT0 as o/p
	P1OUT&=~BIT6; // passing 3.3V to BIT0


	DCOCTL = 0; // Select lowest DCOx n MODx settings
	BCSCTL1 = CALBC1_1MHZ; // Set DCO
	DCOCTL = CALDCO_1MHZ;

	P1SEL = BIT1 + BIT2; // P1.1 = RXD, P1.2 = TXD
	P1SEL2 = BIT1 + BIT2; // P1.1 = RXD, P1.2 = TXD

	UCA0CTL1 |= UCSSEL_2; // CLK=SMCLK
	UCA0BR0 = 104; // !MHz/9600 = 104.166
	UCA0BR1 = 0x00;
	UCA0MCTL = UCBRS0; // Modulation UCBRx = 1
	UCA0CTL1 &= ~UCSWRST; // Initialize USCI State Machine
	IE2 |= UCA0RXIE; // Enable USCI_A0 Rx Interrupt

	__bis_SR_register(GIE);


}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
	__delay_cycles(1000);
	UCA0TXBUF = UCA0RXBUF;
	// P1OUT^=BIT6;

}


