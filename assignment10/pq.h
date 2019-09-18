typedef struct Empl{
    char name[50];
    int id;
    float salary;
}Emp;

typedef struct PriorityQ
{
    int size;
    int capacity;
    Emp *arr;
}PQ;

PQ* createPQ(int max)
{
    PQ *Q;
    Q=(PQ*)malloc(sizeof(PQ));
    Q->capacity=max;
    Q->arr=(Emp*)malloc(sizeof(Emp)*max);
    strcpy(Q->arr[0].name,"No");
    Q->arr[0].id=0;
    Q->arr[0].salary=0.0;
    Q->size=1;
    return Q;
}

void insert(PQ *Q)
{
    int a;
    Emp temp;
    if(Q->size==Q->capacity)
    {
        return;
    }
    else
    {
        a=Q->size;
        Q->size++;
        printf("Enter the Name:\n");
        scanf("%s",Q->arr[a].name);
        printf("Enter the ID and Salary:\n");
        scanf("%d %f",&Q->arr[a].id,&Q->arr[a].salary);
        while(a!=1 && Q->arr[a].salary > Q->arr[a/2].salary)
        {
        
        temp=Q->arr[a];
        Q->arr[a]=Q->arr[a/2];
        Q->arr[a/2]=temp;
        a=a/2;
    
        }

        
    }
}

Emp deletemax(PQ *Q)
{
    int i,c;Emp temp,last,max;
    max=Q->arr[1];
    last=Q->arr[Q->size-1];
    Q->arr[1]=last;
    --Q->size;
for(int j=0;j<Q->size;j++)
{   
    for(i=1;(i*2)<=Q->size;i=c)
    {
    c=i*2;
    if(c!=Q->size && Q->arr[c+1].salary > Q->arr[c].salary)
        c++;
    if(Q->arr[i].salary < Q->arr[c].salary)
        {
            temp=Q->arr[i];
            Q->arr[i]=Q->arr[c];
            Q->arr[c]=temp;
        }
    }
}
return max;
}