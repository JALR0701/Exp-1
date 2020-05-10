

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"

int main(void){
    //Establece el reloj del microcontrolador
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //Habilita el periferico GPIOF
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //Habilita pines de salida (LEDS R, B, G respectivamente)
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    //Habilita pines de entrada (Boton SW1 del pad)
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    while(1){
        //Condición si lee un cero en el boton SW1
        if (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 0){
            //Pone en cero los pines de Salida (LEDS R, B, G respectivamente)
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0x00);

            //Enciende el LED verde
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            SysCtlDelay(30000000);

            //Enciende y apaga el LED verde de manera intermitente
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            SysCtlDelay(3000000);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(3000000);

            //Enciende el LED verde y rojo para formar amarillo
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
            SysCtlDelay(30000000);

            //Apaga el LED verde para dejar únicamente el LED rojo encendido
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x00);
            SysCtlDelay(30000000);

            //Apaga el LED rojo
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x00);
        }
    }
}
