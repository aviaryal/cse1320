/* Linked List Library */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListLib.h"

// First parameter - Address of linked list head
// Second parameter - Ticket being added to linked list
void InsertNode(LNODE **LLH, char Ticket[])
{
    int NodeAdded = 0;
    LNODE *TempPtr, *PrevPtr, *NewNode;
    
	PrevPtr = NULL;
	TempPtr = *LLH;
	
	/* Traverse the list and find where to insert the new node */
	while (TempPtr != NULL && (strcmp(Ticket, TempPtr->Ticket) > 0))
	{
		PrevPtr = TempPtr;
		TempPtr = TempPtr->next_ptr;
	}
	
	/* we found the node so insert the new one */
	NewNode = malloc(sizeof(LNODE));
	strcpy(NewNode->Ticket, Ticket);
	NewNode->next_ptr = TempPtr;

	/* If PrevPtr is still NULL, then we are at the start of the list */
	if (PrevPtr == NULL)
	{
		*LLH = NewNode;
	}
	else
	{
		PrevPtr->next_ptr = NewNode;
	}
}

// First parameter - Address of linked list head
// Second parameter - One ticket that has been taken off the linked list (node was freed) 
void ReturnAndFreeLinkedListNode(LNODE **LLH, char Ticket[])
{
	LNODE *TempPtr;
    TempPtr = *LLH;

    if (TempPtr != NULL)
    {
		strcpy(Ticket, TempPtr->Ticket);
		free(*LLH);
		*LLH = (TempPtr)->next_ptr;
	}
}
