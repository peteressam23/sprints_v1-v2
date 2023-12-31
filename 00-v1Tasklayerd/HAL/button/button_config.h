/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef BUTTON_CONFIG_H_ 
#define BUTTON_CONFIG_H_

/********************************************************************************/
/*                                Includes                                      */
/********************************************************************************/
#include "gpio_interface.h" 

/********************************************************************************/
/*                                Number of Buttons                             */
/********************************************************************************/
typedef enum __buttonNumber_t 
{
	BUTTON_0  = 1 ,
	BUTTON_1      ,
	BUTTON_MAX
}enu_buttonNumber_t;


/********************************************************************************/
/*                                Button Configuration                          */
/********************************************************************************/
typedef struct __buttonConfig_t
{
	str_MGPIO_configuration_t 	 str_MGPIO_ButtonConfiguration;
	enu_buttonNumber_t           buttonNumber;
}str_buttonConfiguration_t;

/********************************************************************************/
/*                                Number Of Buttons                             */
/********************************************************************************/
#define Number_OF_BUTTONS      2
 




#endif