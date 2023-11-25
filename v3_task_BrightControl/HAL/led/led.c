/********************************************************************************/
/*                               INCLUDES                                       */
/********************************************************************************/
#include "led_interface.h"
#include "gpio_interface.h"

/********************************************************************************/
/*                               IMPLEMENTATION                                 */
/********************************************************************************/

enu_ledErrorState_t H_LED_init(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin)
{
	  enu_MGPIO_errorStatus_t enu_MGPIO_l_errorState = GPIO_OK;
    enu_ledErrorState_t enu_l_errorState = LED_OK;
    /*check led port and pin numbers*/
    if(enu_l_ledPort < INVALID_PORT && enu_l_ledPin < INVALID_PIN )
    {
        str_MGPIO_configuration_t str_MGPIO_ButtonConfig;
        /*configure LED struct*/
        str_MGPIO_ButtonConfig.enu_portNumber        = enu_l_ledPort;
        str_MGPIO_ButtonConfig.enu_pinNumber         = enu_l_ledPin;
        str_MGPIO_ButtonConfig.enu_pinOutCurrent     = PIN_CURRENT_8MA;
        str_MGPIO_ButtonConfig.enu_pinInternalType   = PULL_UP;
        str_MGPIO_ButtonConfig.enu_pinDirection 	 	 = OUTPUT_PIN_DIRECTION;
        str_MGPIO_ButtonConfig.enu_pinValue				   = PIN_LOW_VALUE;
        str_MGPIO_ButtonConfig.enu_pinMode 			     = DIGITAL_PIN_MODE;

        /*check that initialization of GPIO is ok*/
        enu_MGPIO_l_errorState = MGPIO_init(&str_MGPIO_ButtonConfig);

        if(enu_MGPIO_l_errorState == GPIO_OK)
        {
            enu_l_errorState = LED_OK;
        }
        else
        {
            enu_l_errorState = LED_NOT_OK;
        }
    }
    else
    {
        enu_l_errorState = LED_NOT_OK;
    }
    return enu_l_errorState;
}

/*****************************************************************************************************/

enu_ledErrorState_t H_LED_on(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin)
{
	  enu_MGPIO_errorStatus_t enu_MGPIO_l_errorState = GPIO_OK;
    enu_ledErrorState_t enu_l_errorState = LED_OK;
   /*check led port and pin numbers*/
    if (enu_l_ledPort < INVALID_PORT && enu_l_ledPin < INVALID_PIN)
    {
        /*check that write pin of GPIO is ok*/
        enu_MGPIO_l_errorState = MGPIO_write(enu_l_ledPort , enu_l_ledPin , PIN_HIGH_VALUE);
        if (enu_MGPIO_l_errorState == GPIO_OK)
        {
            enu_l_errorState = LED_OK;
        }
        else
        {
            enu_l_errorState = LED_NOT_OK;
        }
    }
    else
    {
        enu_l_errorState = LED_NOT_OK;
    }

    return enu_l_errorState;
}

/*****************************************************************************************************/

enu_ledErrorState_t H_LED_off(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin)
{
	  enu_MGPIO_errorStatus_t enu_MGPIO_l_errorState = GPIO_OK;
    enu_ledErrorState_t enu_l_errorState = LED_OK;
   /*check led port and pin numbers*/
    if (enu_l_ledPort < INVALID_PORT && enu_l_ledPin < INVALID_PIN)
    {
        /*check that write pin of GPIO is ok*/
        enu_MGPIO_l_errorState = MGPIO_write(enu_l_ledPort, enu_l_ledPin , PIN_LOW_VALUE);
        if (enu_MGPIO_l_errorState == GPIO_OK)
        {
            enu_l_errorState = LED_OK;
        }
        else
        {
            enu_l_errorState = LED_NOT_OK;
        }
    }
    else
    {
        enu_l_errorState = LED_NOT_OK;
    }

    return enu_l_errorState;
}

/*****************************************************************************************************/

enu_ledErrorState_t H_LED_toggle(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin)
{
	  enu_MGPIO_errorStatus_t enu_MGPIO_l_errorState = GPIO_OK;
    enu_ledErrorState_t enu_l_errorState = LED_OK;
   /*check led port and pin numbers*/
    if (enu_l_ledPort < INVALID_PORT && enu_l_ledPin < INVALID_PIN)
    {
         /*check that Toggle pin of GPIO is ok*/
        enu_MGPIO_l_errorState = MGPIO_toggle(enu_l_ledPort, enu_l_ledPin);
        // Check if GPIO toggle operation was successful
        if (enu_MGPIO_l_errorState == GPIO_OK)
        {
            enu_l_errorState = LED_OK;
        }
        else
        {
            enu_l_errorState = LED_NOT_OK;
        }
    }
    else
    {
        enu_l_errorState = LED_NOT_OK;
    }
    return enu_l_errorState;
}
