/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/SWITCH_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}


void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTA,GPIO_PIN0);
    SWITCH_Init(GPIO_PORTA,GPIO_PIN1);

    while(1)
    {
        u8 switch1 = SWITCH_STATE(GPIO_PORTA, GPIO_PIN0);
        u8 switch2 = SWITCH_STATE(GPIO_PORTA, GPIO_PIN1);

        if(!switch1 && switch2)
        {
            LED_On(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(200);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(200);
        }
        else if(!switch2 && switch1)
        {
            LED_On(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(500);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(500);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
        }
    }
}