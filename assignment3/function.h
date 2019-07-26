#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	 char name[30];
	 Position Next;
	 Position Prev;
};

int IsEmpty( List L )
{
	 return L->Next == NULL;
}

void Find( char X[], List L )
{
 	 int i=1;
	 Position P;
	 P = L->Next;
	 while( (P->Next) != NULL && strcmp(P->name,X)!=0 )
	 {
	 P = P->Next;
	 i++;	
	 }
 	 printf("number in position %d",i);
}

void Create( char X[], List L, Position P )
{
	Position Temp;
 	while(P->Next!=NULL)
 		P=P->Next;
 	Temp=malloc( sizeof( struct Node ) );
 	strcpy(Temp->name, X);
 	Temp->Next = NULL;
 	Temp->Prev = P;
 	P->Next = Temp;
}

void PrintList( const List L )
{
 	Position P = L;
 	if( IsEmpty( L ) )
    printf( "Empty list\n" );
    else
    {
    do
    {
    P = P->Next;
    printf( "%s ", P->name );
    } while( !(P->Next == NULL) );
    printf( "\n" );
    }
}

void addbeg(List L, char X[])
{
	Position Temp;
 	Temp=malloc( sizeof( struct Node ) );
 	strcpy(Temp->name, X);
 	Temp->Next = L->Next;
 	Temp->Prev = L;
 	L->Next=Temp;
}

void addafter(List L, char X[], int Location)
{
 	Position Temp,P;
 	int i;
 	P=L;
 	for (i=0;i<=Location;i++)
 	{
 	P=P->Next;
 	if(P==NULL)
 	{
 		printf("There are less than %d Elements", Location);
 		return;
 	}
 	}
 	P=P->Prev;
 	Temp = malloc( sizeof( struct Node ) );
 	strcpy(Temp->name, X);
 	Temp->Next = P->Next;
 	Temp->Prev = P;
 	Temp->Next->Prev=Temp;
 	P->Next=Temp;
}

void delete(List L, char X[])
{
	if(L==NULL)
	{
		printf("\n %s is not present in the list", X);
		return;
	}
	Position P,temp;
	P = L->Next;
    while( P!= NULL && (strcmp(P->name,X)!=0) )
	{
	P = P->Next;	
	}
	temp = P;
	temp -> Next -> Prev = temp -> Prev;
	temp -> Prev -> Next = temp -> Next;
	free(temp);
}


void PrintAlph(const List L)
{
	Position P = L;
 	if( IsEmpty( L ) )
    printf( "Empty list\n" );
    else
    {
    	Position A,B;
    	A = P->Next;
    	char temp[30];
    	while(A!=NULL)
    	{
    		B = A->Next;
    		while(B!=NULL)
    		{
    			if((strcmp(A->name,B->name)>0))
    			{
    				strcpy(temp,A->name);
    				strcpy(A->name,B->name);
    				strcpy(B->name,temp);
    			}
    			B = B->Next;
    		}
    		A = A->Next;
    	}
    }
    Position t = L;	
    do
    {
    t = t->Next;
    printf( "%s ", t->name );
    } while( !(t->Next == NULL) );
    printf( "\n" );
    	
}
