/*Avinash Aryal 1001727418*/
#include "DiceLib.h"
void RollDice(int diceArray[])
{
    
    /* Fill the diceArray with random no form 1 to 6 */
	int i;
    srand(time(0));
    for(i=0; i<noDice;i++)
    {
        diceArray[i]= (rand()%facesPerDice)+1;
    }
    /* ----------------------------------------------*/
	
}

void PrintRoll(int diceArray[])
{
	/* Print the number that is rolled in the dice */
	int i;
    for(i=0; i<noDice;i++)
    {
        printf("%d ", diceArray[i]);
    }
    printf("\n");
    /* ----------------------------------------------*/
	
}

void numberofCombination(int howMany[],int diceArray[])
{
	/* Counts how many of each faces is found on the dice*/
	int i,j;
	int counter=0;
    for(i=1;i<=facesPerDice; i++)   // initilize for loop s.t. its loops through each faces
    {
        for(j=0;j<noDice;j++)       //initilize for loop s.t. its loops through each dice
        {
            if(i==diceArray[j])    // if faces of dice is equal to the dices roll increase counter
            {
                counter++;
            }
        }
        howMany[i-1]= counter;     // set howmany array index i-1 to countr
        counter=0;				   // set counter to zero
    }
    /* ---------------------------------------------------*/
}
void combination(char result[],int howMany[])
{	int i;
	int twoPair=0;
    int fullHouse=0;
    int ofAKind=0;
    int smallStraight=0;
    int largeStraight=0;
    int cSlam=0;
	
    for(i=0;i<facesPerDice;i++)
    {
        if(howMany[i]==3)
        {
            fullHouse+=3; // if howMany int array has no 3 increase the variable fullHouse variable by 3
        }
        if(howMany[i]==2)
        {
            fullHouse+=2;
            twoPair++;   // if howMany int array has no 2 increase the variable fullHouse by 2 and twoPair by 1
        }
        if(howMany[i]==5)
        {
          cSlam++;  // if howMany int array has no 5 increase cSlam by 1
        }
        if(howMany[i]==1)
        {
            largeStraight++;  // if howMany int array has no 1 increase largeStraight by 1
        }
        else if(howMany[i]==0 && largeStraight>0 && largeStraight<5)
        {
            largeStraight=0;  // if howMany int array has no 0 and largeStraight>0 && largeStraight<5 set largeStraight to 0
        }
        if(howMany[i]>=1)
        {
            smallStraight++; // if howMany int array has no >1 increase the value by 1
        }
        else if(howMany[i]==0 && smallStraight>0 && smallStraight<4)
        {
            smallStraight=0; // if howMany int array has no=0 and smallStraight>0 && smallStraight<4 set samllStraignt to 0
        }
        if(howMany[i]==4)
        {
            ofAKind=4;  // if howMany int array has no 4 set ofAKind to 4
        }
        if(howMany[i]==3)
        {
            ofAKind=3;  // if howMany int array has no 3 set ofAKind to 3
        }
    }
    /*------------------------------------------------------*/


    /* Check each variable that we set while looping howmany array and check each condition */
    if(largeStraight==5)
    {
        strcpy(result,"Large Straight");
		
	 
    }
    else if(smallStraight>=4)
    {
        strcpy(result,"Small Straight");
		
    }
    else if(fullHouse==5)
    {
        strcpy(result,"Full house");
		
    }
    else if(cSlam ==1)
    {
        strcpy(result,"cSlam!!");
		
    }
    else if(ofAKind==4)
    {
         strcpy(result,"Four-of-a-Kind");
		 
    }
    else if( ofAKind==3)
    {
        strcpy(result, "Three-of-a-Kind");
		
    }
    else if( twoPair==2)
    {
        strcpy(result,"Two pair");
		
    }
    else
    {
        strcpy(result, "You have nothing");
		
    }
	
}






