#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef struct avlnode *position; 

typedef struct avlnode *avltree;

struct avlnode
{
    char word[100];
    char tamil[100];
    char hindi[100];
    avltree left;
    avltree right;
    int height;
};

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

static int height(position p)
{
    if(p==NULL)
        return -1;
    else
        return p->height;
}

static position singlerotatewithleft(position k2)
{
    position k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    return k1;
}

static position singlerotatewithright(position k2)
{
    position k1;
    k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),k2->height)+1;
    return k1;
}

static position doublerotatewithleft(position k3)
{
    k3->left=singlerotatewithright(k3->left);
    printf("Double rotation with left was performed.\n");
    return singlerotatewithleft(k3);
}

static position doublerotatewithright(position k3)
{
    k3->right=singlerotatewithleft(k3->right);
        printf("Double rotation with right was performed.\n");
    return singlerotatewithright(k3);
}

avltree insert(char word[],char tamil[],char hindi[],avltree t)
{
    if(t==NULL)
    {
        t=malloc(sizeof(struct avlnode));
        if(t==NULL)
            printf("Error.\nOut of space.\n");
        else
        {
            strcpy(t->word,word);
            strcpy(t->tamil,tamil);
            strcpy(t->hindi,hindi);
            t->height=0;
            t->left=t->right=NULL;
        }
    }
    else if(strcmp(word,t->word)<0)
    {
        t->left=insert(word,tamil,hindi,t->left);
        if(height(t->left)-height(t->right)==2)
        {
            if(strcmp(word,t->left->word)<0)
            {
                t=singlerotatewithleft(t);
                printf("Single rotation with left was performed.\n");
            }
            else
                t=doublerotatewithleft(t);
        }
    }
    else if((strcmp(word,t->word)>0))
    {
        t->right=insert(word,tamil,hindi,t->right);
        if(height(t->right)-height(t->left)==2)
        {
            if(strcmp(word,t->right->word)>0)
            {
                t=singlerotatewithright(t);
                 printf("Single rotation with right was performed.\n");
            }
            else
                t=doublerotatewithright(t);
        }
    }
        
    t->height=max(height(t->left),height(t->right))+1;
    return t;
    
}


void inorder(avltree t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("WORD:%s\n",t->word);
        printf("Tamil:%s\n",t->tamil);
        printf("Hindi:%s\n",t->hindi);
        inorder(t->right);
    }
}
