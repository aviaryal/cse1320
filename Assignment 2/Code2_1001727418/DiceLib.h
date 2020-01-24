/* Avinash Aryal 1001727418*/
#ifndef _DiceLib_
#define _DiceLib_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define noDice 5
#define facesPerDice  6

void RollDice(int diceArray[]);
void PrintRoll(int diceArray[]);
void numberofCombination(int howMany[],int diceArray[]);
void combination(char result[],int howMany[]);


#endif



