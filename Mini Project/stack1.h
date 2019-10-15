#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s
{
	int x;
	struct s *next;
}snode;
snode *top=NULL;

void push(int value)
{
	snode *New;
	New=malloc(sizeof(snode));
	New->x=value;
	if(top==NULL)
		New->next=NULL;
	else
		New->next=top;
	top=New;
}

int Pop()
{
	int ele=-1;
	if(top==NULL)
		printf("Stack Empty!!!\n");
	else
	{
		snode *temp=top;
		top=temp->next;
		ele=temp->x;
		free(temp);
	}
	return ele;
}

int peek()
{
	if(top==NULL)
		printf("Stack Empty\n");
	else
		return top->x;
	return -1;
}

int isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void stackdisplay()
{
	if(top==NULL)
		printf("Stack Empty");
	else
	{
		snode *temp=top;
		while(temp->next!=NULL)
		{
			printf("%d",temp->x);
			temp=temp->next;
		}
		printf("%d",temp->x);
	}
}
