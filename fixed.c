//fixed.c
//Joe Retter, jmr5823
//Brad Gray, bg22946
//Initial Creation Date: 29 Aug 2016
//Descritpion: Contains definitions for functions that print fixed
//point numbers and plot points of the ST7735 LCD screen
//Lab 1
//TA: Mahesh
//Date of Last Revision: 1 Sep 2016


#include <stdint.h>
#include <stdio.h>
#include "ST7735.h" //added prototype for fputc on last line of this header

#define MAX_PARAM_PART1 9999
#define MIN_PARAM_PART1 -9999
#define MAX_PARAM_PART2 256000
#define SPACE 0x20
#define NEWLINE 0x0A
#define DECIMAL 0x2E
#define STAR 0x2A
#define ASCII_CONV 0x30;
#define NEGATIVE 0x2D;

int minX, minY, maxX, maxY; //global for drawing on LCD within set bounds

/*
 * Converts fixed point number to LCD
 * Format signed 32-bit with resolution 0.001
 * Range -9.999 to +9.999
 * If the given int is within range, divide out into separate placeholder values
 * by dividing by 10, convert to ASCII, and write data to LCD
 * If out of range, display **.***
 */
void ST7735_sDecOut3(int32_t x) {
	int32_t ones = 0, tenths = 0, hundredths = 0, thousandths = 0;
	int32_t ones_ascii = 0, tenths_ascii = 0, hundredths_ascii = 0, thousandths_ascii = 0;
	int32_t temp_val;			
	FILE *fp; 						//not used, but fputc call required a file pointer parameter
	int32_t sign = SPACE; //if positive, just want a space instead of '+'
	
	if(x < 0){
		sign = NEGATIVE; 
		x = - x; 						//the sign is set appropriately; deal with abs value for ease
	}
	
	if(x >= MIN_PARAM_PART1 && x <= MAX_PARAM_PART1) {
		
		temp_val = x / 10;
		thousandths = x % 10;
		hundredths = temp_val % 10;
		temp_val = temp_val / 10;
		tenths = temp_val % 10;
		temp_val = temp_val / 10;
		ones = temp_val % 10;
		
		//Get ASCII values as needed
		ones_ascii = ones + ASCII_CONV;
		tenths_ascii = tenths + ASCII_CONV;
		hundredths_ascii = hundredths + ASCII_CONV;
		thousandths_ascii = thousandths + ASCII_CONV;
		
		//write everything to LCD
		fputc(sign, fp);
		fputc(ones_ascii, fp);
		fputc(DECIMAL, fp);
		fputc(tenths_ascii, fp);
		fputc(hundredths_ascii, fp);
		fputc(thousandths_ascii, fp);
		fputc(NEWLINE, fp);
	}else { 						
		fputc(SPACE, fp);
		fputc(STAR, fp);
		fputc(DECIMAL, fp);
		fputc(STAR, fp);
		fputc(STAR, fp);
		fputc(STAR, fp);
		fputc(NEWLINE, fp);
	}
	
}

/*
 * Converts binary fixed-point to LCD 
 * unsigned 32-bit binary fixed-point with a resolution of 1/256. 
 * The full-scale range is from 0 to 999.99. 
 * If the integer part is larger than 256000, it signifies an error. 
 * 1/256 ~ 0.0039
 * For left of decimal, right shift to divide by resolution (256)
 * For fraction, multiply by conversion (39), then divide by base 10 as needed
 * to separate placeholders
 * If outside bounds, print ***.**
 */
void ST7735_uBinOut8(uint32_t x) {
	int whole, fraction, round, ones, tens, hundreds;
	int tenths, tenths_ascii, hundredths, hundredths_ascii;
	int ones_ascii, tens_ascii, hundreds_ascii;
	int resolution = 256; //resolution = 1/256 * 100
	int conversion = 39; // (1/256)  * 100
	FILE *fp;
	
	if(x < MAX_PARAM_PART2){		
		//getting numbers right of decimal
		whole = x >> 8;
		hundreds = whole / 100;
		whole = whole - (hundreds * 100);
		tens = whole / 10;
		whole = whole - (tens * 10);
		ones = whole;
	
		//getting numbers left of decimal
		fraction = (x % resolution) * conversion;
		round = fraction % 100;
		fraction = fraction / 100;
		if (round > 49) {
			fraction++;
		}
		hundredths = fraction % 10;
		tenths = fraction / 10;
		
		//convert all to ASCII
		ones_ascii = ones + ASCII_CONV;
		tens_ascii = tens + ASCII_CONV;
		hundreds_ascii = hundreds + ASCII_CONV;
		hundredths_ascii = hundredths + ASCII_CONV;
		tenths_ascii = tenths + ASCII_CONV;
		
		if (hundreds == 0){
			hundreds_ascii = SPACE;
			if (tens == 0) {
				tens_ascii = SPACE;
			}
		}
	
		//'print' to LCD
		fputc(hundreds_ascii, fp);
		fputc(tens_ascii, fp);
		fputc(ones_ascii, fp);
		fputc(DECIMAL, fp);
		fputc(tenths_ascii, fp);
		fputc(hundredths_ascii, fp);
		fputc(NEWLINE, fp);
	}else {
		fputc(STAR, fp);
		fputc(STAR, fp);
		fputc(STAR, fp);
		fputc(DECIMAL, fp);
		fputc(STAR, fp);
		fputc(STAR, fp);
		fputc(NEWLINE, fp);
	}
}

/*
 * Sets the X and Y axes for an x-y scatter plot, storing in global variables
 * Clears the LCD from any previous work, printing title at top of LCD
 * assumes minX < maxX, and miny < maxY
 * mins and maxes are in LCD coordinates, not cartesian
 */
void ST7735_XYplotInit(char *title, int32_t min_x, int32_t max_x, int32_t min_y, int32_t max_y){
	ST7735_InitR(INITR_REDTAB);
	ST7735_OutString("       ");
  ST7735_OutString(title);
  ST7735_PlotClear(0,4095);
  minX = min_x;
  maxX = max_x;
	minY = min_y;
	maxY = max_y;
	}

/*
 * Plots an array of (x,y) data with given buf arrays
 * neglect any points outside the minX maxY minY maxY bounds
 * converts given cartesian coordinates into LCD coordinates, displaying
 * if within the set min & max global variables 
 */
void ST7735_XYplot(uint32_t num, int32_t *buf_x, int32_t *buf_y){
		uint32_t k;
	  int32_t x, y;
		
		for(k = 0; k < num; k++){
				if(buf_x[k] >= minX && buf_x[k] < maxX && (maxY - buf_y[k] >= minY) && (maxY - buf_y[k] < maxY)){
						x = buf_x[k];
						y = maxY - buf_y[k];
						ST7735_DrawPixel(x, y, ST7735_BLUE);
				}
		}	
}
