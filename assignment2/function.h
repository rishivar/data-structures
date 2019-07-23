#include<stdio.h>
#include<stdlib.h>


typedef struct poly
{
	int coeff;
	int order;
	struct poly *next;
}node;

node* create()
{
	node *h;
	h = (node*)malloc(sizeof(node));
	h->next = NULL;
	return h;
}

void insert(node *hd,int c,int o)
{
	node *p,*t;
	p=(node*)malloc(sizeof(node));
	p->coeff=c;
	p->order=o;
	t=hd;
	while(t->next!=NULL)
		t = t->next;
	p->next =t->next;
	t->next = p;
}


void display(node *hd)
{
	node *tmp;
	tmp=hd->next;
	if(tmp==NULL)
		printf("Empty\n");
	while(tmp!=NULL)
	{
		if(tmp->order==0)
		{
			printf("%d   ",tmp->coeff);
		}
		else
			printf("%dx^%d + ",tmp->coeff,tmp->order);
            tmp=tmp->next;
	}
	printf("\b\b  \n");
}

void removedup(node *hd)
{
	node *p1,*p2,*dup;
	p1=hd->next;
	while(p1!=NULL&&p1->next!=NULL)
	{
		p2=p1;
		while(p2->next!=NULL)
		{
			if(p1->order==p2->next->order)
			{
				p1->coeff=p1->coeff+p2->next->coeff;
				dup=p2->next;
				p2->next=p2->next->next;
				free(dup);
			}
			else
				p2=p2->next;
		}
	p1=p1->next;
	}
}

node* multiply(node *p1,node *p2)
{
	node *ptr1,*ptr2,*ptr3;
	ptr3=(node*)malloc(sizeof(node));
	ptr3->next = NULL;
	int coeff,order;
	ptr1=p1->next;
	ptr2=p2->next;
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			coeff=ptr1->coeff*ptr2->coeff;
			order=ptr1->order+ptr2->order;
			insert(ptr3,coeff,order);
			ptr2=ptr2->next;
		}
		ptr2=p2->next;
		ptr1=ptr1->next;
	}
	removedup(ptr3);
    node *t,*p,*q;
    t = (node*)malloc(sizeof(node));
    p=ptr3->next;
    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
            if(p->order<q->order)
            {
                t->order=p->order;
                t->coeff=p->coeff;
                p->order=q->order;
                p->coeff=q->coeff;
                q->order=t->order;
                q->coeff=t->coeff;
            }
            q=q->next;
        }
        p=p->next;
    }
	return ptr3;
}

node* add(node *p1,node *p2)
{
	node *p,*q,*ptr3;
	ptr3=(node*)malloc(sizeof(node));
	ptr3->next = NULL;
	p=p1->next;
	q=p2->next;
	while(p!=NULL && q!=NULL)
	{
		if(p->order>q->order)
		{
			insert(ptr3,p->coeff,p->order);
			p=p->next;
		}
		else if(p->order<q->order)
		{
			insert(ptr3,q->coeff,q->order);
			q=q->next;
		}
		else
		{
			if(p->coeff+q->coeff!=0)
			{
				insert(ptr3,p->coeff+q->coeff,p->order);
			}
			p=p->next;
			q=q->next;
		}

	}
	while(p!=NULL)
	{
		insert(ptr3,p->coeff,p->order);
		p=p->next;
	}
	while(q!=NULL)
	{
		insert(ptr3,q->coeff,q->order);
		q=q->next;
	}
	return ptr3;
}
