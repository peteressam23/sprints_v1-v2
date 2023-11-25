/********************************************************************************/
/*                                Includes                                      */
/********************************************************************************/
#include "button_config.h" 

/********************************************************************************/
/*                              Config Buttons by struct                        */
/********************************************************************************/
const str_buttonConfiguration_t str_g_buttonConfig[Number_OF_BUTTONS] =
{
	{
	  {
		    /*Button 0 */
      	.enu_portNumber          = PORTF ,
       	.enu_pinNumber           = PIN4 , 
	      .enu_pinDirection        = INPUT_PIN_DIRECTION , 
	      .enu_pinMode           	 = DIGITAL_PIN_MODE,
        .enu_pinInternalType     = PULL_UP,
				.enu_pinType					   = MGPIO_PIN
			
	  }
	  , BUTTON_0 
	},
	{
	  {
		   /*Button 1 */
      .enu_portNumber          = PORTF ,
      .enu_pinNumber           = PIN0 , 
	    .enu_pinDirection        = INPUT_PIN_DIRECTION, 
	    .enu_pinMode             = DIGITAL_PIN_MODE,
      .enu_pinInternalType     = PULL_UP,
			.enu_pinType						 = MGPIO_PIN
	  }
	  , BUTTON_1 
	}
};
