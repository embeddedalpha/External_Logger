/*
 * W25Qxx.h
 *
 *  Created on: Sep 10, 2025
 *      Author: kunal
 */

#ifndef W25QXX_W25QXX_H_
#define W25QXX_W25QXX_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "DMA/DMA.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"


typedef struct __W25Qxx_Config__{
    SPI_Config   *SPI_Port;                 /*!< SPI peripheral (already clock‑enabled)        */
    GPIO_TypeDef  *cs_port; uint16_t  cs_pin;   /*!< Chip‑select  (active‑low)                    */
    GPIO_TypeDef  *dc_port; uint16_t  dc_pin;   /*!< Data/Command select – 0:Cmd  1:Data          */
    GPIO_TypeDef  *rst_port;uint16_t  rst_pin;  /*!< Hardware reset (active‑low). Optional (NULL) */
    uint8_t Manufacturer_ID;
    uint8_t Memory_Type;
    uint8_t Capacity;
    uint8_t Unique_ID;
    uint32_t Last_Address;
} W25Qx_Typedef;

#endif /* W25QXX_W25QXX_H_ */
