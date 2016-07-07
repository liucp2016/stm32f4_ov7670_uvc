
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "ov7670.h"

int OV7670_WriteReg(OV7670_HandleTypeDef *hov, uint8_t regAddr, uint8_t *pData)
{
	if (HAL_I2C_Mem_Write(hov->hi2c, hov->addr, regAddr, I2C_MEMADD_SIZE_8BIT, pData, 1, hov->timeout) == HAL_OK)
	{
		return OV7670_OK;
	}
	else
	{
		return OV7670_ERROR;
	}
}

int OV7670_ReadReg(OV7670_HandleTypeDef *hov, uint8_t regAddr, uint8_t *pData)
{
	if (HAL_I2C_Mem_Read(hov->hi2c, hov->addr, regAddr, I2C_MEMADD_SIZE_8BIT, pData, 1, hov->timeout) == HAL_OK)
	{
		return OV7670_OK;
	}
	else
	{
		return OV7670_ERROR;
	}
}

int OV7670_Reset(OV7670_HandleTypeDef *hov)
{
	uint8_t data = COM7_RESET;
	if (OV7670_WriteReg(hov, REG_COM7, &data) != OV7670_OK)
	{
		return OV7670_ERROR;
	}
	HAL_Delay(100);
	return OV7670_OK;
}
