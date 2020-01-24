/*Avinash Aryal 1001727418*/

#include "GameLib.h"


int main(int argc, char *argv[])
{
	int i;
	AWARD AWARDS[Max_Entries];
	FILE *rhname= OpenAwardFile(argc, argv);
	int noline= FillAwardArray(rhname, AWARDS);
	
	
	int userchoice;
	do
	{
		userchoice=PrintAwardMenu(AWARDS,noline);
		if(userchoice==0)
		{
			for(i=0;i<noline;i++)
			{
				free(AWARDS[i].category);
				free(AWARDS[i].winner);
			}
			return 0;
		}
		else
		{
			GuessIt(&AWARDS[userchoice-1]);
		}
	}
	while(userchoice!=0);
	
}






