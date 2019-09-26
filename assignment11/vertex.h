typedef struct Vertex{
	char v;
	char adj[10];
	unsigned visited:1;
}Vertex;

typedef Vertex Graph[30];

Vertex getVertex(){
	Vertex vertex;
	char adj[10];
	char v; 
	vertex.visited = 0;
	
	printf("Enter the vertex: ");
	scanf("%c",&v);
	getchar();
	printf("Enter the verices adjacent to vertex: ");
	scanf("%[^\n]",adj);
	getchar();

	vertex.v = v;
	strcpy(vertex.adj,adj);

	return vertex;
}

char * spaces(const int size){
	static char spaces[20]="";
	for(int i = 0 ; i < size ; i++)
		spaces[i] = ' ';
	spaces[size] = 0;
	return spaces;
}

void PrintAdjacency(const Graph g,const int size){

	system("clear");
	
	printf(" +--------+----------------+\n");
	printf(" | Vertex | Adjacenct List |\n");
	printf(" +--------+----------------+\n");
	
	for(int i = 0 ; i < size ; i++)
		printf(" |   %c    | %s%s |\n",
		g[i].v,g[i].adj,spaces(14-strlen(g[i].adj)));
	
	printf(" +--------+----------------+\n");
	
}