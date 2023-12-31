/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

/********************************************************************************/
/*                               INCLUDES                                       */
/********************************************************************************/
#include "gpio_interface.h"

/********************************************************************************/
/*                                  LED COLORS                                  */
/********************************************************************************/
typedef enum  __ledCOLOR
{
    RED_LED   = 0,
    BLUE_LED     ,
    GREEN_LED    ,
    TOTAL_LEDS
}enu_ledCOLOR_t;
 
/********************************************************************************/
/*                                  LED CONFIG                                  */
/********************************************************************************/
typedef struct __ledConfiguration
{
	str_MGPIO_configuration_t 	   str_MGPIO_ButtonConfiguration;
	enu_ledCOLOR_t                 enu_ledColor;
}str_ledConfiguration_t;

/********************************************************************************/
/*                              NUMBER OF LEDS                                  */
/********************************************************************************/
#define NUMBER_OF_LEDS     3




#endif /*LED_CONFIG_H_*/
