/*
 * Accel.h
 *
 *  Created on: 31 juil. 2021
 *      Author: oussema_zribi
 */

#ifndef INC_ACCEL_H_
#define INC_ACCEL_H_

#include "MPU6050.h"


void calcul_jerk(void);
void detection_freinage(void);

float Ax;
float Ay;
float Az;
float NewAccelAx;
float NewAccelAy;
float NewAccelAz;
float PrevAccelAx;
float PrevAccelAy;
float PrevAccelAz;
float DeltaAccelAx;
float DeltaAccelAy;
float DeltaAccelAz;
float DeltaAccel;
char msg[50];
//char msg1[10];
int accelcout;


#endif /* INC_ACCEL_H_ */
