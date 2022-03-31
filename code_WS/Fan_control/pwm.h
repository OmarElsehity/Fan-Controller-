/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: header file for the PWM driver
 *
 * Author: Omar Elsehity
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"

/*enum for pwm mode*/
typedef enum{
	NORMAL,RESERVED,NON_INVERTING,INVERTING
}MODE;

/* enum for clock prescaler*/
typedef enum{
	NO_CLOCK,F_CPU_0,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}PRESCALER;

/* struct to pass as an input argument */
typedef struct{
	MODE mode;
	PRESCALER prescaler;
}PWM_config;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the PWM driver.
 */
void PWM_Timer0_init(PWM_config *config_ptr);
/*
 * Description :
 * Function responsible for generating the required PWM Signal.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
