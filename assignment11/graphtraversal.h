
int find(Graph g,int size,const char C){
	for(int i = 0 ; i < size ; i++)
		if(g[i].v == C)//Match Found
			return i;
	return -1;
}


void DFS(Graph g,int size,Vertex start){
	if(strcmp(start.adj,"-") == 0)
		return;

	Stack s = createEmptyStack();
	char adj[10];
	push(&s,start);
	Vertex tmp;

	while(!isEmptyStack(s)){
		tmp = pop(&s);
		if(g[find(g,size,tmp.v)].visited == 0){
			g[find(g,size,tmp.v)].visited = 1;
			printf("%c\t",tmp.v);
		}
		else
		 continue;	
		
		strcpy(adj,tmp.adj);

		if(adj[0] =='-')
			continue;		
	
		for(int i = 0 ; adj[i] ; i++)
			if(adj[i] == ' ')
				continue;
			else
				push(&s,g[find(g,size,adj[i])]);
	}
}

void BFS(Graph g,int size,Vertex start){
	if(strcmp(start.adj,"-") == 0)
		return;

	char adj[10];
	Queue front = 0, rear = 0;	
	enqueue(&front,&rear,start);
	Vertex temp;

	while(!isEmptyQ(front,rear)){
		temp = dequeue(&front,&rear);
		
		if(g[find(g,size,temp.v)].visited == 1)
			continue;
		
		printf("%c\t",temp.v);
		g[find(g,size,temp.v)].visited = 1;
		
		strcpy(adj,temp.adj);
		if(strcmp(temp.adj,"-") == 0)
			continue;
		
		for(int i = 0 ; adj[i] ; i++){
			if(adj[i] == ' ')
				continue;
			if( g[find(g,size,adj[i])].visited == 1)
					continue;	
			else
				enqueue(&front,&rear,g[find(g,size,adj[i])]);	
		}
	}
}