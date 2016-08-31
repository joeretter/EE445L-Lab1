//main.c
//Joe Retter, jmr5823
//Brad Gray, bg22946
//Lab 1
//31 Aug 2016

#include <stdint.h>
#include <stdio.h>
#include "ST7735.h"
#include "PLL.h"
#include "tm4c123gh6pm.h"
#include "fixed.h"

int main(void) {
	int32_t a[1] = {0};
	int32_t b[1] = {0};
	
	int32_t k[7] = {15, 20, 25, 30, 25, 20, 15};
	int32_t q[7] = {15, 20, 25, 30, 35, 40, 45};
	PLL_Init(Bus80MHz);                  // set system clock to 80 MHz
	ST7735_InitR(INITR_REDTAB);

	//ST7735_sDecOut3(8912);
	//ST7735_sDecOut3(890980);
	//ST7735_sDecOut3(-2);
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
	
//	ST7735_XYplotInit("part3", 0, 127, 159, 32);
//	ST7735_XYplot(7, k, q);
}
