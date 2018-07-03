//  MSP430G2x33/G2x53 Demo - ADC10, Sample A10 Temp and Convert to oC and oF
//
//  Description: A single sample is made on A10 with reference to internal
//  1.5V Vref. Software sets ADC10SC to start sample and conversion - ADC10SC
//  automatically cleared at EOC. ADC10 internal oscillator/4 times sample
//  (64x) and conversion. In Mainloop MSP430 waits in LPM0 to save power until
//  ADC10 conversion complete, ADC10_ISR will force exit from any LPMx in
//  Mainloop on reti. Temperaure in oC stored in IntDegC, oF in IntDegF.
//  Uncalibrated temperature measured from device to device will vary with
//  slope and offset - please see datasheet.
//  ACLK = n/a, MCLK = SMCLK = default DCO ~1.2MHz, ADC10CLK = ADC10OSC/4
//
//                MSP430G2x33/G2x53
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |A10              |
//
//  D. Dang
//  Texas Instruments Inc.
//  December 2010
//   Built with CCS Version 4.2.0 and IAR Embedded Workbench Version: 5.10
//******************************************************************************
#include <msp430.h>

long temp;
long IntDegF;
long IntDegC=0,CurDegC=0,PreDegC=0;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;    // Stop WDT
  P1DIR|=BIT3+BIT4;      //BIT3--EN;BIT2--IN1;BIT5--IN2
  P1OUT&=~(BIT3+BIT4);
  ADC10CTL1 = INCH_10 + ADC10DIV_3;         // Temp Sensor ADC10CLK/4
  ADC10CTL0 = SREF_1 + ADC10SHT_3 + REFON + ADC10ON + ADC10IE;
  __delay_cycles(100000);

  	P1DIR |= 0x04;                            // P1.2--pwm pin
  	P1SEL |= 0x04;                            // P1.2--pwm pin

  	CCR0 = 800;                             // PWM Period
  	CCTL1 = OUTMOD_7;                         // CCR1 reset/set
  	TACTL = TASSEL_2 + MC_1;                  // SMCLK, up mode

  while(1)
   {

    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(GIE);        // LPM0 with interrupts enabled


    // oC = ((A10/1024)*1500mV)-986mV)*1/3.55mV = A10*423/1024 - 278
    temp = ADC10MEM;
    IntDegC = ((temp - 673) * 423) / 1024;
    CurDegC=IntDegC;
    P1OUT|=BIT3;
    P1OUT&=~BIT4;
    if(CurDegC>PreDegC+2)
    {
    	CCR1=(CurDegC+30)*10;
    	PreDegC=CurDegC;

    }
    if(CurDegC<PreDegC-2)
    {
    	CCR1=(CurDegC-15)*20;
    	PreDegC=CurDegC;

    }
   // __delay_cycles(100);


    __no_operation();                       // SET BREAKPOINT HERE
  }
}

// ADC10 interrupt service routine

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR (void)

{
 // __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

