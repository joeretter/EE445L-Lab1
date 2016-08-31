//fixed.h
//Joe Retter, jmr5823
//Brad Gray, bg22946
//Lab 1
//31 Aug 2016


/****************ST7735_sDecOut3***************
 converts fixed point number to LCD
 format signed 32-bit with resolution 0.001
 range -9.999 to +9.999
 Inputs:  signed 32-bit integer part of fixed-point number
 Outputs: none
 send exactly 6 characters to the LCD 
Parameter LCD display
 12345    " *.***"
  2345    " 2.345"  
 -8100    "-8.100"
  -102    "-0.102" 
    31    " 0.031" 
-12345    " *.***"
 */ 
void ST7735_sDecOut3(int32_t x); //signed 32-bit decimal fixed-point delta=0.001

/**************ST7735_uBinOut8***************
 unsigned 32-bit binary fixed-point with a resolution of 1/256. 
 The full-scale range is from 0 to 999.99. 
 If the integer part is larger than 256000, it signifies an error. 
 The ST7735_uBinOut8 function takes an unsigned 32-bit integer part 
 of the binary fixed-point number and outputs the fixed-point value on the LCD
 Inputs:  unsigned 32-bit integer part of binary fixed-point number
 Outputs: none
 send exactly 6 characters to the LCD 
Parameter LCD display
     0	  "  0.00"
     2	  "  0.01"
    64	  "  0.25"
   100	  "  0.39"
   500	  "  1.95"
   512	  "  2.00"
  5000	  " 19.53"
 30000	  "117.19"
255997	  "999.99"
256000	  "***.**"
*/
void ST7735_uBinOut8(uint32_t y); 

/**************ST7735_XYplotInit***************
 Specify the X and Y axes for an x-y scatter plot
 Draw the title and clear the plot area
 Inputs:  title  ASCII string to label the plot, null-termination
          min_x   smallest X data value allowed, resolution= 0.001
          max_x   largest X data value allowed, resolution= 0.001
          min_y   smallest Y data value allowed, resolution= 0.001
          max_y   largest Y data value allowed, resolution= 0.001
 Outputs: none
 assumes minX < maxX, and miny < maxY
*/
void ST7735_XYplotInit(char *title, int32_t min_x, int32_t max_x, int32_t min_y, int32_t max_y); 

/**************ST7735_XYplot***************
 Plot an array of (x,y) data
 Inputs:  num    number of data points in the two arrays
          bufX   array of 32-bit fixed-point data, resolution= 0.001
          bufY   array of 32-bit fixed-point data, resolution= 0.001
 Outputs: none
 assumes ST7735_XYplotInit has been previously called
 neglect any points outside the minX maxY minY maxY bounds
*/	
void ST7735_XYplot(uint32_t num, int32_t *buf_x, int32_t *buf_y); //plot an array of (x,y) data
