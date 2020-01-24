/*Avinash Aryal 1001727418*/

#include "DrawTool.h"


void mapInitilization(char maxArray[][maxSize], int *size)
{
	int i,j, userSize;
	char input[maxSize];
	/* While the usersize is not within the range the function
		ask user to input size again and again
	*/
	do
	{

		printf("Please enter number between 1 and %d:", maxSize);
		scanf("%d",&userSize);
		getchar();
	}while(userSize<=0 || userSize>maxSize);
	
	*size= userSize;		// save user input size on the address pointing by pointer *size
	
	// Ask user for background character
	char bgChar;
	printf("Please enter background character: ");
	scanf(" %c", &bgChar);
	getchar();
	
	
	/* Takes userinput background and size and fills the array */
	for(i=0;i<userSize;i++)
	{
		for(j=0;j<userSize;j++)
		{
			*(*(maxArray+i)+j)= bgChar;
			
		}
	}
}


// map print function print maps
void mapPrint(char maxArray[][maxSize], int userSize)
{
    int i,j;
    for(i=0;i<userSize;i++)
	{
		for(j=0;j<userSize;j++)
		{
			printf("%c ",*(*(maxArray+i)+j));

		}
		printf("\n");
	}
}
// map print function ends

// Draw line function
void drawLine(char maxArray[][maxSize],int row, int col, char action, int noSpot, char bg)
{
    int i;
    if(action=='V')
    {
        /* Check if the action is V and goes to for loop with increasing
			i and row number. Replace the given position with char provided
			by user.
		*/
		for(i=0;i<noSpot;i++,row++)
        {
            *(*(maxArray+row)+col)=bg;

        }
    }
    if(action=='H')
    {
		/* Check if the action is H and goes to for loop with increasing
			i and col number. Replace the given position with char provided
			by user.
		*/
		
        for(i=0;i<noSpot;i++,col++)
        {
            *(*(maxArray+row)+col)=bg;
        }
    }
}
/*DrawLine function ends*/
	
	
/* THis is instrusction function*/	
void instruction()
{
	
    printf("Draw commands start with \n");
    printf("\n");
    printf("\t P for a single point\n"
           "\t H for a horizontal line\n"
           "\t V for a vertical line \n"
           "\n");
    printf("After the P/V/H, enter a row,col coordinate and the number of spots to mark\n"
           "enclosed in () and separated by commas and then the character for the mark.\n"
           "'X' will be used if a mark is not entered. For example,\n");
    printf("\n\t P(2,3,1)* \t start at point 2,3 in the array and mark one spot\n"
           "\t\t\t with an *. For P, the 3rd parameter is ignored.\n");
    printf("\n\t V(1,2,3)$ \t start at point 1,2 in the array and mark the next\n"
           "\t\t\t 3 spots down from the current position with $\n");
    printf("\n\t H(4,6,7)# \t start at point 4,6 in the array and mark the next\n"
           "\t\t\t 7 spots to the right with # \n\n");
    printf("Coordinates out of range and lines drawn past the borders are not allowed.\n"
           "\nEnter Q at the draw command prompt to quit\n"
           "\nPress <ENTER> to continue\n");
	getchar();

}
/* Instruction Function Ends*/





