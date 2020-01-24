/*Avinash Aryal 1001727418*/
#include "GameLib.h"

FILE *OpenAwardFile(int argc, char *argv[])
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
int FillAwardArray(FILE *AwardFile, AWARD FillAward[])
{

	int maxsize=1000;
	//char *info=malloc(sizeof(char));
	char info[maxsize];
	char *token;
	int record=0;
	while(fgets(info,maxsize-1 , AwardFile)!=NULL && record<Max_Entries)
	{
		if(info[strlen(info)-2]=='\r')
			info[strlen(info)-2]='\0';
		else if(info[strlen(info)-1]=='\n')
			info[strlen(info)-1]='\0';
		token=strtok(info,"|");
		strcpy(FillAward[record].years,token);

		token= strtok(NULL,"|");
		FillAward[record].category= malloc(strlen(token)*sizeof(char));
		strcpy(FillAward[record].category,token);

		token= strtok(NULL,"|");
		FillAward[record].winner= malloc(strlen(token)*sizeof(char));
		strcpy(FillAward[record].winner,token);
		record ++;
		
	}
	
	fclose(AwardFile);
	return record;

}


int PrintAwardMenu(AWARD awardarray[], int noline)
{
	int i=0;
	printf("Welcome to the Academy Awards Guessing Game\n\n");
	printf("0. Exit\n");
	for(i=0; i<noline; i++)
	{
		printf("%d. %s %s\n", i+1, awardarray[i].years, awardarray[i].category);
	}
	int choice;
	do
	{
		printf("Pick a Category: ");
		scanf("%d",&choice);
		getchar();
	}
	while(choice<=-1 || choice>=noline+1);

	return choice;

}

void GuessIt(AWARD *singleAward)
{
	int i;
	srand(time(0));
	int randomnumber=rand();

	int length_winner= strlen(singleAward->winner);
    int noGuess= (randomnumber%(length_winner/2)) +3;

	char upper[length_winner];
	char dash[length_winner];
	char orginal[length_winner];
	strcpy(upper, singleAward->winner);
	strcpy(dash, singleAward->winner);
	strcpy(orginal, singleAward->winner);
	for(i=0;i<length_winner;i++)
	{
		upper[i]= toupper(upper[i]);
		dash[i]=toupper(dash[i]);
	}
	char alpha[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	

	char *firstoccur;
	firstoccur=strpbrk(dash,alpha);
	while(firstoccur!=NULL)
	{
		*firstoccur='-';
		firstoccur=strpbrk(dash,alpha);
	}
	
	printf("You have %d guess to guess %s in %s\n", noGuess, singleAward->category, singleAward->years);
	do
	{
		char userguess;
		printf("Enter your guess[letter]: ");
		scanf(" %c", &userguess);

		int correct=0;

		char uguess= toupper(userguess);
		
		while(strchr(upper,uguess)!=NULL)
		{
			int distance=strchr(upper, uguess)-upper;
			dash[distance]= orginal[distance];
			upper[distance]='-';
			correct++;

		}

		if(correct==0)
		{
			printf("You enter wrong guess.\n%s",dash);
			noGuess--;
			printf("\nYou have %d guesses\n", noGuess);
			continue;
		}

		if(strcmp(orginal, dash)==0)
		{
			printf("\n\nYou guessed correctly. ");
			printf("The winner of the %s %s was \"%s\".\n", singleAward->years,singleAward->category, singleAward->winner);
			break;

		}
		else
			printf("\n%s\n", dash);
		

	}
	while(noGuess!=0);
	if(noGuess==0)
		printf("\nYou are out of guess\n");
}






