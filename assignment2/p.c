#include<stdio.h>
#include<stdlib.h>
#include "prototype.h"

int main()
{
	int c,o;
	node *a,*b,*prod,*sum;
	a=create();
	printf("\nPolynomial Addition and Multiplication ");
	printf("\nEnter details of Polynomial A: ");
	while(1)
	{
		printf("\nEnter 99 to break");
		printf("\nEnter Coeff : ");
		scanf("%d",&c);
		if(c==99)
			break;
		printf("\nEnter Order : ");
		scanf("%d",&o);
		insert(a,c,o);
	}
	b=create();
	printf("\nEnter Details of Polynomial B: ");
	while(1)
	{
		printf("\nEnter 99 to break");
		printf("\nEnter Coeff : ");
		scanf("%d",&c);
		if(c==99)
			break;
		printf("\nEnter Order : ");
		scanf("%d",&o);
		insert(b,c,o);
	}
	printf("\nPolynomial 1  : ");
	display(a);
	printf("\nPolynomial 2  : ");
	display(b);
	prod=multiply(a,b);
	printf("\nProd of 1 & 2 : ");
    display(prod);
	sum=add(a,b);
	printf("\nSum of 1 &  2 : ");
	display(sum);
	printf("\n");
	return 0;
}
