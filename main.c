//main.c
//Joe Retter, jmr5823
//Brad Gray, bg22946
//Initial Creation Date: 29 Aug 2016
//Descritpion: Test file to demo the functionality of fixed.c
//Lab 1
//TA: Mahesh
//Date of Last Revision: 1 Sep 2016


#include <stdint.h>
#include <stdio.h>
#include "ST7735.h"
#include "PLL.h"
#include "tm4c123gh6pm.h"
#include "fixed.h"

int main(void) {
		
	int32_t x[12] = {30, 35, 40, 45, 40, 35, 30, 25, 20, 15, 20, 25};
	int32_t y[12] = {10, 15, 20, 25, 30, 35, 40, 35, 30, 25, 20, 15};
	int32_t x2[12] = {60, 65, 70, 75, 70, 65, 60, 55, 50, 45, 50, 55};
	int32_t y2[12] = {40, 45, 50, 55, 60, 65, 70, 65, 60, 55, 50, 45};
	PLL_Init(Bus80MHz);    // set system clock to 80 MHz
	ST7735_InitR(INITR_REDTAB);

	ST7735_sDecOut3(-100000);
	ST7735_sDecOut3(-10000);
	ST7735_sDecOut3(-9999);
	ST7735_sDecOut3(-999);
	ST7735_sDecOut3(-1);
	ST7735_sDecOut3(-0);
	ST7735_sDecOut3(123);
	ST7735_sDecOut3(1234);
	ST7735_sDecOut3(9999);
	ST7735_sDecOut3(10000);
/*
	ST7735_uBinOut8(-64);
	ST7735_uBinOut8(0);
	ST7735_uBinOut8(2);
  ST7735_uBinOut8(64);
	ST7735_uBinOut8(100);
	ST7735_uBinOut8(500);
	ST7735_uBinOut8(512);
	ST7735_uBinOut8(5000);
	ST7735_uBinOut8(30000);
	ST7735_uBinOut8(255997);
	ST7735_uBinOut8(256000);
	*/
//	ST7735_XYplotInit("part3", 0, 127, 32, 159);
//	ST7735_XYplot(12, x, y);
//	ST7735_XYplot(12, x2, y2);
}
