//Joe Retter, jmr5823
//Brad Gray, bg22946
//EE 445L MW 5-630PM
//Lab 1

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

void ST7735_sDecOut3(int32_t x) {
	int32_t ones = 0, tenths = 0, hundredths = 0, thousandths = 0;
	int32_t ones_ascii = 0, tenths_ascii = 0, hundredths_ascii = 0, thousandths_ascii = 0;
	int32_t temp_val;
	FILE *fp;
	int32_t sign = SPACE; //ascii for space
	
	if(x < 0){
		sign = 0x2D; //negative sign
		x = - x;
	}
	
	if(x > MIN_PARAM_PART1 && x < MAX_PARAM_PART1) {
		temp_val = x / 10;
		thousandths = x % 10;
		hundredths = temp_val % 10;
		temp_val = temp_val / 10;
		tenths = temp_val % 10;
		temp_val = temp_val / 10;
		ones = temp_val % 10;
		
		ones_ascii = ones + ASCII_CONV;
		tenths_ascii = tenths + ASCII_CONV;
		hundredths_ascii = hundredths + ASCII_CONV;
		thousandths_ascii = thousandths + ASCII_CONV;

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

void ST7735_uBinOut8(uint32_t x) {
	int whole, fraction, round, ones, tens, hundreds;
	int tenths, tenths_ascii, hundredths, hundredths_ascii;
	int ones_ascii, tens_ascii, hundreds_ascii;
	int resolution = 256; //resolution = 1/256 * 100
	int conversion = 39; // (1/256)  * 100
	FILE *fp;
	int32_t sign = SPACE; //ascii for space
	
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
		
	ones_ascii = ones + ASCII_CONV;
	tens_ascii = tens + ASCII_CONV;
	hundreds_ascii = hundreds + ASCII_CONV;
	hundredths_ascii = hundredths + ASCII_CONV;
	tenths_ascii = tenths + ASCII_CONV;
	
if(x > 0 && x < MAX_PARAM_PART2){	
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
		fputc(STAR, fp);
		fputc(NEWLINE, fp);
	}
}
