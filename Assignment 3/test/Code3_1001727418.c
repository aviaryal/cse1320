/*Avinash Aryal 1001727418*/

#include "DrawTool.h"

int main(void)
{
    int usersize=20;
    char chEnter[maxSize];
	char maxArray[maxSize][maxSize];
	mapInitilization(maxArray, &usersize);
	instruction();
	mapPrint(maxArray,usersize);

	char quit='a';
	while(quit!='q'|| quit!='Q')
    {
        char drawcommand[maxSize];
        //char action[maxSize], row[maxSize],col[maxSize], spot[maxSize], mark[maxSize];
        char action[maxSize], row[maxSize],col[maxSize], spot[maxSize], mark[maxSize];
        printf("Please enter command or q to quit\n");
        fgets(drawcommand, maxSize, stdin);
        //scanf("%s", action);
        char *delimiters = "(,)";
        char *field;

        field=strtok(drawcommand,delimiters);
        strcpy(action,field);
        if(action[0]=='q' || action[0]== 'Q')
        {
            break;
        }

        field=strtok(NULL,delimiters);
        strcpy(row,field);
        int rowno= atoi(row);
        if(rowno>=usersize)
        {
            printf("Invalid row number\n");
            continue;
        }


        field=strtok(NULL,delimiters);
        strcpy(col,field);
        int colno= atoi(col);
        if(colno>=usersize)
        {
            printf("Invalid column no\n");
            continue;
        }


        field=strtok(NULL,delimiters);
        strcpy(spot,field);
        int noSpot= atoi(spot);

        field=strtok(NULL,delimiters);
        strcpy(mark,field);
        if(strcmp(mark,"\n")==0)
        {
            mark[0]='X';
        }




        char upaction;
        upaction= toupper(action[0]);
        if(upaction== 'P' )
        {
            *(*(maxArray+rowno)+colno)=mark[0];
        }
        else if(upaction=='V')
        {
            if(( noSpot+rowno) > (usersize))
            {
                printf("Spot out of bound for column \n");
                continue;
            }
            else
            drawLine(maxArray, rowno,colno,upaction,noSpot, mark[0]);

        }
        else if(upaction=='H')
        {
            if((noSpot+colno)>(usersize))
            {
                printf("Spot out of bound for row \n");
            }
            else
                drawLine(maxArray,rowno,colno,upaction,noSpot,mark[0]);
        }
        else if(upaction=='V')
        {
            if((noSpot+colno)>(usersize))
            {
                printf("Spot out of bound for col \n");
            }
            else
                drawLine(maxArray,rowno,colno,upaction,noSpot,mark[0]);
        }
        else
        {
            printf("Wrong command\n");
        }
        mapPrint(maxArray,usersize);



    }

	return 0;
}



