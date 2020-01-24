#ifndef _Draw_Tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define maxSize 20

void mapInitilization(char maxArray[][maxSize], int *size);
void mapPrint(char maxArray[][maxSize], int userSize);
void drawLine(char maxArray[][maxSize],int row, int col, char action, int noSpot, char bg);
void instruction();




#endif


