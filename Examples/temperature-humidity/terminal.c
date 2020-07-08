#include <stdio.h>
#include <stdint.h>

void asciiCursorXY(uint8_t x, uint8_t y)
{
  printf("\x1B[%hu;%huH",y,x);
}

void printCharXY(uint8_t x, uint8_t y, char ch)
{
  asciiCursorXY(x,y);
  printf("%c",ch);
}
