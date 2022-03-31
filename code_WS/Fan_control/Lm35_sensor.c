 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Omar Elsehity
 *
 *******************************************************************************/
#include "Lm35_sensor.h"
#include "adc.h"
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void){

uint8 temp = 0;
uint16 adc_value = 0;
/* Read ADC channel where the temperature sensor is connected */
adc_value = ADC_readChannel(SENSOR_CHANNEL);
/* Calculate the temperature from the ADC value*/

temp = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*MAX_VOLT));
return temp;
}
