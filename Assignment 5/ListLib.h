/* Avinash Aryal 1001727418 */
#ifndef _LinkedList
#define _LinkedList

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "DrawTool.h"

typedef struct node
{
	char single;
	char *letter;
	struct node *nextptr;
}	
node;

void addnode(node **LinkedListHead, char singlechar, char command[]);
void searchnode(node **LinkedListHead, char search, char maxarray[maxSize][maxSize], int letterpositon);









#endif


