#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

uint8_t LED_D1 = 0;
uint8_t LED_D4 = 0;

uint32_t frequencia = 24000000;


//void SysTick_Handler(void){
  //LED_D1 ^= GPIO_PIN_1; // Troca estado do LED D1
  //GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, LED_D1); // Acende ou apaga LED D1
  
  //LED_D4 ^= GPIO_PIN_0; // Troca estado do LED D4
  //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4); // Acende ou apaga LED D4
  
  //tempo ++;
  
//} // SysTick_Handler

void main(void){
  
  uint32_t loop = 2000; // ? dividido por 3 pois uma itera??o no loop s?o 3 instru??es em assembly
  
  SysTickPeriodSet(frequencia); // f = 1Hz para clock = 24MHz
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION); // Habilita GPIO N (LED D1 = PN1, LED D2 = PN0, LED D3 = PF4, LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)); // Aguarda final da habilita??o
  
  GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1); // LEDs D1 e D2 como sa?da
  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, 0); // LEDs D1 e D2 apagados
  GPIOPadConfigSet(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilita??o
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // LEDs D3 e D4 como sa?da
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0); // LEDs D3 e D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ); // Habilita GPIO J (push-button SW1 = PJ0, push-button SW2 = PJ1)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)); // Aguarda final da habilita??o
    
  GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1); // push-buttons SW1 e SW2 como entrada
  GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

  //SysTickIntEnable();
  //SysTickEnable();

  while(1){    
    
    
    uint32_t i, j;
    for(i=0; i<loop; i++)
    {
      for(j=0; j<loop; j++)
      {
        if(i == j)
        {
          continue;
        }
      }
    }
    
    LED_D4 ^= GPIO_PIN_0; // Troca estado do LED D4
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4); // Acende ou apaga LED D4
    
    
    //if(GPIOPinRead(GPIO_PORTJ_BASE, GPIO_PIN_0) == GPIO_PIN_0) // Testa estado do push-button SW1
    //  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0); // Apaga LED D3
    //else
    //  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_PIN_4); // Acende LED D3
    //int i, a=0;
    //for(i=0; i<loop; i++)
    //{
    //  a += i;
    //}
    //if(tempo == (frequencia/loop))
    //{
    //LED_D4 ^= GPIO_PIN_0; // Troca estado do LED D4
    //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4); // Acende ou apaga LED D4
    //}
 
    
  } // while
} // main
