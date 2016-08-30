#include <stdint.h>
#include <stdio.h>
#include "ST7735.h" //added prototype for fputc on last line of this header

void ST7735_sDecOut3(int32_t x) {
	int sign_character;
	int first_digit;
	int second_digit;
	int third_digit;
	int fourth_digit;
	int running_dividend;
	
	if(x < 0) {
		
		running_dividend = x / 10;
		fourth_digit = x % 10; 
		fputc(fourth_digit, ); //not sure about the file pointer... we don't need it
	}
	
}