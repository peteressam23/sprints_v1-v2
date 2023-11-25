/********************************************************************************/
/*                                 INCLUDES                                     */
/********************************************************************************/
#include "led_config.h"

/********************************************************************************/
/*                                 Config Leds by struct                        */
/********************************************************************************/
const str_ledConfiguration_t str_ledConfiguration[NUMBER_OF_LEDS] =
{
	{
	  {
      .enu_portNumber     = PORTF ,
      .enu_pinNumber      = PIN1 , 
	    .enu_pinDirection   = OUTPUT_PIN_DIRECTION, 
	    .enu_pinMode        = DIGITAL_PIN_MODE,
	    .enu_pinValue       = PIN_LOW_VALUE ,           
	    .enu_pinOutCurrent  = PIN_CURRENT_2MA,
			.enu_pinType			  = MGPIO_PIN
	  }
	  , RED_LED 
	},
	{
	  {
      .enu_portNumber        = PORTF ,
      .enu_pinNumber         = PIN2 , 
	    .enu_pinDirection      = OUTPUT_PIN_DIRECTION, 
	    .enu_pinMode           = DIGITAL_PIN_MODE,
	    .enu_pinValue          = PIN_LOW_VALUE ,           
	    .enu_pinOutCurrent     = PIN_CURRENT_2MA,
      .enu_pinType					 = MGPIO_PIN			
	  }
	  , BLUE_LED 
	},
	{
	  {
      .enu_portNumber    = PORTF ,
      .enu_pinNumber     = PIN3 , 
	    .enu_pinDirection  = OUTPUT_PIN_DIRECTION , 
	    .enu_pinMode       = DIGITAL_PIN_MODE,
	    .enu_pinValue      = PIN_LOW_VALUE ,           
	    .enu_pinOutCurrent = PIN_CURRENT_2MA,
			.enu_pinType			 = MGPIO_PIN
	  }
	  , GREEN_LED
	}
};
