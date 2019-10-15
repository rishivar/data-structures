#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char dest[100];
    int vertex;
    int dist;
    struct node* link;
};

struct node* graph[20];
char p[][20] = {"Chennai","Coimbatore","Madurai","Pondicherry","Villupuram"};

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        graph[i]=malloc(sizeof(struct node));
        graph[i]->vertex=-1;
        graph[i]->dist=0;
        strcpy(graph[i]->dest,p[i]);
        graph[i]->link=NULL;
    }    
    return ;
}

void addEdge(int src, int dest, char ar[],int dist)
{
    struct node* New = malloc(sizeof(struct node));
    New->vertex=dest;
    New->link=NULL;
    strcpy(New->dest,ar);
    New->dist=dist;

    struct node* temp=graph[src];
    
    while(temp->link!=NULL)
    {
        temp=temp->link;

    }

    temp->link=New;

}

void printGraph(int n)
{
    int v;
    for (v = 0; v < n; ++v)
    {
        printf("%s -> ",graph[v]->dest);
        struct node* temp = graph[v]->link;
        while (temp!=NULL)
        {
            printf("%s(%d) ", temp->dest,temp->dist);
            temp = temp->link;
        }
        printf("\n");
    }
}

void ListtoMatrix(int G[][5])
{
    for (int v = 0; v < 5; ++v)
    {
        struct node* temp = graph[v]->link;
        while (temp!=NULL)
        {
        	G[v][temp->vertex]=temp->dist;
            temp = temp->link;
        }
    }
}

void stationInitialise(int G[][5])
{
    init(5);
    /*
    0-Chennai
    1-Villupuram
    2-Pondicherry
    3-Madurai
    4-Coimbatore
    */

    addEdge(0,4,p[4],168);
    addEdge(4,0,p[0],168);
    addEdge(0,1,p[1],513);
    addEdge(1,0,p[0],513);
    addEdge(0,3,p[3],165);
    addEdge(3,0,p[0],165);
    
    addEdge(4,1,p[1],337);
    addEdge(1,4,p[4],337);
	addEdge(4,2,p[2],294);
	addEdge(2,4,p[4],294);
    addEdge(4,3,p[3],41);
    addEdge(3,4,p[4],41);
    
    addEdge(3,2,p[2],300);
    addEdge(2,3,p[3],300);
    
    addEdge(2,1,p[1],236);
	addEdge(1,2,p[2],236);
	
	//printGraph(5);
	
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			G[i][j]=0;
	/*
	printf("\nBefore List to Matrix \n");
	
	for(int i=0;i<5;i++)
	{
		printf("%d-> %s\t",i,p[i]);
		for(int j=0;j<5;j++)
		{
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	*/
	
	ListtoMatrix(G);
	
	/*
	printf("\nAfter List to Matrix \n");
    printf("\t\tChennai\tCBE\tMadurai\tPondi\tVillupuram\n");
	for(int i=0;i<5;i++)
	{
		printf("%s\t",p[i]);
		for(int j=0;j<5;j++)
		{
			printf("%d\t",G[i][j]);
		}
		printf("\n");
	}
	*/
}
