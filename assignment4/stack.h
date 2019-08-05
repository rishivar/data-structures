#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#include<ctype.h>
#define bool int 


struct sNode 
{ 
char data; 
struct sNode *next; 
}; 


void pushi(struct sNode** top_ref, float new_data); 


int popi(struct sNode** top_ref); 


bool isMatchingPair(char character1, char character2) 
{ 
if (character1 == '(' && character2 == ')') 
	return 1; 
else if (character1 == '{' && character2 == '}') 
	return 1; 
else if (character1 == '[' && character2 == ']') 
	return 1; 
else
	return 0; 
} 


bool areParenthesisBalanced(char exp[]) 
{ 
int i = 0; 


struct sNode *stack = NULL; 


while (exp[i]) 
{ 
	
	if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') 
		pushi(&stack, exp[i]); 

	
	if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') 
	{ 
			
		
		if (stack == NULL) 
		return 0; 

		
		else if ( !isMatchingPair(popi(&stack), exp[i]) ) 
		return 0; 
	} 
	i++; 
} 
	

if (stack == NULL) 
	return 1;
else
	return 0;
} 


void pushi(struct sNode** top_ref, float new_data) 
{ 
	struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode)); 		 
	new_node->data = new_data; 
	new_node->next = (*top_ref); 
	(*top_ref) = new_node; 
} 


int popi(struct sNode** top_ref) 
{ 
	char res; 
	struct sNode *top; 
	top = *top_ref; 
	res = top->data; 
	*top_ref = top->next; 
	free(top); 
	return res; 
} 

struct Stack
{
int top;
unsigned capacity;
float* array;
};

struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) 
	  return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 

	stack->array = (float*) malloc(stack->capacity * sizeof(float)); 

	if (!stack->array) 
		return NULL; 
	return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
}

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
}

float pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
}

int isOperand(char ch) 
{ 
	return (ch >= '1' && ch <= '9'); 
} 

int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+': 
	case '-': 
		return 1; 

	case '*': 
	case '/': 
		return 2; 

	case '^': 
		return 3; 
	} 
	return -1; 
} 


int infixToPostfix(char* exp) 
{ 
	int i, k; 
 
	struct Stack* stack = createStack(strlen(exp)); 
	if(!stack)
		return -1 ; 

	for (i = 0, k = -1; exp[i]; ++i) 
	{ 
		
		if (isOperand(exp[i])) 
			exp[++k] = exp[i]; 
		
		
		else if (exp[i] == '(') 
			push(stack, exp[i]); 
		

		else if (exp[i] == ')') 
		{ 
			while (!isEmpty(stack) && peek(stack) != '(') 
				exp[++k] = pop(stack); 
			if (!isEmpty(stack) && peek(stack) != '(') 
				return -1; 		 
			else
				pop(stack); 
		} 
		else
		{ 
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack))) 
				exp[++k] = pop(stack); 
			push(stack, exp[i]); 
		} 

	} 

	
	while (!isEmpty(stack)) 
		exp[++k] = pop(stack ); 

	exp[++k] = '\0'; 
	printf( "%s", exp ); 
	return 0;
} 


float evaluatePostfix(char* exp) 
{ 
	
	struct Stack* stack = createStack(strlen(exp)); 
	int i; 	
	if (!stack) return -1; 	
	for (i = 0; exp[i]; ++i) 
	{ 
		float temp;
		if (isdigit(exp[i])) 
			push(stack, exp[i] - '0'); 
		else
		{ 
			float val1 = (float) pop(stack); 
			float val2 = (float) pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': 	temp = val1+val2;
						push(stack, temp); 
						break; 
			case '-': 	temp = val2-val1;
						push(stack, temp);
						break; 
			case '*': 	temp = val2*val1;
						push(stack, val2 * val1); 
						break; 
			case '/': 	temp = val2/val1;
						push(stack, temp); 
						break; 
			} 
		} 
	} 
	return pop(stack); 
} 



