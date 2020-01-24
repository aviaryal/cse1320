/*Avinash Aryal 1001727418*/

#include "DrawTool.h"

int main(void)
{
	int usersize;
	char maxArray[maxSize][maxSize];
	mapInitilization(maxArray, &usersize);
	instruction();
	mapPrint(maxArray,usersize);

	
	while(1)
    {
		int drawcommandsize=100;
        char drawcommand[drawcommandsize];
		
        char action,mark;
		int rowno,colno,noSpot;
		
        printf("Please enter command or q to quit\n");
        fgets(drawcommand, drawcommandsize-1, stdin); // Take String input from user
		
		
		/* Using the strtok function to extract the desired input*/
		char *delimiters = "(,)";
        char *token;	
        token=strtok(drawcommand,delimiters);
		action=*token;
		if(action=='q' || action== 'Q')
        {
            break;
        }
		
        token=strtok(NULL,delimiters);
		rowno= atoi(token);
        
        token=strtok(NULL,delimiters);
		colno= atoi(token);
       
        token=strtok(NULL,delimiters);
        noSpot=atoi(token);

        token=strtok(NULL,delimiters);
        mark=*token;
		
        if(mark=='\n')
        {
            mark='X';
        }
        
        action= toupper(action);
        
		if(action== 'P' )
        {
			/* While action is 'P' and rowno<usersize and column no < usersize 
				place the desired charcater into the function. 
			*/
            if(rowno<usersize && colno<usersize && rowno>=0 && colno>=0)
			{
				*(*(maxArray+rowno)+colno)=mark;
				
			}
			else 
				printf("Invalid command\n");
			
        }
        else if(action=='V')
        {
            
			if(( noSpot+rowno)<=(usersize) && noSpot>0 && rowno>=0 && colno>=0 && colno<usersize && rowno<usersize)
            {
                
				drawLine(maxArray, rowno,colno,action,noSpot, mark);
                
            }
            else
            {
				printf("Invalid command \n");
				
			}

        }
        else if(action=='H')
        {
            if((noSpot+colno)<=(usersize)&& noSpot>0 && colno>=0 && rowno>=0 && colno<usersize && rowno<usersize)
            {
                drawLine(maxArray,rowno,colno,action,noSpot,mark);
            }
            else
				printf("Invalid command\n");
                
		}
        else
        {
            printf("Wrong command\n");
			
        }
        mapPrint(maxArray,usersize);

    }

	return 0;
}



