#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pq.h"


int main()
{
    
Emp temp;
int n;
printf("Enter number of entries: ");
scanf("%d",&n);
PQ *Q;
Q=createPQ(100);
for(int i=1;i<=n;i++)
{
insert(Q);
printf("\nThe Queue after insertion : \n\n");
for(int j=1;j<Q->size;j++)
{
printf("Position in Queue   : %d\n" , j); //I am printing the position in the array only for reference
printf("Name of Person      : %s\n" ,Q->arr[j].name);
printf("ID                  : %d\n" ,Q->arr[j].id);
printf("Salary              : %f\n\n",Q->arr[j].salary);
}
}

temp=deletemax(Q);

printf("Deleted entry details : \n");
printf("Name   : %s\n" ,temp.name);
printf("ID     : %d\n" ,temp.id);
printf("Salary : %f\n\n",temp.salary);

printf("\nThe Queue after deletion : \n\n");
for(int j=1;j<Q->size;j++)
{
printf("Position in Queue : %d\n" , j);
printf("Name              : %s\n" ,Q->arr[j].name);
printf("ID                : %d\n" ,Q->arr[j].id);
printf("Salary            : %f\n\n",Q->arr[j].salary);
}