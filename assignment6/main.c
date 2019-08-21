#include "tree.h"

int main()
{
	int ch;
	do
	{
		char exp[100];
		printf("\nEnter Expression : ");
		scanf("%s",exp);
		infixToPostfix(exp);
		et* r = constructTree(exp);
		printf("Preorder : ");
		preorder(r);
		printf("\nInorder : ");
		inorder(r);
		printf("\nPostorder : ");
		postorder(r);
		printf("\n\n");
		printf("Do you want to continue? (1.Yes, 2.No)");
		scanf("%d",&ch);
	}while(ch!=2);
	return 0;
} 
