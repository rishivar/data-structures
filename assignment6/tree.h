#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

typedef struct et
{
	char value;
	struct et *left, *right;
}et;

typedef struct str
{
	et *x;
	struct str *next;
}Node;
Node *Top=NULL;

void treepush(et* value)
{
	Node *new;
	new=malloc(sizeof(Node));
	new->x=value;
	if(Top==NULL)
		new->next=NULL;
	else
		new->next=Top;
	Top=new;
}

et* treePop()
{
	et *ele=NULL;
	if(Top==NULL)
		printf("Stack Empty!!!\n");
	else
	{
		Node *temp=Top;
		Top=temp->next;
		ele=temp->x;
		free(temp);
	}
	return ele;
}

void preorder(et* t)
{
	if(t!=NULL)
	{
		printf("%c",t->value);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(et* t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%c",t->value);
		inorder(t->right);
	}
}

void postorder(et* t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%c",t->value);
	}
}

int isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	return 0;
} 

et* newNode(int v)
{
	et* temp = (et*)malloc(sizeof(et));
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}

et* constructTree(char postfix[])
{
	et *t, *t1, *t2;
	for (int i=0; i<strlen(postfix); i++)
	{
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			treepush(t);
		} 
		else // operator
		{
			t = newNode(postfix[i]);
			t1 = treePop(); // Remove Top
			t2 = treePop();
			t->right = t1; // make them children
			t->left = t2;
			treepush(t); // Add this subexpression to stack
		}
	} 
	t = treePop();
	return t;
}

