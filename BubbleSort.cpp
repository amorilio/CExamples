// BubbleSort.cpp: implementation of the BubbleSort class.
//
//////////////////////////////////////////////////////////////////////

#include "BubbleSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
}mynode ;

void add_node(struct node **head, int *count, int value);
void print_list(char *listName, struct node *head);
mynode *bubbleSort(mynode **head, int count);

BubbleSort::BubbleSort()
{	
	mynode *head;
	int count = 0;	
	printf("\n---- Start Bubble Sort Test---- \n");

	head = (struct node *)NULL;
	
	add_node(&head, &count, 100);
	add_node(&head, &count, 3);
	add_node(&head, &count, 90);
	add_node(&head, &count, 7);
	add_node(&head, &count, 9);
	
	print_list("myList(BEFORE)", head);
	head = bubbleSort(&head, count);
	print_list("myList(AFTER) ", head);
	
	printf("\n---- End Bubble Sort Test---- \n");
}

BubbleSort::~BubbleSort()
{
	
}

mynode *bubbleSort(mynode **head, int count)
{

	int i, j;
	mynode *p0, *p1, *p2, *p3;
	
	for(i = 1; i < count; i++)
	{
		p0 = (struct node *)NULL;
		p1 = (*head);
		p2 = (*head)->next;
		p3 = p2->next;
		
		for(j = 1; j <= (count - i); j++)
		{
			if(p1->value > p2->value)  
			{
				// Adjust the pointers...       
				p1->next = p3;
				p2->next = p1;
				if(p0)
					p0->next=p2;
				
				// Set the head pointer if it was changed...
				if((*head) == p1)
					(*head)=p2;
				
				// Progress the pointers
				p0 = p2;
				p2 = p1->next;
				if (p3 != NULL && p3->next != NULL) 
					p3 = p3->next;
				else
					p3 = NULL;
			}
			else
			{
				// Nothing to swap, just progress the pointers...
				p0 = p1;
				p1 = p2;
				p2 = p3;
				if (p3 != NULL && p3->next != NULL) 
					p3 = p3->next;
				else
					p3 = NULL;
			}
			
			print_list("myList(Inner Loop) ", *head);
		}		
		printf("\n");
		print_list("myList(Outer Loop) ", *head);
	}
	return	(*head);
}

void add_node(struct node **head, int *count, int value)
{
	mynode *temp, *cur;
	temp = (mynode *)malloc(sizeof(mynode));
	temp->next=NULL;
	temp->prev=NULL;
	
	if(*head == NULL)
	{
		*head=temp;
		temp->value=value;
	}
	else
	{
		for(cur=*head;cur->next!=NULL;cur=cur->next);
		cur->next=temp;
		temp->prev=cur;
		temp->value=value;
	}
	
	*count = *count + 1;
}

void print_list(char *listName, struct node *head)
{
	mynode *temp;
	
	printf("[%s] -> ", listName);
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("[%d]->",temp->value);
	}
	printf("NULL\n");
}

