/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/********************************************************************************/
/*                                  INCLUDES                                    */
/********************************************************************************/
#include "led_config.h"

/********************************************************************************/
/*                                  LED ERROR STATE                             */
/********************************************************************************/
typedef enum __ledErrorState
{
    LED_OK,
    LED_NOT_OK
}enu_ledErrorState_t;

/********************************************************************************/
/*                                  LED PORTS                                   */
/********************************************************************************/
#define  PORT_RED_LED      PORTF
#define  PORT_BLUE_LED     PORTF
#define  PORT_GREEN_LED    PORTF

/********************************************************************************/
/*                                   LED PINS                                   */
/********************************************************************************/
#define  PIN_RED_LED       PIN1
#define  PIN_BLUE_LED      PIN2
#define  PIN_GREEN_LED     PIN3

/********************************************************************************/
/*                                   PROTOTYPES                                 */
/********************************************************************************/
/**
 * @brief Initialize LEDS 
 * @param    enu_l_ledPort  LED connected on its port.
 *           enu_l_ledPin   LED connected on its pin
 * 
 * @return   enu_ledErrorState_t :
 *            - LED_OK 
 *            - LED_NOT_OK 
 */
enu_ledErrorState_t H_LED_init(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin);


/**
 * @brief    Turn on LED.
 * @param    enu_l_ledPort  LED connected on its port.
 *           enu_l_ledPin   LED connected on its pin
 * 
 * @return   enu_ledErrorState_t :
 *            - LED_OK 
 *            - LED_NOT_OK 
 */
enu_ledErrorState_t H_LED_on(enu_MGPIO_portNumber_t enu_l_ledPort , enu_MGPIO_pinNumber_t enu_l_ledPin);


/**
 * @brief Turns off LED.
 * @param    enu_l_ledPort  LED connected on its port.
 *           enu_l_ledPin   LED connected on its pin
 * 
 * @return   enu_ledErrorState_t :
 *            - LED_OK 
 *            - LED_NOT_OK 
 */
enu_ledErrorState_t H_LED_off(enu_MGPIO_portNumber_t enu_l_ledPort, enu_MGPIO_pinNumber_t enu_l_ledPin);


/**
 * @brief Toggles LED.
 * @param    enu_l_ledPort  LED connected on its port.
 *           enu_l_ledPin   LED connected on its pin
 * 
 * @return   enu_ledErrorState_t :
 *            - LED_OK 
 *            - LED_NOT_OK 
 */
enu_ledErrorState_t H_LED_toggle(enu_MGPIO_portNumber_t enu_l_ledPort, enu_MGPIO_pinNumber_t enu_l_ledPin);





















#endif /* LED_INTERFACE_H_ */
