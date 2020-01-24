/*Avinash Aryal 1001727418*/

#include "DrawTool.h"


void mapInitilization(char maxArray[][maxSize])
{
	char bgChar;
	int i,j;
	printf("Please enter background character: ");
	scanf(" %c", &bgChar);
	getchar();
	
	
	/* Takes userinput background and size and fills the array */
	for(i=0;i<maxSize;i++)
	{
		for(j=0;j<maxSize;j++)
		{
			*(*(maxArray+i)+j)= bgChar;
			
		}
	}
}


// map print function print maps
void mapPrint(char maxArray[][maxSize])
{
    int i,j;
    for(i=0;i<maxSize;i++)
	{
		for(j=0;j<maxSize;j++)
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
void checkinputcommand(char *drawcommand,char maxArray[maxSize][maxSize], int commandposition)
{
	char command[strlen(drawcommand)];
	strcpy(command,drawcommand); 
	
	int i, rowno, colno,noSpot;
	char action, mark;
    char *delimiters = "(,)";
    char *token;
    token = strtok(command, delimiters);
    action = *token;
   
    token = strtok(NULL, delimiters);
    rowno = atoi(token);

    token = strtok(NULL, delimiters);
    colno = atoi(token);

    token = strtok(NULL, delimiters);
    noSpot = atoi(token);

    token = strtok(NULL, delimiters);
    if (token == NULL)
    {
        mark = 'X';
    }
	else
		mark = *token;

	
	
	if(commandposition==1)
		colno+=7;
	else if(commandposition==2)
		colno+=14;

    
    action = toupper(action);

    if (action == 'P')
    {
        /* While action is 'P' and rowno<maxSize and column no < maxSize 
				place the desired charcater into the function. 
			*/
        if (rowno < maxSize && colno < maxSize && rowno >= 0 && colno >= 0)
        {
            *(*(maxArray + rowno) + colno) = mark;
        }
        
    }
    else if (action == 'V')
    {
		
        if ((noSpot + rowno) <= (maxSize) && noSpot > 0 && rowno >= 0 && colno >= 0 && colno < maxSize && rowno < maxSize)
        {
			
            drawLine(maxArray, rowno, colno, action, noSpot, mark);
        }
        
    }
    else if (action == 'H')
    {
		
        if ((noSpot + colno) <= (maxSize) && noSpot > 0 && colno >= 0 && rowno >= 0 && colno < maxSize && rowno < maxSize)
        {
            drawLine(maxArray, rowno, colno, action, noSpot, mark);
        }
        
    }
    
}



