/*Avinash Aryal 1001727418*/

#ifndef _Draw_Tool
#define _Draw_Tool
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define maxSize 20

void mapInitilization(char maxArray[][maxSize]);
void mapPrint(char maxArray[][maxSize]);
void drawLine(char maxArray[][maxSize],int row, int col, char action, int noSpot, char bg);
void checkinputcommand(char *drawcommand,char maxArray[maxSize][maxSize], int commandposition);




#endif


