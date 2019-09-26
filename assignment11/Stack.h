typedef Vertex Data;

typedef struct StackNode{
	Data d;
	struct StackNode * next;
}StackNode;

typedef StackNode* Stack;

Stack createEmptyStack(){
	return 0;
}

int isEmptyStack(Stack top){
	return top == 0;
}

void push(Stack * top,Data d){
	StackNode * tmp = (StackNode*)malloc(sizeof(StackNode));
	tmp -> d = d;
	tmp -> next = 0;
	if(!isEmptyStack(*top))
		tmp -> next = (*top);
	(*top) = tmp;
}

Data pop(Stack * top){
	Data rval;
	strcpy(rval.adj,"");

	if(isEmptyStack(*top))
		return rval;

	rval = (*top) -> d;
	StackNode * tmp = *top;
	*top = (*top) -> next;
	free(tmp);
	return rval;
}

Data peek(Stack top){
	return top -> d; 
}


void displayStack(Stack top){
	StackNode * tmp = top;
	if(isEmptyStack(top)){
		printf("Empty Stack!");
		return;
	}
	while(tmp){
		printf("%c ",tmp -> d.v);
		tmp = tmp -> next;
	}
	printf("\n");
}