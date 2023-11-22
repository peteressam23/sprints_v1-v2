/********************************************************************************/
/*                                Includes                                      */
/********************************************************************************/
#include "button_interface.h"

/********************************************************************************/
/*                                Extern Array OF Struct                        */
/********************************************************************************/
extern const str_buttonConfiguration_t str_g_buttonConfig[Number_OF_BUTTONS];

/********************************************************************************/
/*                                 IMPLEMENTATION                               */
/********************************************************************************/
enu_buttonErrorStatus_t H_BUTTON_init(void) 
{
    /*make variable to store error state*/
    enu_buttonErrorStatus_t enu_l_errorState = BUTTON_OK;
	 /*Couter for Loop*/
    uint8_t uint8_l_iterate = 0;
    for(uint8_l_iterate = 0 ; uint8_l_iterate < Number_OF_BUTTONS ; uint8_l_iterate++)
   	{
        /*Check pin direction of the button not input*/
        if(str_g_buttonConfig[uint8_l_iterate].str_MGPIO_ButtonConfiguration.enu_pinDirection != INPUT_PIN_DIRECTION) 
				{
            enu_l_errorState = BUTTON_NOT_OK;
            break;
        } 
				else 
					{
            /*Initialize the button*/
            enu_l_errorState = (enu_buttonErrorStatus_t) MGPIO_init(&str_g_buttonConfig[uint8_l_iterate].str_MGPIO_ButtonConfiguration);
            if(enu_l_errorState != BUTTON_OK) 
						{
                enu_l_errorState = BUTTON_NOT_OK;
                break;
            } 
			      else 
		      	{
                
            }
        }
    }
    return enu_l_errorState;
}

/*****************************************************************************************************/

enu_buttonErrorStatus_t H_BUTTON_read(enu_buttonNumber_t enu_a_button_Number , boolean *ptr_a_value)
{
   /*make variable to store error state*/
    enu_buttonErrorStatus_t enu_l_errorState = BUTTON_OK;
    uint8_t uint8_l_iterate = 0;
    for(uint8_l_iterate = 0; uint8_l_iterate < Number_OF_BUTTONS; uint8_l_iterate++)
   	{
        /*Check if direction of  button is not input*/ 
        if(str_g_buttonConfig[uint8_l_iterate].str_MGPIO_ButtonConfiguration.enu_pinDirection != INPUT_PIN_DIRECTION) 
				{
            enu_l_errorState = BUTTON_NOT_OK;
            break;
        } 
				else 
				{
            if(str_g_buttonConfig[uint8_l_iterate].buttonNumber == enu_a_button_Number )
						{
                  /*Get the state of the button */
                    enu_l_errorState = (enu_buttonErrorStatus_t) MGPIO_read(
                    str_g_buttonConfig[uint8_l_iterate].str_MGPIO_ButtonConfiguration.enu_portNumber,
                    str_g_buttonConfig[uint8_l_iterate].str_MGPIO_ButtonConfiguration.enu_pinNumber,
                    ptr_a_value
                );
                break;
             } 
			       else 
		      	{
         
            }
            if(enu_l_errorState != BUTTON_OK) 
						{
                enu_l_errorState = BUTTON_NOT_OK;
                break;
            } 
		      	else 
		      	{
               
            }
        }
    }
    return enu_l_errorState;
}
