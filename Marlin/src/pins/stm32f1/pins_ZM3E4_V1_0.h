/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


// =====================NOTE=====================
// #define TONE_TIMER		1
// #define TONE_CHANNEL		2
// Please redefine the TONE_TIMER and TONE_CHANNEL in 
// .platformio\packages\framework-arduinoststm32-maple\STM32F1\cores\maple\tone.cpp
// line 31 and line 34
// =====================NOTE=====================


#pragma once
#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif
#define BOARD_INFO_NAME "ZONESTAR ZM3E4 V1.0"

//#define DISABLE_DEBUG
#define DISABLE_JTAG

#define FLASH_EEPROM_EMULATION
#define EEPROM_PAGE_SIZE     (0x800) // 2KB
#define	MARLIN_EEPROM_SIZE		(EEPROM_PAGE_SIZE*2)
#define EEPROM_START_ADDRESS uint32(0x8000000 + (STM32_FLASH_SIZE) * 1024 - MARLIN_EEPROM_SIZE)
#define E2END                (EEPROM_PAGE_SIZE - 1)

//=============================================================================
// ZONESTAR ZM3E4 V1.0 (STM32F130RCT6) board pin assignments
//=============================================================================
//	PA0					//	PB0		HEAT_1			//	PC0	   		AXU_SDA			  
//	PA1     		    //	PB1     FAN1            //	PC1         TEMP_E1               
//	PA2	    HEAT_BED	//	PB2	    BOOT1           //	PC2	        TEMP_E0           
//	PA3	    PWR_HOLD    //	PB3	    SPI3_SCK        //	PC3	        TEMP_BED
//	PA4     SD_CS		//	PB4     SPI3_MISO       //	PC4         SD_DETECT
//	PA5     SD_SCK      //	PB5     SPI3_MOSI       //	PC5         HEAT_0
//	PA6     SD_MISO 	//	PB6     SERVO3          //	PC6         E1_STEP
//	PA7     SD_MOSI     //	PB7     SERVO2          //	PC7         E1_EN
//	PA8     X_DIR      	//	PB8     FAN2/SERVO1     //	PC8         FIL_RUNOUT_PIN
//	PA9     UART1_RX   	//	PB9     SERVO0          //	PC9         E0_DIR
//	PA10    UART1_TX   	//	PB10    TX3             //	PC10        E0_EN
//	PA11    USB_D-      //	PB11    RX3             //	PC11        Z2_EN
//	PA12    USB_D+      //	PB12    LED          	//	PC12        Z2_STEP
//	PA13    SWD_SDO     //	PB13    Z1_MAX          //	PC13        X_MIN
//	PA14    SWD_SCK     //	PB14    Y_MAX           //	PC14        WIFI_RST
//	PA15    SPI3_CS     //	PB15    PWR_DET         //	PC15        WIFI_CS

//	PD0	 	Z2_DIR		//	PE0		Y_EN
//	PD1     Z2_MIN		//	PE1		Y_STEP
//	PD2	    Z1_EN		//	PE2		Y_DIR
//	PD3	    Z1_STEP		//	PE3		Y_MIN
//	PD4	    Z1_DIR		//	PE4		X_DIR
//	PD5	    WIFI_RXD	//	PE5		X_STEP
//	PD6	    WIFI_TXD	//	PE6		X_EN
//	PD7	    Z1_MIN		//	PE7		AXU_SCL
//	PD8	    X_MAX		//	PE8		BTN_EN1
//	PD9	    E3_DIR		//	PE9		LCD_SCK
//	PD10    E3_STEP		//	PE10	LCD_MOSI
//	PD11    E3_EN		//	PE11	BEEPER
//	PD12    E2_DIR		//	PE12	LCD_EN
//	PD13    E2_STEP		//	PE13	KILL
//	PD14    E2_EN		//	PE14	BTN_EN2
//	PD15    E1_DIR		//	PE15	BTN_ENC
//=============================================================================

//EXP1 connector																
//	   MARK     I/O     ZONESTAR_LCD12864		REPRAPDISCOUNT_LCD12864				
//	10 RS		PE13   	KILL					BTN_ENC										
//	9  BP		PE11		BEEP					BEEP										
//	8  EN		PE12		DOGLCD_CS				LCDRS								
//	7  MOSI	PE10 		DOGLCD_SCK				LCDE								
//	6  EN1	PE8    	BTN_EN1					NC								
//	5  SCK	PE9   	DOGLCD_MOSI				LCD4
//	4  ENC 	PE15   	BTN_ENC					NC								
//	3  EN2  PE14		BTN_EN2					NC								
//	2  +5V										+5V								
//	1  GND										GND								


//EXP2 connector								
//	   MARK     I/O     ZONESTAR_LCD12864       REPRAPDISCOUNT_LCD12864
//	10	 										
//	9	  
//	8	RX0  	PA9		UART1_RX				
//	7	TX0  	PA10	UART1_TX				BTN_EN2
//	6	CS3	 	PA15
//	5	MISO3  	PB4								BTN_EN1
//	4	MOSI3  	PB5								KILL
//	3	SCK3  	PB3								
//	2	+5V										+5V
//	1	GND										GND


//AUX1 connector
//	1	+5V 	    	
//	2	GND
//	3	RX3  		PB11	UART3_RX
//	4	TX3  		PB10	UART3_TX
//	5	SCL  		PE7		
//	6	SDA  		PC0		

//WiFi
//	1	+5V 	    	
//	2	GND
//	3	WIFI_TXD  	PD5		UART2_RX
//	4	WIFI_RXD  	PD6		UART2_TX
//	5	WIFI_RST  	PC14		
//	6	WIFI_CS  	PC15		
//=============================================================================

//
// Limit Switches
//
#ifdef USE_XMIN_PLUG
#define X_STOP_PIN         PC13
#endif

#ifdef USE_YMIN_PLUG
#define Y_STOP_PIN         PE3
#endif

#ifdef USE_ZMIN_PLUG
#define Z_MIN_PIN          PD7
#endif

#ifdef USE_XMAX_PLUG
#define X_MAX_PIN          PD8
#endif

#ifdef USE_YMAX_PLUG
#define Y_MAX_PIN          PB14
#endif

#ifdef USE_ZMAX_PLUG
#define Z_MAX_PIN          PB13
#endif

//
// Steppers
//
#ifdef COREXY
#define X_ENABLE_PIN       PE0
#define X_STEP_PIN         PE1
#define X_DIR_PIN          PE2

#define Y_ENABLE_PIN       PE6
#define Y_STEP_PIN         PE5
#define Y_DIR_PIN          PE4
#else
#define X_ENABLE_PIN       PE6
#define X_STEP_PIN         PE5
#define X_DIR_PIN          PE4

#define Y_ENABLE_PIN       PE0
#define Y_STEP_PIN         PE1
#define Y_DIR_PIN          PE2
#endif

#define Z_ENABLE_PIN       PD2
#define Z_STEP_PIN         PD3
#define Z_DIR_PIN          PD4

#ifdef OPTION_DUALZ_DRIVE
#define Z2_ENABLE_PIN      PC11
#define Z2_STEP_PIN        PC12
#define Z2_DIR_PIN         PD0
#endif

#ifdef OPTION_Z2_ENDSTOP
#define Z2_MIN_PIN		  PD1	//Z2_MIN_PIN
#endif

//#define Z2_MAX_PIN         PB12

#ifdef	SWITCH_EXTRUDER_SQUENCY
#define E3_ENABLE_PIN      PC10
#define E3_STEP_PIN        PA8
#define E3_DIR_PIN         PC9

#define E2_STEP_PIN        PC6
#define E2_DIR_PIN         PD15
#define E2_ENABLE_PIN      PC7

#define E1_STEP_PIN        PD13
#define E1_DIR_PIN         PD12
#define E1_ENABLE_PIN      PD14

#define E0_STEP_PIN        PD10
#define E0_DIR_PIN         PD9
#define E0_ENABLE_PIN      PD11
#else
#define E0_ENABLE_PIN      PC10
#define E0_STEP_PIN        PA8
#define E0_DIR_PIN         PC9

#define E1_STEP_PIN        PC6
#define E1_DIR_PIN         PD15
#define E1_ENABLE_PIN      PC7

#define E2_STEP_PIN        PD13
#define E2_DIR_PIN         PD12
#define E2_ENABLE_PIN      PD14

#define E3_STEP_PIN        PD10
#define E3_DIR_PIN         PD9
#define E3_ENABLE_PIN      PD11
#endif
//
// Temperature Sensors
//
#define TEMP_0_PIN         PC2   // TH0
#define TEMP_1_PIN         PC1   // TH1
#define TEMP_BED_PIN       PC3   // TB1

//
// Heaters
//
#define HEATER_0_PIN       PC5   // HEATER0
#define HEATER_1_PIN       PB0   // HEATER1
#define HEATER_BED_PIN     PA2   // HOT BED

#if ENABLED(OPTION_CHAMBER)
#undef TEMP_1_PIN
#undef HEATER_1_PIN
#define TEMP_CHAMBER_PIN	PC1
#define HEATER_CHAMBER_PIN	PB0
#endif
//
// Fans
//
#define FAN_PIN            PB1   // FAN1
#define FAN1_PIN           PB8   // FAN2

//
// Misc. Functions
//
//#define POWER_LOSS_PIN     PB15   //
#define LED_PIN            PA0
#define SUICIDE_PIN        PA3
#define FIL_RUNOUT_PIN	   PC8

#define ENABLE_SPI1
#define SD_DETECT_PIN      PC4
#define SCK_PIN            PA5
#define MISO_PIN           PA6
#define MOSI_PIN           PA7
#define SS_PIN             PA4

//WiFi. Functions
#define WIFI_RST          	PC15
#define WIFI_EN          	PC14

#if ENABLED(OPTION_REPEAT_PRINTING)
#define FPRWARD_PIN         PA13    
#define BACK_PIN          	PA14
#endif

#if ENABLED(ZONESTAR_12864LCD)
#define	LCDSCREEN_NAME		"ZONESTAR LCD12864"

#define LCD_PINS_RS 			PE12		//7 CS make sure for zonestar zm3e4!
#define LCD_PINS_ENABLE 	PE9			//6 DATA make sure for zonestar zm3e4!
#define LCD_PINS_D4 			PE10    //8 SCK make sure for zonestar zm3e4!
#define BEEPER_PIN        PE11
#define KILL_PIN          	-1//PE13
#define BTN_EN1 					PE8
#define BTN_EN2 					PE14
#define BTN_ENC 					PE15
#endif

#if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define	LCDSCREEN_NAME		"REPRAPDISCOUNT LCD12864"
#define LCD_PINS_RS 			PE12	//7 CS make sure for zonestar zm3e4!
#define LCD_PINS_ENABLE 	PE10	//6 DATA make sure for zonestar zm3e4!
#define LCD_PINS_D4 			PE9    	//8 SCK make sure for zonestar zm3e4!
#define LCD_PINS_D5 			-1    	//mosi
#define LCD_PINS_D6 			-1      
#define LCD_PINS_D7 			-1
#define LCD_RESET_PIN     -1

#define BEEPER_PIN    		PE11
#define KILL_PIN      		PB5
#define BTN_EN1 					PB4
#define BTN_EN2 					PA10
#define BTN_ENC 					PE13

#define DOGLCD_A0           -1
#define DOGLCD_CS           -1
#define DOGLCD_MOSI         -1
#define DOGLCD_SCK          -1
#endif

#if ENABLED(ZONESTAR_LCD2004_KNOB)
#define	LCDSCREEN_NAME	"LCD2004 KNOB"
#define LCD_PINS_RS         PE12    
#define LCD_PINS_ENABLE     PE10    
#define LCD_PINS_D4         PE9    
#define LCD_PINS_D5         PE14    
#define LCD_PINS_D6         PE8    
#define LCD_PINS_D7         PE15

#define BTN_EN1 			PA10
#define BTN_EN2 			PB4
#define BTN_ENC 			PE13
#define BEEPER_PIN 			PE11
#define KILL_PIN 			PB5
#endif


#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define	LCDSCREEN_NAME	"LCD2004 5KEY"
#define LCD_PINS_RS         PE12    
#define LCD_PINS_ENABLE     PE10    
#define LCD_PINS_D4         PE9    
#define LCD_PINS_D5         PE14    
#define LCD_PINS_D6         PE8    
#define LCD_PINS_D7         PE15 

#define ADC_KEYPAD_PIN		PE13//PC0			//PIN6 of AUX1
#endif
#if ENABLED(ZONESTAR_DWIN_LCD)
//Connect to EXP2 connector
#define	LCDSCREEN_NAME		"ZONESTAR DWIN LCD"

#define BEEPER_PIN          PA15    //PE11
#define KILL_PIN          	-1		//PE13
#define BTN_EN1 			PB3    	//PE14
#define BTN_EN2 			PB5    	//PE8
#define BTN_ENC 			PB4   	//PE15
#endif

#if HAS_MARLINUI_U8GLIB
#define BOARD_ST7920_DELAY_1 DELAY_NS(200)    //Tclk_fall <200ns
#define BOARD_ST7920_DELAY_2 DELAY_NS(250)    //Tdata_width >200ns
#define BOARD_ST7920_DELAY_3 DELAY_NS(200)    //Tclk_rise <200ns
#endif

//SERVO
//Remap SERVO0 PIN for BLTouch
#if ENABLED(BLTOUCH_ON_EXP1)
//BLTouch connect to EXP1
#define	BLTOUCH_PROBE_PIN 		PE8
#define BLTOUCH_GND_PIN		  	PE15
#define	SERVO0_PIN		  			PE14
#elif ENABLED(BLTOUCH_ON_EXP2)
//BLTouch connect to EXP2
#define	BLTOUCH_PROBE_PIN 		PB3
#define BLTOUCH_GND_PIN		  	PB5
#define	SERVO0_PIN		  			PA15
#else
#define	SERVO0_PIN		  			PB9	
#define	BLTOUCH_PROBE_PIN 		PB13
#endif

#define	SERVO2_PIN		  PB7
#define	SERVO3_PIN		  PB6


