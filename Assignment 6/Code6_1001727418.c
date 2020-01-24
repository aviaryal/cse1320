#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "QueueLib.h"
#include "BSTLib.h"
#include "ListLib.h"
#include "StackLib.h"

#define MAXROWS 10
#define MAXCOLS 10

/* Add prototypes */
void PrintReceipts(SNODE **StackTop);
int ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT);
BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol);
int ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT);
int ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode);
int ReadMovieTheaterFile(char MovieTheaterMap[][MAXCOLS], char FileName[], int row, int col);
void WriteMap(BNODE *MyTheater, char MovieTheaterMap[][MAXCOLS], int MapRow, int MapCol);
void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[]);
void PrintSeatMap(char MovieTheaterMap[][MAXCOLS], int row, int col);
int PrintMenu();

void PrintReceipts(SNODE **StackTop)
{
	/* 
	   if the StackTop is empty, the print appropriate message - see example output - 
	   else print out the receipts.  A receipt is one node of the stack and each receipt
	   consists of a receipt number, a movie theater name and a TicketList (a linked list
	   of all seats sold to one customer).  Use ReturnAndFreeLinkedListNode() to traverse 
	   the linked list stored in each stack node and display the seats and free the 
	   linked list nodes.  Call pop() to remove the stack node.
	*/
	if(*StackTop==NULL)
		printf("Nothing to print\n");
	else
	{
		printf("Today Recipts\n\n");
		while((*StackTop)!=NULL)
		{
			printf("\nReceipt Number %d\n", (*StackTop)->ReceiptNumber);
			printf("\t%s\n\n", (*StackTop)->MovieTheaterName);
			while((*StackTop)->TicketList!=NULL)
			{
				printf("\t%s\t", (*StackTop)->TicketList->Ticket);
				ReturnAndFreeLinkedListNode(&(*StackTop)->TicketList,(*StackTop)->TicketList->Ticket);			
			}
			pop(StackTop);
		}
		
	}
	
}

BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol)
{
	BNODE *MyTheater = BSTRoot;
	char zip[10] = {};
	char MyDims[6] = {};
	
	printf("\n\nPick a theater by entering the zipcode\n\n");
				
	// Traverse the BST in order and print out the theaters in zip code order - use InOrder()			
	InOrder(BSTRoot);
	
	// Prompt for a zip
	scanf(" %s",zip);
	//fgets(zip, 9,stdin);
	
	
	// Call SearchForBNODE()
	BNODE *result = SearchForBNODE(MyTheater, zip);
	
	// If theater is not found, then print message
	if(result==NULL)
		printf("Sorry wrong zip code");
	else
	{
		// If theater is found, then tokenize the theater's dimensions and
		// pass those dimensions and the MovieTheaterMap and the theater's filename
		// to ReadMovieTheaterFile()
		strcpy(MyDims, result->Dimensions);
		char *token;
		char *deliminator="*x";
		token= strtok(MyDims, deliminator);
		int row = atoi(token);
		*MapRow=row;
		token=strtok(NULL,deliminator);
		int col= atoi(token);
		*MapCol=col;
		// If ReadMovieTheaterFile() returns FALSE, then print
		// "Unable to print that seat map at this time.  Check back later."
		// else call PrintSeatMap()
		char name[50];
		strcpy(name, result->FileName);
		int result = ReadMovieTheaterFile(MovieTheaterMap, name,row, col);
		if(result)
			PrintSeatMap(MovieTheaterMap, row, col);
		else
			printf("Unable to print that seat map at this time.Check back later.");

	}
	// return the found theater
	return result;
}	

int ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT)
{
	//	read the passed in file and calls enQueue for each name in the file
	int successfulread=0;
	char name[100];
	while(fgets(name, 99, QueueFile))
	{
		//enQueue(char CustomerName[], QNODE **QueueHead, QNODE **QueueTail)
		enQueue(name, QH, QT);
		successfulread++;
	}
	return successfulread;
}

int ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode)
{
	//	read the passed in file and tokenize each line and pass the information to AddBSTNode
	int successfulcall=0;
	char name[100];
	char *deliminator="|";
	char *MovieTheaterName;
	char *token;
	char zip[6];
	char *filename;
	char *dimensions;
	while(fgets(name, sizeof(name)-1, BSTFile))
	{
		//AddBSTNode(BNODE **BSTnode, char MTN[], char ZC[], char FN[], char DIM[])
		name[strlen(name)-1]='\0';
		
		token=strtok(name, deliminator);
		MovieTheaterName= malloc(sizeof(char)*strlen(token));
		strcpy(MovieTheaterName, token);
		
		token=strtok(NULL,deliminator);
		strcpy(zip,token);
		
		token=strtok(NULL,deliminator);
		filename=malloc(strlen(token)*sizeof(char));
		strcpy(filename,token);
		
		token=strtok(NULL, deliminator);
		dimensions= malloc(strlen(token)*sizeof(char));
		strcpy(dimensions, token);
		
		AddBSTNode(BSTnode, MovieTheaterName, zip, filename, dimensions);
		successfulcall++;
	}
	return successfulcall;
}

int ReadMovieTheaterFile(char MovieTheaterMap[][MAXCOLS], char FileName[], int row, int col)
{
	FILE *MapFile;
	char MapLine[MAXROWS*MAXCOLS+10]={};
	int i, j, k = 0;
	
	MapFile = fopen(FileName, "r+");
	if (MapFile == NULL)
	{
		printf("\nFile \"%s\" did not open\n\n", FileName);
		return 0;
	}
	
	fgets(MapLine, sizeof(MapLine)-1, MapFile);
	
	if (strlen(MapLine) != row*col)
		return 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			MovieTheaterMap[i][j] = MapLine[k++];
		}
	}
	
	fclose(MapFile);
	
	return 1;	
}
				
void WriteMap(BNODE *MyTheater, char MovieTheaterMap[][MAXCOLS], int MapRow, int MapCol)
{
	FILE *MapFile;
	int i, j, k = 0;
	char MovieTheaterLine[MapRow*MapCol];
	
	MapFile = fopen(MyTheater->FileName, "w+");
	if (MapFile == NULL)
	{
		printf("\nFile \"%s\" did not open\n\n", MyTheater->FileName);
	}
	
	for (i = 0; i < MapRow; i++)
	{
		for (j = 0; j < MapCol; j++)
		{
			MovieTheaterLine[k++] = MovieTheaterMap[i][j];
		}
	}		
	MovieTheaterLine[k] = '\0';
	
	fputs(MovieTheaterLine, MapFile);
	fclose(MapFile);
}

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i  = 0; 
	
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
	
	return;
}

void PrintSeatMap(char MovieTheaterMap[][MAXCOLS], int row, int col)
{
	int i, j;

	printf("\n\n\t");
	for (i = 1; i <= col; i++)
	{
		printf("Seat%-3d", i);		
	}
	printf("\n");
	
	for (i = 0; i < row; i++)
	{
		printf("Row %c\t", i+65);
		for (j = 0; j < col; j++)
		{
			printf("%-7c", MovieTheaterMap[i][j]);
		}
		printf("\n");
	}
}

int PrintMenu()
{
	int choice = 0;
	
	printf("\n\n1.	Sell tickets to next customer\n\n");
	printf("2.	See who's in line\n\n");
	printf("3.	See the seat map for a given theater\n\n");
	printf("4.	Print today's receipts\n\n");
	printf("Choice : ");
	scanf("%d", &choice);
	getchar();
	while (choice < 1 || choice > 4)
	{
		printf("Invalid choice.  Please reenter. ");
		scanf("%d", &choice);
	}

	
	return choice;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	FILE *queueFile = NULL;
	FILE *zipFile = NULL;
	char arg_value[20];
	char queuefilename[20];
	char zipfilename[20];
	int ReceiptNumber = 0;
	int choice = 0;
	int SeatNumber;
	char Row;
	char Ticket[5];
	int ArrayRow, ArrayCol;
	int MapRow, MapCol;
	char MovieTheaterMap[MAXROWS][MAXCOLS] = {};
	LNODE *TicketLinkedListHead = NULL;
	QNODE *QueueHead = NULL;
	QNODE *QueueTail = NULL;
	BNODE *BSTRoot = NULL;
	BNODE *MyTheater = NULL;
	SNODE *StackTop = NULL;
	int NumberOfTickets = 0;
	
	if (argc != 4)
	{
		printf("%s QUEUE=xxxxxx ZIPFILE=xxxxx RECEIPTNUMBER=xxxxx\n", argv[0]);
		exit(0);
	}
	
	get_command_line_parameter(argv, "QUEUE=", queuefilename);
	get_command_line_parameter(argv, "ZIPFILE=", zipfilename);
	get_command_line_parameter(argv, "RECEIPTNUMBER=", arg_value);
	ReceiptNumber = atoi(arg_value);
		
	/* open queuefilename - if it does not open, print message and exit */	
	queueFile = fopen(queuefilename, "r");
	if(queueFile==NULL)
		return 0;

	/* open zipfilename - if it does not open, print message and exit */
	zipFile=fopen(zipfilename,"r");
	if(zipFile==NULL)
		return 0;

	ReadFileIntoQueue(queueFile, &QueueHead, &QueueTail);
	ReadFileIntoBST(zipFile, &BSTRoot);
	
	while (QueueHead != NULL)
	{
		choice = PrintMenu();
	
		switch (choice)
		{
			case 1 :
				printf("\n\nHello %s\n", QueueHead->name);				
				MyTheater = PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				if (MyTheater == NULL)
					break;
				printf("\n\nHow many movie tickets do you want to buy? ");
				scanf("%d", &NumberOfTickets);
				for (i = 0; i < NumberOfTickets; i++)
				{
					do
					{
						printf("\nPick a seat (Row Seat) ");
						scanf(" %c%d", &Row, &SeatNumber);
						Row = toupper(Row);
						ArrayRow = (int)Row - 65;
						ArrayCol = SeatNumber - 1;
					
						if ((ArrayRow < 0 || ArrayRow >= MapRow) ||
							(ArrayCol < 0 || ArrayCol >= MapCol))
						{
							printf("\nThat is not a valid seat.  Please choose again\n\n");
						}		
					}
					while ((ArrayRow < 0 || ArrayRow >= MapRow) ||
						   (ArrayCol < 0 || ArrayCol >= MapCol));
					
					if (MovieTheaterMap[ArrayRow][ArrayCol] == 'O')
					{	
						MovieTheaterMap[ArrayRow][ArrayCol] = 'X';
						sprintf(Ticket, "%c%d", Row, SeatNumber); 
						InsertNode(&TicketLinkedListHead, Ticket);
					}
					else
					{
						printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
						i--;
					}
					PrintSeatMap(MovieTheaterMap, MapRow, MapCol);
				}
				
				WriteMap(MyTheater, MovieTheaterMap, MapRow, MapCol);
				push(&StackTop, TicketLinkedListHead, ReceiptNumber, MyTheater->MovieTheaterName);
				TicketLinkedListHead = NULL;
				ReceiptNumber++;
				printf("\nThank you %s - enjoy your movie!\n", QueueHead->name);
				deQueue(&QueueHead);
				
				break;
			case 2 : 
				printf("\n\nCustomer Queue\n\n");
				DisplayQueue(QueueHead);
				printf("\n\n");
				break;
			case 3 :
				PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				break;
			case 4 : 
				PrintReceipts(&StackTop);
				break;
			default :
				printf("Bad menu choice");
		}
	}
	
	printf("Good job - you sold tickets to all of the customers in line.\n");
	PrintReceipts(&StackTop);
	
	return 0;
}
