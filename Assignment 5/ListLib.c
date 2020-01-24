/* Avinash Aryal 1001727418 */
#include "ListLib.h"

void addnode(node **LinkedListHead, char singlechar, char *command)
{
	// declare pointer type of node
	node *temptr,*newnode;
	// Malloc the newnode
	newnode=malloc(sizeof(newnode));
	newnode->single= singlechar;
	//malloc the letter to input command
	newnode->letter= malloc(strlen(command)+1);
	// copy command to letter
	strcpy(newnode->letter, command);
	//set next pointer to null
	newnode->nextptr=NULL;
	if(*LinkedListHead==NULL)
		*LinkedListHead=newnode;
	else
	{
		temptr=*LinkedListHead;
		while(temptr->nextptr!=NULL)
		{	
			temptr=temptr->nextptr;
		}
		temptr->nextptr=newnode;
	}
	
}
void searchnode(node **LinkedListHead, char search, char maxarray[maxSize][maxSize], int letterpositon)
{
	node *temptr;
	temptr=*LinkedListHead;
	while(temptr!=NULL)
	{
		if(temptr->single==search)
		{
			checkinputcommand(temptr->letter,maxarray,letterpositon);
		}
			
		temptr=temptr->nextptr;
			
	}
		
}









