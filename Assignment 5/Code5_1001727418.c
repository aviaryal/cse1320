/*Avinash Aryal 1001727418*/

#include "DrawTool.h"
FILE *OpenFile(int argc, char *argv[])
{
	//char *file_Name=NULL;
	//file_Name= malloc(sizeof(char));
	int maxsize=1000;
	char file_Name[maxsize];
	FILE *readfile=NULL;
	if(argc>=2)
	{
		strcpy(file_Name, argv[1]);
		
	}
	else
	{
		printf("Please Enter the file name: ");
		fgets(file_Name, maxsize-1,stdin);
		file_Name[strlen(file_Name)-1]='\0';
	}
	do
	{
		readfile= fopen(file_Name, "r");
		if(readfile==NULL)
		{
			printf("Error reading file. \nPlease enter the file name: ");
			scanf("%s", file_Name);
		}
	}
	while(readfile==NULL);
	return readfile;

}


int main(int argc, char *argv[])
{
	FILE *rhname= OpenFile(argc, argv);
	struct node *head=NULL;
	int i;
	char letter;
	int max=1000;
	char *command;
	char info[max];
	char *token;
	char input[10];
	while(fgets(info,max-1 , rhname)!=NULL)
	{
		if(info[strlen(info)-2]=='\r')
			info[strlen(info)-2]='\0';
		else if(info[strlen(info)-1]=='\n')
			info[strlen(info)-1]='\0';
		if(info[0]=='\n' || info[0]=='\0' || info[0]=='\r')
			break;
		
		token=strtok(info,"|");
		letter=*token;

		token= strtok(NULL,"|");
		command= malloc(strlen(token)*sizeof(char));
		strcpy(command,token);
		addnode(&head, letter, command);
	}
	fclose(rhname);
	char maxArray[maxSize][maxSize];
	mapInitilization(maxArray);
	do
	{
		printf("Please enter 1-3 letters: ");
		scanf("%s",input);
	}
	while(strlen(input)<0 || strlen(input)>3);
	
	for(i=0;i<strlen(input);i++)
	{
		searchnode(&head, toupper(input[i]), maxArray,i);
	    mapPrint(maxArray);
		printf("\n");
	}
	return 0;
	
}



