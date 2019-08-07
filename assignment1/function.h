#include<stdio.h>
#include<string.h>

struct student
{	int Regno;
	char Name[20];
	int Marks[5];	
};
int i,j;
void dispall(struct student list[],int n)
{	
	for(i=0;i<n;i++)
	{	printf("\nStudent %d\n",(i+1));
		printf("\nName : %s\n",list[i].Name);
		printf("\nRegno: %d\n",list[i].Regno);
		printf("\nMarks\n");
		for(j=0;j<5;j++)
		{	printf("%d\n",list[i].Marks[j]);
		}
	}
}

void dispnext(struct student list[],int n)
{	printf("\nEnter position of student in list to get records before and after\n");
	int i,j;
	scanf("%d",&i);
	printf("\nStudent Before\n");
	printf("\nName : %s\n",list[i-1].Name);
	printf("\nRegno: %d\n",list[i-1].Regno);
	printf("\nMarks\n");
	for(j=0;j<5;j++)
		printf("%d\n",list[i-1].Marks[j]);
	printf("\nStudent After\n");
	printf("\nName : %s\n",list[i+1].Name);
	printf("\nRegno: %d\n",list[i+1].Regno);
	printf("\nMarks\n");
	for(j=0;j<5;j++)
		printf("%d\n",list[i+1].Marks[j]);
}

void search(struct student list[],int n)
{	printf("Enter name of student to search");
	char nm[20];
	scanf("%s",nm);
	for(int i=0;i<n;i++)
	{	if(strcmp(nm,list[i].Name)==0)
		{	printf("\nName : %s\n",list[i].Name);
			printf("\nRegno: %d\n",list[i].Regno);
			printf("\nMarks\n");
			for(int j=0;j<5;j++)
				printf("%d\n",list[i].Marks[j]);
		}
	}
}

void insertend(struct student *list,int n)
{	printf("\nEnter Student Details to Add at end\n");
	printf("\nEnter Student Regno: ");
	scanf("%d",&(list+n)->Regno);
	printf("\nEnter Student Name: ");
	scanf("%s",(list+n)->Name); 
	printf("\nMarks\n");
	for(int i=0;i<5;i++)
	{	scanf("%d",&(list+n)->Marks[i]);
	}
}

void create(struct student *list,int n)
{	for(int i=0;i<n;i++)
	{	printf("\nEnter Student %d Details\n",(i+1));
		printf("\nEnter Student Regno: ");
		scanf("%d",&(list+i)->Regno);
		printf("\nEnter Student Name: ");
		scanf("%s",(list+i)->Name);
		printf("\nEnter Marks: \n");
		for(j=0;j<5;j++)
			{	scanf("%d",&(list+i)->Marks[j]);
			}
	}
}

void delete(struct student *list, int n)
{	printf("\nEnter Student Name to Delete\n");
	char nm[20];
	scanf("%s",nm);
	for(int i=0;i<n;i++)
	{	if(strcmp((list+i)->Name,nm)==0)
		{	for(int j=i;j<n-1;j++)
			{	*(list+j)=*(list+(j+1));
			}
		}
	}
}

void insert(struct student *list,int n)
{	printf("\nEnter Reg Number to Add Record After it\n");
	int reg,j,pos;
	scanf("%d",&reg);
	for(int i=0;i<n;i++)
	{	if((list+i)->Regno==reg)
		{	for(j=n;j>i+1;j--)
			{	*(list+j)=*(list+(j-1));
			}
			pos=i+1;
		}
	}
	printf("\nEnter Student Details\n");
	printf("\nEnter Student Regno: ");
	scanf("%d",&(list+pos)->Regno);
	printf("\nEnter Student Name: \n");
	scanf("%s",(list+pos)->Name); 
	printf("\nMarks: \n");
	for(i=0;i<5;i++)
	{	scanf("%d",&(list+pos)->Marks[i]);
	}
}

void insertbeg(struct student *list,int n)
{	
	for(int i=n;i>0;i--)
	{	*(list+i)=*(list+(i-1));
	}
	printf("\nEnter Student Regno: ");
	scanf("%d",&(list+0)->Regno);
	printf("\nEnter Student Name: \n");
	scanf("%s",(list+0)->Name); 
	printf("\nMarks: \n");
	for(i=0;i<5;i++)
	{	scanf("%d",&(list+0)->Marks[i]);
	}
}
