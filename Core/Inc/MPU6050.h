/*
 * MPU6050.h
 *
 *  Created on: 31 juil. 2021
 *      Author: oussema_zribi
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stm32g4xx_hal.h"

#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_CONFIG_REG 0x1B
#define GYRO_XOUT_H_REG 0x43

// Setup MPU6050
#define MPU6050_ADDR 0xD0
/* USER CODE BEGIN Private defines */
void MPU6050_Init(void);
void MPU6050_Read_Accel(void);

float Ax;
float Ay;
float Az;
float NewAccel;
float PrevAccel;
float jerk;


#endif /* INC_MPU6050_H_ */
