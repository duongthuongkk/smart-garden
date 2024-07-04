#ifndef SHT30_H
#define SHT30_H

#include "stm32f1xx_hal.h"

typedef struct {
    float temperature;
    float humidity;
} SHT30_Data;

HAL_StatusTypeDef SHT30_ReadData(SHT30_Data *data);

#endif // SHT30_H
