#include<stdio.h>
#include "stack.h"

int main()
{ 
  char exp[100];
  int ch;
  do
  {
  		printf("Enter the Expression :");
  		scanf(" %s",exp);
  		if (areParenthesisBalanced(exp))
  			printf("Balanced \n");
  		else
  		{
  			printf("Not Balanced \nCan't be Operated\n");
  			exit(0);
  		}
  		printf("The Postfix Expression is :");
  		infixToPostfix(exp);
  		printf("\nEvaluation of Postfix Expression :%f\n",evaluatePostfix(exp));
  		printf("Do you want to Continue (1. Yes/ 2.No) ?\n");
  		scanf("%d",&ch);
  		}while(ch==1);
  		return 0;
  }
