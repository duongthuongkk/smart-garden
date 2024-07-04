#include "i2c-sht30.h"

#define SHT30_I2C_ADDRESS 0x44<<1 
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

HAL_StatusTypeDef SHT30_ReadData(SHT30_Data *data) {
    uint8_t command[2] = {0x2C, 0x06};
    uint8_t buffer[6];
    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Master_Transmit(&hi2c1, SHT30_I2C_ADDRESS, command, 2, HAL_MAX_DELAY);
    if (ret != HAL_OK) {
        return ret;
    }
    HAL_Delay(500);

    ret = HAL_I2C_Master_Receive(&hi2c1, SHT30_I2C_ADDRESS, buffer, 6, HAL_MAX_DELAY);
    if (ret != HAL_OK) {
        return ret;
    }

    uint16_t rawTemperature = (buffer[0] << 8) | buffer[1];
    uint16_t rawHumidity = (buffer[3] << 8) | buffer[4];

    data->temperature = -45.0f + 175.0f * ((float)rawTemperature / 65535.0f);
    data->humidity = 100.0f * ((float)rawHumidity / 65535.0f);

    return HAL_OK;
}
