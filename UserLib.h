Edit this line

/***************************************************************************//*!
*
* @file     UserLib.h
*
* @author
*
* @version
*
* @date
*
* @brief    Header file for UserLib.
*
******************************************************************************/
#ifndef USERLIB_H_
#define USERLIB_H_

#include "CLASS_Typedefs.h"
#include "CLASS_Defines.h"

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
#define USERLIB_RAMP_DEFAULT	{0.0, 0.0, 0.0}

#define USERLIB_HYST_DEFAULT	{0.0, 0.0, 0.0, 0.0, 0.0}

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/
typedef struct
{
	float32_t	f32State;
	float32_t	f32Increment;
	float32_t	f32Decrement;
} UserLib_Ramp_t;

typedef struct
{
	float32_t	f32HystOn;
	float32_t	f32HystOff;
	float32_t	f32OutOn;
	float32_t	f32OutOff;
	float32_t	f32OutState;
} UserLib_Hyst_t;

/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/


/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/
float32_t UserLib_Ramp(float32_t f32In, UserLib_Ramp_t *pParam);
float32_t UserLib_Hyst(float32_t f32In, UserLib_Hyst_t *pParam);

#endif /* USERLIB_H_ */
