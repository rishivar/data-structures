#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vertex.h"
#include "Stack.h"
#include "Queue.h"

#include "graphtraversal.h"


char *Strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(void){
	Graph g1,g2;
	int size;
	Vertex start;

	printf("ENTER THE GRAPH:\n");
	printf("Enter the number of vertices: ");
	scanf("%d",&size);
	getchar();

	for(int i = 0 ; i < size; i++){
		g1[i] = getVertex();
		
		if(i == 0)
			start = g1[i];
	}

	PrintAdjacency(g1,size);
	
	printf("BFS OUTPUT:\n");
	BFS(g1,size,start);
	
	for(int i = 0 ; i < size ; i++){
		g1[i].visited = 0;
		Strrev(g1[i].adj);
	}
	start = g1[0];

	printf("\nDFS OUTPUT:\n");
	DFS(g1,size,start);

	return 0;
}