#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"


int main()
{
	List L;
 	Position P;
 	int i;
 	L = malloc( sizeof( struct Node ) );
 	L->Next = NULL;
 	L->Prev=NULL;
 	P = L;
 	char name[30];
 	do
 	{
 	printf("\n 1. Insert Student name at front");
 	printf("\n 2. Insert Student name at end");
 	printf("\n 3. Insert After a given record");
 	printf("\n 4. Search for student");
 	printf("\n 5. Delete a given student");
 	printf("\n 6. Display all student details");
 	printf("\n 7. Display the students in alphabetical order \n");
 	scanf("%d",&i);
 	if(i==1)
 	{
 		printf("\n Enter Student Name to insert at front: ");
 		scanf("%s",name);
 		addbeg(L,name);

 	}
 	else if(i==2)
 	{
 		printf("\n Enter Student Name to insert at rear: ");
 		scanf("%s",name);
		Create(name, L,P);		 		
 	}
 	else if(i==3)
 	{
 		int loc;
 		printf("\n Enter position to add after the record: ");
 		scanf("%d",&loc);
 		printf("\n Enter Student name to insert: ");
 		scanf("%s",name);
 		addafter(L,name,loc);
 	}
 	else if(i==4)
 	{
 		printf("\n Enter name of student to find position: ");
 		scanf("%s",name);
 		Find(name, L);
 	}
 	else if(i==5)
 	{
 		printf("\n Enter name of student to delete: ");
 		scanf("%s",name);
 		delete(L, name);
 	}
 	else if(i==6)
 	{
 		PrintList(L);
 	}
 	else if(i==7)
 	{
 		PrintAlph(L);
 	}
 	printf("\nDo you want to continue (1. Yes / 2. No)");
 	scanf("%d",&i);
 	}while(i!=2);
 	return 0;

}

