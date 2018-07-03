#include<stdint.h>
#include<stdbool.h>
#include"inc/hw_memmap.h"
#include"inc/hw_types.h"
#include"driverlib/sysctl.h"
#include"driverlib/debug.h"
#include"driverlib/gpio.h"
#include"driverlib/uart.h"
#include"driverlib/pin_map.h"

void main(void)
{
	SysCtlClockSet(SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN|SYSCTL_USE_PLL|SYSCTL_SYSDIV_5);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(),115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE ));
	UARTCharPut(UART0_BASE, 'E');
	UARTCharPut(UART0_BASE, 'n');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'r');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, 'h');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 't');
	UARTCharPut(UART0_BASE, 'e');
	UARTCharPut(UART0_BASE, 'x');
	UARTCharPut(UART0_BASE, 't');
	while(1)
	{
	if(UARTCharsAvail(UART0_BASE))
		UARTCharPut(UART0_BASE, UARTCharGet(UART0_BASE));
	}

}
