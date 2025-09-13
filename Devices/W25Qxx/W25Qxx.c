/*
 * W25Qxx.c
 *
 *  Created on: Sep 10, 2025
 *      Author: kunal
 */

#include "W25Qxx.h"

SPI_Config W25QX;

#define NSS_Port GPIOA
#define NSS_Pin  4

static void NSS_Low(void)
{
	GPIO_Pin_Low(NSS_Port, NSS_Pin);
}

static void NSS_High(void)
{
	GPIO_Pin_High(NSS_Port, NSS_Pin);
}


struct Status_Register
{

	int HOLD_RST;
	int DRV1;
	int DRV0;
	int RES4;
	int RES3;
	int WPS;
	int RES2;
	int RES1;
	int SUS;
	int CMP ;
	int LB3 ;
	int LB2 ;
	int LB1 ;
	int RES0;
	int QE ;
	int SRP1 ;
	int SRP0 ;
	int SEC ;
	int TB ;
	int	BP2 ;
	int BP1 ;
	int BP0 ;
	int WEL ;
	int BUSY;

}Status_Register;

struct Status_Register SR;

static void Read_Status_Register(void)
{
	int x[3];
	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0x05);
	x[0] = SPI_TRX_Byte(&W25QX, 0xAA);
	x[1] = SPI_TRX_Byte(&W25QX, 0xAA);
	x[2] = SPI_TRX_Byte(&W25QX, 0xAA);
	NSS_High();



	SR. SRP0 = ((1 << 7) & x[0]) >> 7;
	SR. SEC = ((1 << 6) & x[0]) >> 6;
	SR. TB = ((1 << 5) & x[0]) >> 5;
	SR.	BP2 = ((1 << 4) & x[0]) >> 4;
	SR. BP1 = ((1 << 3) & x[0]) >> 3;
	SR. BP0 = ((1 << 2) & x[0]) >> 2;
	SR. WEL = ((1 << 1) & x[0]) >> 1;
	SR. BUSY= ((1 << 0) & x[0]) >> 0;

	SR.SUS  = ((1 << 7) & x[1]) >> 7;
	SR.CMP  = ((1 << 6) & x[1]) >> 6;
	SR.LB3  = ((1 << 5) & x[1]) >> 5;
	SR.LB2  = ((1 << 4) & x[1]) >> 4;
	SR.LB1  = ((1 << 3) & x[1]) >> 3;
	SR.QE   = ((1 << 1) & x[1]) >> 1;
	SR.SRP1  = ((1 << 0) & x[1]) >> 0;
	//
	SR.HOLD_RST  = ((1 << 7) & x[2]) >> 7;
	SR.DRV1  = ((1 << 6) & x[2]) >> 6;
	SR.DRV0  = ((1 << 5) & x[2]) >> 5;
	SR.WPS  = ((1 << 2) & x[2]) >> 2;
}

static int Write_Enable()
{
	int retval;
	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0x06);
	NSS_High();

	Read_Status_Register();
	if(SR.WEL)
	{
		retval = 1;
	}
	else
	{
		retval = -1;
	}
	return retval;
}

static int Write_Disable()
{
	int retval;
	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0x04);
	NSS_High();
	Read_Status_Register();
	if(SR.WEL)
	{
		retval = -1;
	}
	else
	{
		retval = 1;
	}
	return retval;
}

void W25Qx_Release_Power_Down(void)
{
	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0xAB);
	NSS_High();
}

void W25QX_Init(W25Qx_Typedef *self)
{
	SPI_Init(self->SPI_Port);
	W25Qx_Release_Power_Down();
	Delay_us(5);

	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0x9F);
	self->Manufacturer_ID = SPI_TRX_Byte(&W25QX, 0xAA);
	self->Memory_Type = SPI_TRX_Byte(&W25QX, 0xAA);
	self->Capacity = SPI_TRX_Byte(&W25QX, 0xAA);
	NSS_High();


	uint64_t x[8];
	NSS_Low();
	SPI_TRX_Byte(&W25QX, 0x4B);
	SPI_TRX_Byte(&W25QX, 0xAA);
	SPI_TRX_Byte(&W25QX, 0xAA);
	SPI_TRX_Byte(&W25QX, 0xAA);
	SPI_TRX_Byte(&W25QX, 0xAA);

	for(int i = 0 ; i < 8; i++)
	{
		x[i] = SPI_TRX_Byte(&W25QX, 0xAA);
	}
	self->Unique_ID = (x[0] << 56) | (x[1] << 48) | (x[2] << 40) | (x[3] << 32) | (x[4] << 24) | (x[5] << 16) |
			(x[6] << 8) | (x[7] << 0);
	NSS_High();

	if(self->Memory_Type == 0x13)	//W25Q80
	{
		self->Last_Address = 0x0FFFFF;
	}
	if(self->Memory_Type == 64)	//W25Q16
	{
		self->Last_Address = 0x1FFFFF;
	}
	if(self->Memory_Type == 0x15)	//W25Q32
	{
		self->Last_Address = 0x3FFFFF;
	}
}


int W25Qx_Read_Byte(uint32_t address)
{
	int32_t LA = (int32_t)address;
	int read = 0;
	NSS_Low(W25QX);
	SPI_TRX_Data(W25QX, 0x03);
	SPI_TRX_Data(W25QX, (0xFF0000 & LA) >> 16);
	SPI_TRX_Data(W25QX, (0x00FF00 & LA) >> 8);
	SPI_TRX_Data(W25QX, (0x0000FF & LA) >> 0);
	read = SPI_TRX_Data(W25QX, 0xAA);
	SPI_CSS_High(W25QX);
	return read;
}
