#include "DrawTool.h"
#include <stdio.h>

void mapInitilization(char maxArray[][maxSize], int *size)
{
	int i,j, userSize;
	do
	{

		printf("Please enter number between 1 and 20:");
		scanf("%d",&userSize);
		getchar();
	}while(userSize<0 || userSize>20);
	
	*size= userSize;
	char bgChar;
	printf("Please enter background character: ");
	scanf(" %c", &bgChar);
	getchar();
	//char (*ptr)[userSize]= maxArray;
	//char *ptr= &maxArray[0][0];

	for(i=0;i<userSize;i++)
	{
		for(j=0;j<userSize;j++)
		{
			*(*(maxArray+i)+j)= bgChar;
			//maxArray[i][j]=bgChar;
		}
	}
}



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



void drawLine(char maxArray[][maxSize],int row, int col, char action, int noSpot, char bg)
{
    int i;
    if(action=='V')
    {
        for(i=0;i<noSpot;i++,row++)
        {
            *(*(maxArray+row)+col)=bg;

        }
    }
    if(action=='H')
    {
        for(i=0;i<noSpot;i++,col++)
        {
            *(*(maxArray+row)+col)=bg;
        }
    }
}
	
	
void instruction()
{
	char chEnter[maxSize];
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
	do
    {
        fgets(chEnter, maxSize, stdin);
		//scanf(" %c", &chEnter);
    }
    while(chEnter[0]!='\n');
}


