#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include"stm32f4xx.h"
//#include"stm32f4xx_hal_i2c.h"

#define I2C_TO 80 // Timeout de la comunicación I2C

//extern I2C_HandleTypeDef hi2c1;
extern uint8_t buff[20];


void I2C_Read(uint16_t i2c_add, uint16_t mem_add, uint16_t size);
void I2C_Write(uint16_t i2c_add, uint16_t mem_add, uint16_t size);