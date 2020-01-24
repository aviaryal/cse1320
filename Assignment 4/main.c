#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define Max_Entries 15
typedef struct
{
	char years[5];
	char *category;
	char *winner;
}
AWARD;

FILE *OpenAwardFile(int argc, char *argv[])
{
	//char *HeapFileName=NULL;
	//HeapFileName= malloc(sizeof(char));
	char HeapFileName[100];
	FILE *readfile;
	if(argc>=2)
	{
		strcpy(HeapFileName, argv[1]);
	}
	else
	{
		printf("Please Enter the file name: ");
		scanf("%s",HeapFileName);
	}
	do
	{

		readfile = fopen(HeapFileName, "r");
		if(readfile==NULL)
		{
			printf("Error reading file. \nPlease enter the file name: ");
			scanf("%s", HeapFileName);
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
	while(fgets(info, maxsize-1, AwardFile))
	{
	    
		token= strtok(info,"|");
		strcpy(FillAward[record].years,token);

		token= strtok(NULL,"|");
		FillAward[record].category= malloc(strlen(token)*sizeof(char));
		strcpy(FillAward[record].category,token);

		token= strtok(NULL,"|");
		FillAward[record].winner= malloc(strlen(token)*sizeof(char));
		strcpy(FillAward[record].winner,token);
		record ++;
	}
	printf("Filling ____array. The record size is %d\n", record);
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
    int noGuess= (randomnumber%(length_winner%2)) +3;

	char upper[length_winner];
	char dash[length_winner];
	char test[length_winner];
	strcpy(upper, singleAward->winner);
	strcpy(dash, singleAward->winner);
	strcpy(test, singleAward->winner);
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
			dash[distance]= userguess;
			upper[distance]='-';
			correct++;

		}

		if(correct==0)
		{
			printf("You enter wrong guess.\n %s",dash);
			noGuess--;
			printf("You have %d guesses\n ", noGuess);
			continue;
		}




		if(strcmp(test, dash)==0)
		{
			printf("You guessed correctly");
			printf("The winner of the %s %s was %s", singleAward->years,singleAward->category, singleAward->winner);
			break;

		}
		else
			printf("\n %s", dash);

	}
	while(noGuess!=0);
}

int main(int argc, char *argv[])
{
    AWARD awardarray[Max_Entries];

    FILE *rhname= OpenAwardFile(argc, argv);
	int noline= FillAwardArray(rhname, awardarray);
	int userchoice;
	do
	{
		userchoice=PrintAwardMenu(awardarray,noline);

		if(userchoice==0)
			return 0;
		else
			GuessIt(&awardarray[userchoice-1]);
	}
	while(userchoice!=0);

    return 0;
}
