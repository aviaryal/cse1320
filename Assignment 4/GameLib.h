/*Avinash Aryal 1001727418*/
#ifndef _frog
#define frog

#define Max_Entries 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

typedef struct 
{
	char years[5];
	char *category;
	char *winner;
}
AWARD;

FILE *OpenAwardFile(int argc, char *argv[]);
int FillAwardArray(FILE *AwardFile, AWARD FillAward[]);
int PrintAwardMenu(AWARD awardarray[], int noline);
void GuessIt(AWARD *singleAward);



#endif














