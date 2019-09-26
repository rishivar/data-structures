typedef Vertex Data;

typedef struct QueueNode{
	Data d;
	struct QueueNode * next ;
}QueueNode;


typedef QueueNode * Queue;

int isEmptyQ(Queue front,Queue rear){
	if(front == 0 || rear == 0)
		return 1;
	return 0;
}

void enqueue(Queue *front,Queue *rear,Data d){
	
	QueueNode * tmp = (QueueNode*)malloc(sizeof(QueueNode));
	tmp -> d = d;
	tmp -> next = NULL;

	if(isEmptyQ(*front,*rear))
		(*front) = (*rear) = tmp;
	else{
		(*rear) -> next = tmp;
		(*rear) = tmp;
	}

}

Data dequeue(Queue * front,Queue * rear){
	Vertex rval;
	strcpy(rval.adj,"");

	QueueNode * tmp;

	if(isEmptyQ(*front,*rear)){
		printf("Queue Empty!\n");
		return rval;
	}

	rval = (*front) -> d;
	tmp = (*front);

	if( (*front) == (*rear) )
		(*front) = (*rear) = 0;
	else
		(*front) = (*front) -> next;
	
	
	free(tmp);
	return rval;
}