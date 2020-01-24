/*
 Testing Module for Coding Assignment 1
 */
#include <string.h>
#include <stdio.h>
void TestRollDice(int dice[])
{
static int testCase = 1;
int CSdice[] = {1,1,1,1,1};
int FHdice1[] = {1,1,2,2,2};
int FHdice2[] = {1,1,1,2,2};
int FHdice3[] = {2,3,2,3,2};
int LSdice1[] = {1,2,3,4,5};
int LSdice2[] = {2,3,4,5,6};
int LSdice3[] = {3,4,1,2,5};
int SSdice1[] = {1,2,3,4,6};
int SSdice2[] = {2,3,4,5,5};
int SSdice3[] = {3,4,5,6,1};
int SSdice4[] = {6,1,2,3,4};
int SSdice5[] = {5,2,3,4,5};
int SSdice6[] = {1,3,4,5,6};
int SSdice7[] = {3,5,1,6,4};
int TwoPair1[] = {1,1,2,2,3};
int TwoPair2[] = {4,5,5,6,6};
int TwoPair3[] = {1,5,2,5,1};
int ThreeKind1[] = {1,1,1,2,3};
int ThreeKind2[] = {1,6,2,6,6};
int ThreeKind3[] = {3,4,2,2,2};
int FourKind1[] = {1,1,1,1,2};
int FourKind2[] = {3,2,2,2,2};
int FourKind3[] = {3,6,3,3,3};
switch(testCase)
{
case 1:
memcpy((void *)dice, CSdice, sizeof(CSdice));
printf("CSlam!");
break;
case 2:
memcpy((void *)dice, FHdice1, sizeof(FHdice1));
printf("Full House");
break;
case 3:
memcpy((void *)dice, FHdice2, sizeof(FHdice2));
printf("Full House");
break;
case 4:
memcpy((void *)dice, FHdice3, sizeof(FHdice3));
printf("Full House");
break;
case 5:
memcpy((void *)dice, LSdice1, sizeof(LSdice1));
printf("Large Straight");
break;
case 6:
memcpy((void *)dice, LSdice2, sizeof(LSdice2)); 
printf("Large Straight");
break;
case 7:
memcpy((void *)dice, LSdice3, sizeof(LSdice3));
printf("Large Straight");
break;
case 8:
memcpy((void *)dice, SSdice1, sizeof(SSdice1));
printf("Small Straight");
break;
case 9:
memcpy((void *)dice, SSdice2, sizeof(SSdice2));
printf("Small Straight");
break;
case 10:
memcpy((void *)dice, SSdice3, sizeof(SSdice3));
printf("Small Straight");
break;
case 11:
memcpy((void *)dice, SSdice4, sizeof(SSdice4));
printf("Small Straight");
break;
case 12:
memcpy((void *)dice, SSdice5, sizeof(SSdice5));
printf("Small Straight");
break;
case 13:
memcpy((void *)dice, SSdice6, sizeof(SSdice6));
printf("Small Straight");
break;
case 14:
memcpy((void *)dice, SSdice7, sizeof(SSdice7));
printf("Small Straight");
break;
case 15:
memcpy((void *)dice, TwoPair1, sizeof(TwoPair1));
printf("Two Pair");
break;
case 16:
memcpy((void *)dice, TwoPair2, sizeof(TwoPair2));
printf("Two Pair");
break;
case 17:
memcpy((void *)dice, TwoPair3, sizeof(TwoPair3));
printf("Two Pair");
break;
case 18:
memcpy((void *)dice, ThreeKind1, sizeof(ThreeKind1));
printf("Three a Kind");
break;
case 19:
memcpy((void *)dice, ThreeKind2, sizeof(ThreeKind2));
printf("Three of a Kind");
break;
case 20:
memcpy((void *)dice, ThreeKind3, sizeof(ThreeKind3));
printf("Three of a Kind");
break;
case 21: 
memcpy((void *)dice, FourKind1, sizeof(FourKind1));
printf("Four of a Kind");
break;
case 22:
memcpy((void *)dice, FourKind2, sizeof(FourKind2));
printf("Four of a Kind");
break;
case 23:
memcpy((void *)dice, FourKind3, sizeof(FourKind3));
printf("Four of a Kind");
break;
}
testCase++;
}
