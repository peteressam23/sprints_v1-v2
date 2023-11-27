/********************************************************************************/
/*                                      INCLUDES                                */
/********************************************************************************/
#include "gpt_config.h"
#include "gpt_interface.h'

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
