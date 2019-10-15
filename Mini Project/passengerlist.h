typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef struct
{
	char name[100];
	char gender;
	int age;
	char proof[50];
	char Class[50];
	char dest[50];
	char src[50];
	float cost;
}details;

struct Node
{
	 
	 details det;
	 Position Next;
	 Position Prev;

};


List CreateEmptylist()
{
	List t,h;
	h=(List)malloc(sizeof(struct Node));
	t=(List)malloc(sizeof(struct Node));
	h->Prev=NULL;
	h->Next=t;
	t->Prev=h;
	t->Next=NULL;
	return h;
}


int IsEmpty( List L )
{
	 return L->Next == NULL;
}
int Find(List L,char X[])
{
 	 int i=1;
	 Position P;
	 P = L->Next;
	 while( (P->Next) != NULL && strcmp(P->det.name,X)!=0 )
	 {
	 P = P->Next;
	 i++;	
	 }
	 
 	 if(P->Next == NULL)
 	 {
 	 	printf("No name found.\n");
 	 	return -1;
 	}
 	else
 	{

 	 printf("Name is in position %d\n",i);
 	 printf("Name\t\t: %s\n",P->det.name);
 	 printf("Gender\t\t: %c\n",P->det.gender);
 	 printf("Age\t\t: %d\n",P->det.age);
 	 printf("Proof\t\t: %s\n",P->det.proof);
 	 printf("Class\t\t: %s\n",P->det.Class);
 	 printf("Boarding point\t: %s\n",P->det.src);
 	 printf("Destination\t: %s\n",P->det.dest);
 	 return i;
	}

}


void addend(List L, details d)
{
 	Position Temp,P;
 	int i;
 	P=L;
 	while(P->Next!=NULL)
 		{
 			P=P->Next;
 		}
 	P=P->Prev;
 	Temp =(List) malloc( sizeof( struct Node ) );
 	Temp->det=d;
 	Temp->Next = P->Next;
 	Temp->Prev = P;
 	Temp->Next->Prev=Temp;
 	P->Next=Temp;

}

int Delete(List L, char X[])
{
	int i=0;
	if(L==NULL)
	{
		printf("\n%s is not present in the list", X);
		return 0;
	}
	Position P,temp;
	P = L->Next;
    while( P!= NULL && (strcmp(P->det.name,X)!=0) )
	{
	P = P->Next;	
	}
	if(P!=NULL)
	{
	temp = P;
	if(!strcmpi(temp->det.Class,"First"))
	{
		i=1;
	}
	else if (!strcmpi(temp->det.Class,"Second"))
	{
		i=2;
	}
	else if (!strcmpi(temp->det.Class,"Sleeper"))
	{
		i=3;
	}
	temp -> Next -> Prev = temp -> Prev;
	temp -> Prev -> Next = temp -> Next;
	free(temp);
	}
	else
	{
		printf("No name found.\n");
		return 0;
	}
	return i;

}

void disp(List h)
{
	List temp;
	temp=(List)malloc(sizeof(struct Node));
	temp=h->Next;
	printf("All records.\n");
	int i=1;
	while(temp->Next!=NULL)
	{
		printf("\n\nNo\t\t: %d\nName\t\t: %s\nBoarding station: %s\nDestination\t: %s\nClass\t\t: %s\n",i,temp->det.name,temp->det.src,temp->det.dest,temp->det.Class);
		temp=temp->Next;
		i++;
	}
	printf("\n");
}
