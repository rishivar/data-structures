#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct q
{
	int n;
	struct q *next;
}qnode;
qnode *front=NULL;
qnode *rear=NULL;

int qEmpty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void queuedisplay()
{
	if(front==NULL)
	{
		printf("Queue Empty!!!\n");
	}
	else
	{
		qnode *temp=front;
		while(temp->next!=NULL)
		{
			printf("%d \n",temp->n);
			temp=temp->next;
		}
		printf("%d \n",temp->n);
	}
}

void enqueue(int num)
{
	qnode *New;
	New=malloc(sizeof(qnode));
	if(New==NULL)
	{
		printf("Fatal Error !!!\n");
	}
	New->next=NULL;
	New->n=num;
	if(front==NULL)
	{
		front=New;
		rear=New;
	}
	else
	{
		rear->next=New;
		rear=New;
	}
}

int dequeue()
{
	int out=-1;
	if (front==NULL)
	{
		printf("Queue Empty!!!\n");
	}
	else
	{
		qnode *temp=front;
		front=front->next;
		out=temp->n;
		free(temp);
		if(front==NULL)
			rear=NULL;
	}
	return out;
}
