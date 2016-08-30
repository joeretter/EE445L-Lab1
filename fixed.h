//Joe Retter, 
//Brad Gray, bg22946
//EE 445L MW 5-630PM
//Lab 1

void ST7735_sDecOut3(int32_t x); //signed 32-bit decimal fixed-point delta=0.001
void ST7735_uBinOut8(uint32_t y); //unsigned 32-bit binary fixed-point delta=1/256
void ST7735_XYplotInit(); //specify the X and Y axes for an x-y scatter plot
void ST7735_XYplot(); //plot an array of (x,y) data
