/*
 * Copyright (c) 2015 South Silicon Valley Microelectronics Inc.
 * Copyright (c) 2015 iComm Corporation
 *
 * This program is free software: you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation, either version 3 of the License, or 
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ssv6200_reg.h"
#define BANK_COUNT 49
static const u32 BASE_BANK_SSV6200[] = {
	SYS_REG_BASE,
	WBOOT_REG_BASE,
	TU0_US_REG_BASE,
	TU1_US_REG_BASE,
	TU2_US_REG_BASE,
	TU3_US_REG_BASE,
	TM0_MS_REG_BASE,
	TM1_MS_REG_BASE,
	TM2_MS_REG_BASE,
	TM3_MS_REG_BASE,
	MCU_WDT_REG_BASE,
	SYS_WDT_REG_BASE,
	GPIO_REG_BASE,
	SD_REG_BASE,
	SPI_REG_BASE,
	CSR_I2C_MST_BASE,
	UART_REG_BASE,
	DAT_UART_REG_BASE,
	INT_REG_BASE,
	DBG_SPI_REG_BASE,
	FLASH_SPI_REG_BASE,
	DMA_REG_BASE,
	CSR_PMU_BASE,
	CSR_RTC_BASE,
	RTC_RAM_BASE,
	D2_DMA_REG_BASE,
	HCI_REG_BASE,
	CO_REG_BASE,
	EFS_REG_BASE,
	SMS4_REG_BASE,
	MRX_REG_BASE,
	AMPDU_REG_BASE,
	MT_REG_CSR_BASE,
	TXQ0_MT_Q_REG_CSR_BASE,
	TXQ1_MT_Q_REG_CSR_BASE,
	TXQ2_MT_Q_REG_CSR_BASE,
	TXQ3_MT_Q_REG_CSR_BASE,
	TXQ4_MT_Q_REG_CSR_BASE,
	HIF_INFO_BASE,
	PHY_RATE_INFO_BASE,
	MAC_GLB_SET_BASE,
	BTCX_REG_BASE,
	MIB_REG_BASE,
	CBR_A_REG_BASE,
	MB_REG_BASE,
	ID_MNG_REG_BASE,
	CSR_PHY_BASE,
	CSR_RF_BASE,
	MMU_REG_BASE,
	0x00000000
};

static const char *STR_BANK_SSV6200[] = {
	"SYS_REG",
	"WBOOT_REG",
	"TU0_US_REG",
	"TU1_US_REG",
	"TU2_US_REG",
	"TU3_US_REG",
	"TM0_MS_REG",
	"TM1_MS_REG",
	"TM2_MS_REG",
	"TM3_MS_REG",
	"MCU_WDT_REG",
	"SYS_WDT_REG",
	"GPIO_REG",
	"SD_REG",
	"SPI_REG",
	"CSR_I2C_MST",
	"UART_REG",
	"DAT_UART_REG",
	"INT_REG",
	"DBG_SPI_REG",
	"FLASH_SPI_REG",
	"DMA_REG",
	"CSR_PMU",
	"CSR_RTC",
	"RTC_RAM",
	"D2_DMA_REG",
	"HCI_REG",
	"CO_REG",
	"EFS_REG",
	"SMS4_REG",
	"MRX_REG",
	"AMPDU_REG",
	"MT_REG_CSR",
	"TXQ0_MT_Q_REG_CSR",
	"TXQ1_MT_Q_REG_CSR",
	"TXQ2_MT_Q_REG_CSR",
	"TXQ3_MT_Q_REG_CSR",
	"TXQ4_MT_Q_REG_CSR",
	"HIF_INFO",
	"PHY_RATE_INFO",
	"MAC_GLB_SET",
	"BTCX_REG",
	"MIB_REG",
	"CBR_A_REG",
	"MB_REG",
	"ID_MNG_REG",
	"CSR_PHY",
	"CSR_RF",
	"MMU_REG",
	""
};

static const u32 SIZE_BANK_SSV6200[] = {
	SYS_REG_BANK_SIZE,
	WBOOT_REG_BANK_SIZE,
	TU0_US_REG_BANK_SIZE,
	TU1_US_REG_BANK_SIZE,
	TU2_US_REG_BANK_SIZE,
	TU3_US_REG_BANK_SIZE,
	TM0_MS_REG_BANK_SIZE,
	TM1_MS_REG_BANK_SIZE,
	TM2_MS_REG_BANK_SIZE,
	TM3_MS_REG_BANK_SIZE,
	MCU_WDT_REG_BANK_SIZE,
	SYS_WDT_REG_BANK_SIZE,
	GPIO_REG_BANK_SIZE,
	SD_REG_BANK_SIZE,
	SPI_REG_BANK_SIZE,
	CSR_I2C_MST_BANK_SIZE,
	UART_REG_BANK_SIZE,
	DAT_UART_REG_BANK_SIZE,
	INT_REG_BANK_SIZE,
	DBG_SPI_REG_BANK_SIZE,
	FLASH_SPI_REG_BANK_SIZE,
	DMA_REG_BANK_SIZE,
	CSR_PMU_BANK_SIZE,
	CSR_RTC_BANK_SIZE,
	RTC_RAM_BANK_SIZE,
	D2_DMA_REG_BANK_SIZE,
	HCI_REG_BANK_SIZE,
	CO_REG_BANK_SIZE,
	EFS_REG_BANK_SIZE,
	SMS4_REG_BANK_SIZE,
	MRX_REG_BANK_SIZE,
	AMPDU_REG_BANK_SIZE,
	MT_REG_CSR_BANK_SIZE,
	TXQ0_MT_Q_REG_CSR_BANK_SIZE,
	TXQ1_MT_Q_REG_CSR_BANK_SIZE,
	TXQ2_MT_Q_REG_CSR_BANK_SIZE,
	TXQ3_MT_Q_REG_CSR_BANK_SIZE,
	TXQ4_MT_Q_REG_CSR_BANK_SIZE,
	HIF_INFO_BANK_SIZE,
	PHY_RATE_INFO_BANK_SIZE,
	MAC_GLB_SET_BANK_SIZE,
	BTCX_REG_BANK_SIZE,
	MIB_REG_BANK_SIZE,
	CBR_A_REG_BANK_SIZE,
	MB_REG_BANK_SIZE,
	ID_MNG_REG_BANK_SIZE,
	CSR_PHY_BANK_SIZE,
	CSR_RF_BANK_SIZE,
	MMU_REG_BANK_SIZE,
	0x00000000
};
