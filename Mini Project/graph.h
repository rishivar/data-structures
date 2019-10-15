#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "stack1.h"
#include "queue.h"

void initial(int adj[][5],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			adj[i][j]=0;
		}
	}
}

void insert(int adj[][5],int src,int dest)
{
	adj[src][dest]=1;
}

void display(int adj[][5],int n)
{
	printf("-\t");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t",i);
	}
	printf("\n \t");
	for (int i = 0; i < n; ++i)
	{
		printf("-------");
	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d|\t",i);
		for (int j = 0; j < n; ++j)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
}

int visited(int ele,int ar[],int n)
{
	int flag=0;
	if (n==0)
	{
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (ar[i]==ele)
		{
			flag=1;
			break;
		}
	}
	return flag;
}

int dfs(int start,int adj[][5],int ar[],int size)
{
	int i=0;
	push(start);
	while(!isEmpty())
	{
		i=Pop();
		if(!visited(i,ar,size))
		{
			ar[size]=i;
			size++;
		}
		for(int j=5-1;j>=0;j--)
		{
			if(adj[i][j]!=0)
			{
				if(!visited(j,ar,size))
					push(j);
			}
		}
	}
	return size;
}

int bfs(int start,int adj[][5],int ar[],int size)
{
	int i=-1;
	enqueue(start);
	i=start;
	ar[size]=i;
	size++;
	while(!qEmpty())
	{
		i=dequeue();
		for(int j=0;j<5;j++)
		{
			if(adj[i][j]!=0)
			{
				if(!visited(j,ar,size))
				{
					ar[size]=j;
					size++;
					enqueue(j);
				}
			}
		}
	}
	return size;
}
