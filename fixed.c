//Joe Retter, jmr5823
//Brad Gray, bg22946
//EE 445L MW 5-630PM
//Lab 1

#include <stdint.h>
#include <stdio.h>
#include "ST7735.h" //added prototype for fputc on last line of this header

#define MAX_PARAM 9999
#define MIN_PARAM -9999

void ST7735_sDecOut3(int32_t x) {
	int32_t ones = 0, tenths = 0, hundredths = 0, thousandths = 0;
	int32_t ones_ascii = 0, tenths_ascii = 0, hundredths_ascii = 0, thousandths_ascii = 0;
	int32_t temp_val;
	FILE *fp;
	int32_t sign = 0x20; //ascii for space
	int32_t decimal = 0x2E; //ascii for decimal
	int32_t star = 0x2A; //ascii for *
	char str[7];
	
	if(x < 0){
		sign = 0x2D;
		x = - x;
	}
	
	if(x > MIN_PARAM && x < MAX_PARAM) {
		temp_val = x / 10;
		thousandths = x % 10;
		hundredths = temp_val % 10;
		temp_val = temp_val / 10;
		tenths = temp_val % 10;
		temp_val = temp_val / 10;
		ones = temp_val % 10;
		
		ones_ascii = ones + 0x30;
		tenths_ascii = tenths + 0x30;
		hundredths_ascii = hundredths + 0x30;
		thousandths_ascii = thousandths + 0x30;
		//printf("%c%d%c%d%d%d\n", sign, ones, decimal, tenths, hundredths, thousandths);
		//fputc(str, fp); // using dummy file pointer
		fputc(sign, fp);
		fputc(ones_ascii, fp);
		fputc(decimal, fp);
		fputc(tenths_ascii, fp);
		fputc(hundredths_ascii, fp);
		fputc(thousandths_ascii, fp);
	}else {
		fputc(star, fp);
		fputc(decimal, fp);
		fputc(star, fp);
		fputc(star, fp);
		fputc(star, fp);
		//printf(" *.***\n");
	}
	
}