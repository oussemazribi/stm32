/*
 * Accel.c
 *
 *  Created on: 31 juil. 2021
 *      Author: oussema_zribi
 */
#include "Accel.h"
#include <stdio.h>
UART_HandleTypeDef hlpuart1;
UART_HandleTypeDef huart1;

void calcul_jerk(void) {
	MPU6050_Read_Accel();

		if (accelcout == 0) {
			NewAccelAx = Ax;
			NewAccelAx = Ax;
			NewAccelAx = Ax;
			accelcout++;

		} else {
			PrevAccelAx = NewAccelAx;
			PrevAccelAy = NewAccelAy;
			PrevAccelAz = NewAccelAz;
			NewAccelAx = Ax;
			NewAccelAy = Ay;
			NewAccelAz = Az;
			accelcout = 0;
		}

		DeltaAccelAx = (NewAccelAx - PrevAccelAx);
		DeltaAccelAy = (NewAccelAy - PrevAccelAy);
		DeltaAccelAz = (NewAccelAz - PrevAccelAz);

		//sprintf(msg, "Ax: %.2f Ay: %.2f Az: %.2f \r\n", DeltaAccelAx , DeltaAccelAy , DeltaAccelAz);
		//sprintf(msg1, "2: %.2f \r\n", PrevAccel);
		//HAL_UART_Transmit(&hlpuart1, (uint8_t*) msg, sizeof(msg),HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart1, (uint8_t*) msg, sizeof(msg),
		HAL_MAX_DELAY);


}

void detection_freinage(void){
	calcul_jerk();
	DeltaAccel=(DeltaAccelAx+DeltaAccelAy+DeltaAccelAz)/3;
	sprintf(msg, "%.2f \r\n", DeltaAccel);
	//HAL_UART_Transmit(&hlpuart1, (uint8_t*) msg, sizeof(msg),HAL_MAX_DELAY);
	if(DeltaAccel < -1 ){
		sprintf(msg,"FFFF \r\n");
		HAL_UART_Transmit(&hlpuart1, (uint8_t*) msg, sizeof(msg),HAL_MAX_DELAY);
	}
}
