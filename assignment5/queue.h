#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mynode
{
     char pid[5];
     float bus_time;
     struct mynode *next;
}node;

void avgcalc(float wt1, float wt2, int c1, int c2)
{
    float av1=wt1/c1;
    float av2=wt2/c2;
    printf("\nAverage Waiting Time A: %f \nAverage Waiting Time B: %f \n", av1, av2);
}

void create(node *h1, node *r1, node *h2, node *r2)
{
    node *ht1=h1,*ht2=h2,*t1,*t2;
    int ch1=1, ch2=1;
    float wt1=0;
    float wt2=0;
    char id[5];
    float bt;
    int c1=0;
    int c2=0;
    t1=(node*)malloc(sizeof(node));
    t2=(node*)malloc(sizeof(node));
    while(ch2)
    {
        printf("\nEnter ID: ");
        scanf("%s",id);
        printf("\nEnter burst time: ");
        scanf("%f",&bt);
        if(ch1==1)
        {
            ht1->next=t1;
            ht1=t1;
            strcpy(t1->pid,id);
            t1->bus_time=bt;
            wt1+=bt;
            ch1+=1;
            c1+=1;
            continue;
        }
        else if(ch1==2)
        {
            ht2->next=t2;
            ht2=t2;
            strcpy(t2->pid,id);
            t2->bus_time=bt;
            wt2+=bt;
            ch1+=1;
            c2+=0;
            continue;
        }
        else
        {
            if(wt2<wt1)
            {
                ht2->next=t1;
                ht2=t1;
                strcpy(t2->pid,id);
                t2->bus_time=bt;
                wt2+=bt;
                c2+=1;
            }
            else
            {
                ht1->next=t1;
                ht1=t1;
                strcpy(t1->pid,id);
                t1->bus_time=bt;
                wt1+=bt;
                c1+=1;
            }
        }
        printf("\nWait Time A: %f and Wait Time B: %f", wt1,wt2);
        printf("\nEnter 0 to exit: ");
        scanf("%d",&ch2);
    }
    t1->next=NULL;
    r1=t1;
    t2->next=NULL;
    r2=t2;
    avgcalc(wt1,wt2,c1,c2);
}



