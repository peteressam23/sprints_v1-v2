/********************************************************************************/
/*                              HEADER GUARD                                    */
/********************************************************************************/
#ifndef GPT_INTERFACE_H_
#define GPT_INTERFACE_H_

/********************************************************************************/
/*                                  INCLUDES                                    */
/********************************************************************************/
#include "common.h"
#include "gpio_interface.h"


/********************************************************************************/
/*                              POINTERTO FUNC CALL BACK                        */
/********************************************************************************/
typedef void(*ptrf_callBack_t)(void);


/********************************************************************************/
/*                                      SELECT TIMER                            */
/********************************************************************************/
typedef enum __MTIMER_timerSelect_t
{
	M_TIMER0_SELECT         = 0,
  M_TIMER1_SELECT            ,
  M_TIMER2_SELECT            ,
  M_TIMER3_SELECT	           ,
	M_TIMER4_SELECT            ,
	M_TIMER5_SELECT            ,
	M_WIDE_TIMER0_SELECT       ,
	M_WIDE_TIMER1_SELECT       ,
	M_WIDE_TIMER2_SELECT       ,
	M_WIDE_TIMER3_SELECT       ,
	M_WIDE_TIMER4_SELECT       ,
	M_WIDE_TIMER5_SELECT       ,
	M_INVALID_TIMER_SELECT      
}enu_MTIMER_timerSelect_t;

/********************************************************************************/
/*                                      SELECT MODE                             */
/********************************************************************************/
typedef enum __MTIMER_mode_t
{
	MTIMER_ONE_SHOT_MODE         = 0,
  MTIMER_PERIODIC_MODE            ,
  MTIMER_RTC_MODE                 ,
  MTIMER_INPUT_EDGE_COUNT_MODE	   ,
	MTIMER_INPUT_EDGE_TIME_MODE	   ,
	MTIMER_PWM_MODE                 ,
	MTIMER_INVALID_MODE
}enu_MTIMER_mode_t;

/********************************************************************************/
/*                                       SELECT TYPE                            */
/********************************************************************************/
typedef enum __MTIMER_type_t
{
	MTIMER_INDIVIDUAL_TYPE         = 0,
  MTIMER_CONCATENATED_TYPE          ,
	MTIMER_INVALID_TYPE
}enu_MTIMER_type_t;

/********************************************************************************/
/*                      TIMER STRUCTURE TO CONFIGURE                            */
/********************************************************************************/
typedef struct 
{
	enu_MTIMER_timerSelect_t          enu_timerSelect;
	enu_MTIMER_mode_t                 enu_timerMode;
	enu_MTIMER_type_t                 enu_timerType;
	boolean                           bool_interruptuOk;
	ptrf_callBack_t                   ptrf_callBack;    
}str_MTIMER_configurations_t;


/********************************************************************************/
/*                                 SELECT TIMER UNIT                            */
/********************************************************************************/
typedef enum __TIME_unit_t
{
	TIME_IN_MICROSECONDS  = 0 ,
	TIME_IN_MILLIOSECONDS     ,
	TIME_IN_SECONDS           ,
	TIME_UNIT_INVALID
}enu_timeUnit_t;


/********************************************************************************/
/*                              ERROR STATE OF TIMER                            */
/********************************************************************************/
typedef enum __MTIMER_status_t
{
	MTIMER_OKAY      = 0           ,
	MTIMER_SELECT_ERROR      ,
	MTIMER_MODE_SELECT_ERROR       ,
	MTIMER_TYPE_SELECT_ERROR       ,
	MTIMER_NULL_REF_ERROR          ,
	MTIMER_INVALID_OPERATION_ERROR ,
	MTIMER_NULL_REF_CB_ERROR       ,
	MTIMER_INVALID_UNIT_ERROR
}enu_MTIMER_status_t;


/********************************************************************************/
/*                               PROTOTYPES                                     */
/********************************************************************************/
/**
*@berif      : initialies specific timer 
*@param[in]  : pointer to str_MTIMER_configurations_t type with desired option 

     
*@return     : MTIMER_OKAY                      success initialization
							 MTIMER_NULL_REF_ERROR            Null pointer argument 
							 MTIMER_TIMER_SELECT_ERROR        Invalid timer number  
							 MTIMER_MODE_SELECT_ERROR         Invalid mode select   
							 MTIMER_TYPE_SELECT_ERROR         Invalid type select   
							 MTIMER_INVALID_OPERATION_ERROR   reinitialization error
*/
enu_MTIMER_status_t M_timerInit               (str_MTIMER_configurations_t *ptr_timerConfigurations);


/**
*@berif      : start timer 

*@param[in]  :  - enu_MTIMER_timerSelect_t     
								- uint32_desired_time        
								- enu_timeUnit_t              
     
*@return     : MTIMER_OKAY                     
							 MTIMER_TIMER_SELECT_ERROR       
							 MTIMER_INVALID_UNIT_ERROR       
					  	 MTIMER_INVALID_OPERATION_ERROR   
*/
enu_MTIMER_status_t M_timerStart       (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t u32_arg_desiredTime , enu_timeUnit_t enu_arg_timeUnit);


/**
*@berif         :  enable interrupt for specific timer
*@param[in]     :  enu_MTIMER_timerSelect_t       
								
*@return        : MTIMER_OKAY                      
							    MTIMER_TIMER_SELECT_ERROR        
							    MTIMER_INVALID_OPERATION_ERROR   
*/
enu_MTIMER_status_t M_timerEnableInterrupt   (enu_MTIMER_timerSelect_t enu_arg_timerSelect);


/**
*@berif         :  disable interrupt for specific timer
*@param[in]     :  enu_MTIMER_timerSelect_t      
								
*@return        : MTIMER_OKAY                    
							    MTIMER_TIMER_SELECT_ERROR        
							    MTIMER_INVALID_OPERATION_ERROR   
*/
enu_MTIMER_status_t M_timerDisableInterrupt  (enu_MTIMER_timerSelect_t enu_arg_timerSelect);


/**
*@berif         : get elapsed time for specific timer
*@param[in]     : enu_MTIMER_timerSelect_t      
								
*@param[in/out] : - *u32_ptr_timeMs                :store the elapsed value

*@return        : MTIMER_OKAY                      (In case of success initialization)
							    MTIMER_TIMER_SELECT_ERROR        (In case of Invalid timer number  )
							    MTIMER_INVALID_OPERATION_ERROR   (In case of uninitialized timer   )
*/
enu_MTIMER_status_t M_Timer_getElapsedTime   (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_timeMs);


/**
*@berif         : get remaining time 
*@param[in]     : enu_MTIMER_timerSelect_t       
								
*@param[out]    : *u32_ptr_timeMs            
*@return        : MTIMER_OKAY                      
							    MTIMER_TIMER_SELECT_ERROR        
							    MTIMER_INVALID_OPERATION_ERROR   
*/
enu_MTIMER_status_t M_TIMER_getRemainingTime (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint32_t *u32_ptr_timeMs);



/**
*@berif         : function stop timer
*@param[in]     : enu_MTIMER_timerSelect_t      
								
*@return        : MTIMER_OKAY                      
							    MTIMER_TIMER_SELECT_ERROR        
							    MTIMER_INVALID_OPERATION_ERROR  
*/
enu_MTIMER_status_t M_stopTimer         (enu_MTIMER_timerSelect_t enu_arg_timerSelect);


/**
*@berif         :set pwm with desired duty cycle
*@param[in]     : enu_MTIMER_timerSelect_t      
                  u16_arg_durationMs 
                  u8_dutyCycle         
								
*@return        : MTIMER_OKAY                      
							    MTIMER_TIMER_SELECT_ERROR        
							    MTIMER_INVALID_OPERATION_ERROR   
*/
enu_MTIMER_status_t M_TIMER_set_pwm            (enu_MTIMER_timerSelect_t enu_arg_timerSelect , uint16_t u16_arg_durationMs , uint8_t u8_arg_dutyCycle);

#endif
