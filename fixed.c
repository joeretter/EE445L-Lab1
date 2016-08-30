//Joe Retter, 
//Brad Gray, bg22946
//EE 445L MW 5-630PM
//Lab 1

#include <stdint.h>
#include <stdio.h>
#include "ST7735.h" //added prototype for fputc on last line of this header

#define MAX_PARAM 9999
#define MIN_PARAM -9999

void ST7735_sDecOut3(int32_t x) {
	int ones = 0, tenths = 0, hundredths = 0, thousandths = 0;
	int temp_val;
	FILE *fp;
	char sign = ' ';
	char decimal = '.';
	char str[7];
	
	if(x < 0){
		sign = '-';
		x = - x;
	}
	
	if(x > MIN_PARAM && x < MAX_PARAM) {
		temp_val = x / 10;
		thousandths = x % 10;
		hundredths = temp_val % 10;
		temp_val = temp_val / 10;
		tenths = temp_val % 10;
		temp_val = temp_val / 10;
		ones = temp_val / 10;
		printf("%c%d%c%d%d%d\n", sign, ones, decimal, tenths, hundredths, thousandths);
		//fputc(str, fp); // using dummy file pointer
	}else {
		printf(" *.***\n");
	}
	
}