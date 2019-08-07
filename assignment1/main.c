#include<stdio.h>
#include"prototype.h"
int main()
{	
	struct student list[10];
	int n,op,cont;
	printf("Enter number of Student records to add initially: ");
	scanf("%d",&n);
	create(list,n);
	do
	{
	printf("\nChoose \n1.Insert at Beginning\n2.Insert at End\n3.Insert\n4.Search\n5.Delete\n6.Display all\n7.Display Before And After\n");
	scanf("%d",&op);
	switch(op)
	{	case 1: insertbeg(list,n);
				n++;
				break;
		case 2: insertend(list,n);
				n++;
				break;
		case 3: insert(list,n);
				n++;
				break;
		case 4:search(list,n);
				break;
		case 5: delete(list,n);
				n--;
				break;
		case 6: dispall(list,n);
				break;
		case 7: dispnext(list,n);
				break;
	}
	printf("DO YOU WANT TO CONTINUE?\n 1. YES\n2. NO");
	scanf("%d",&cont);
	}while(cont==1);
	return(0);
}	
