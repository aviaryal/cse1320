/* Avinash Aryal 1001727418*/
#include "DiceLib.h"

int main(void)
{
    int  numberOfReRolls=2;     						// Limits the no of re-roll
    int  reRollsCounter=0;      						// Counts the no of re-Roll
    int  diceArray[noDice];     						// Declare an diceArray and   the
	int  howMany[facesPerDice];							// Defines howmany faces array
	char result[100];									// Defines the result char array
	char ch='Y';
							
    while(reRollsCounter<=numberOfReRolls)
    {

        if(ch=='Y' || ch=='y')
        {
            RollDice(diceArray);   						    // if user input Y or y calls the function RollDice
			printf("You rolled: ");
			PrintRoll(diceArray);							//Print the dice array
			printf("\n");
			numberofCombination(howMany,diceArray);			//takes howmany function, and fills it with the count
			combination(result, howMany);					//takes character array result and fill it with compination
			printf("%s", result);							//print the result of the combination
            reRollsCounter++;      							// if user reRolls a dice then counter is increased
			if(reRollsCounter<=numberOfReRolls)
			{
				printf("\nEnter Y to reroll or N to cancel. ");        // Ask user if they want to reroll
				scanf(" %c",&ch);
			}
			
		}
        else if(ch=='N' || ch=='n')
        {
			printf("Thank You! For playing");
            break;                							// if user input N or n terminate the loop
        }
        else
        {
            printf("Sorry! You enter a wrong command.");
			printf("\nEnter Y to reroll or N to cancel. ");        // Ask user if they want to reroll
			scanf(" %c",&ch);
            continue;              							// if users input wrong command runs the loop from above
        }


    }

    return 0;
}








