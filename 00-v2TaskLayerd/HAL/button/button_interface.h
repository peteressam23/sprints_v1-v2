/********************************************************************************/
/*                                HEADER GUARD                                  */
/********************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/********************************************************************************/
/*                                Includes                                      */
/********************************************************************************/
#include "button_config.h"

/********************************************************************************/
/*                                Buttons Error State                           */
/********************************************************************************/
typedef enum __buttonErrorStatus_t 
{
    BUTTON_OK = 0,  
    BUTTON_NOT_OK      
} enu_buttonErrorStatus_t;

/********************************************************************************/
/*                                  ProtoType                                   */
/********************************************************************************/
/**
 * @brief Inite the buttons.f
 * @return enu_buttonErrorStatus_t  
 *            -BUTTON_OK 
 *            -BUTTON_NOT_OK 
 */
enu_buttonErrorStatus_t H_BUTTON_init(void);

/**
 * @brief Reads the state of a button.
 * 
 * @param  enu_buttonNumber_t 
 *         ptr_a_value 
 * 
 * @return enu_buttonErrorStatus_t  
 *            -BUTTON_OK 
 *            -BUTTON_NOT_OK 
 */
enu_buttonErrorStatus_t H_BUTTON_read(enu_buttonNumber_t enu_a_button_Number , boolean *ptr_a_value);

#endif