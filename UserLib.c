/***************************************************************************//*!
*
* @file     UserLib.c
*
* @author
*
* @version
*
* @date
*
* @brief    Source file containing routines ....
*
******************************************************************************/

/******************************************************************************
| Includes
-----------------------------------------------------------------------------*/
#include "UserLib.h"

#include "CLASS_Typedefs.h"
#include "CLASS_Defines.h"


/******************************************************************************
| External declarations
-----------------------------------------------------------------------------*/

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-exported)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function prototypes           (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-exported)
-----------------------------------------------------------------------------*/

/**************************************************************************//*!

@brief      The function calculates the Increment/decrement ramp

@param[in]    f32In      Input argument representing the desired output value.
@param[out]  *pParam     Pointer to parameters

@return     The function returns f32 value, which represents
            the actual ramp output value

@details

@note       All parameters and states, used by the function, can be reset...
******************************************************************************/

float32_t UserLib_Ramp(float32_t f32In, UserLib_Ramp_t *pParam)
{
	register float32_t	f32_inc;
	register float32_t 	f32_dec;
	register float32_t	f32_state;

	f32_inc = pParam->f32State + pParam->f32Increment;
	f32_dec = pParam->f32State + pParam->f32Decrement;

	f32_state = (pParam->f32State <= f32In) ? f32_inc : f32_dec;

	pParam->f32State = (((f32_state >= f32In) && (pParam->f32State <= f32In)) ||
			 	 	   ((f32_state <= f32In) && (pParam->f32State > f32In))) ?
			 	 		f32In : f32_state;
	return(pParam->f32State);

}

/**************************************************************************//*!

@brief      Hysteresis function

@param[in]   f32In      Input argument
@param[out]  *pParam    Pointer to parameters

@return     The function returns f32 value, which represents
            the actual output value

@details

@note       All parameters and states, used by the function, can be reset...
******************************************************************************/

float32_t UserLib_Hyst(float32_t f32In, UserLib_Hyst_t *pParam)
{
	register float32_t	f32temp;

	f32temp = (f32In < pParam->f32HystOn) ? pParam->f32OutState : pParam->f32OutOn ;

	pParam->f32OutState = (f32In <= pParam->f32HystOff) ? pParam->f32OutOff : f32temp ;

	return(pParam->f32OutState);

}
/* End of file */

