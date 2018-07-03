#include <msp430g2553.h>

#define LCD_DIR P1DIR
#define LCD_OUT P1OUT

#define LCD_RS BIT0
#define LCD_EN BIT1

#define LCD_D7 BIT7
#define LCD_D6 BIT6
#define LCD_D5 BIT5
#define LCD_D4 BIT4

#define LCD_MASK ((LCD_RS|LCD_EN|LCD_D7|LCD_D6|LCD_D5|LCD_D4))

#define TRUE 1
#define FALSE 0



long temp;
long IntDegF;
long IntDegC=0,CurDegC=0,PreDegC=0;



void LCD_PUSH()
{
	LCD_OUT&=~LCD_EN; //ENABLE LOW
	__delay_cycles(100);

	LCD_OUT|=LCD_EN; //ENABLE HIGH
	__delay_cycles(100);

	LCD_OUT&=~LCD_EN; //ENABLE LOW
	__delay_cycles(100);
}

void SEND(char data, int type) // one argument is data n other is command
{
	LCD_OUT&=~LCD_MASK; // make all the pins LOW
	LCD_OUT|=(data&0xF0); // sending the upper bit of the data to the LCD

	if (type==TRUE)
	{
		LCD_OUT|=LCD_RS;
	}
	else
	{
		LCD_OUT&=~LCD_RS;
	}

	LCD_PUSH();

	LCD_OUT&=~LCD_MASK; // make all the pins LOW
	LCD_OUT|=((data&0x0F)<<4); // sending the lower bit of the data to the LCD

	if (type==TRUE)
		{
			LCD_OUT|=LCD_RS;
		}
		else
		{
			LCD_OUT&=~LCD_RS;
		}

		LCD_PUSH();
}

void LCD_INIT()
{
	LCD_DIR|=LCD_MASK;
	LCD_OUT&=~LCD_MASK;
	__delay_cycles(100000);

	LCD_OUT=0x20; //LCD in 4-bit mode
	LCD_PUSH();

	SEND(0x28,FALSE); //4-bit mode
	SEND(0x0E,FALSE);
	SEND(0x06,FALSE);
}

void LCD_CLEAR()
{
	SEND(0x01,FALSE); //clear LCD screen
	SEND(0x02,FALSE);
}

void PRINT(char *text)
{
	char *c;
	c=text;
	while((c!=0)&&(*c!=0)) // check both address n data is not 0
	{
		SEND(*c,TRUE); // send the data to the display
		c++;
	}

}

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    LCD_INIT();
    LCD_CLEAR();
    PRINT(" ROHIT");
    while(1)
    {
    	__delay_cycles(1000);
    }

}




