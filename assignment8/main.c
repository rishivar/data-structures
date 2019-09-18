#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode
{
  char name[100];
  struct treenode *left;
  struct treenode *right;
}tree;

tree* findmin(tree *t)
{
  if(t==NULL)
    return NULL;
  else if (t->left==NULL)
    return t;
  else
    return findmin(t->left);
}

tree* insert(char name[],tree *t)
{
  if (t==NULL)
  {
    t=malloc(sizeof(tree));
    if (t==NULL)
    {
      printf("Out of Space\n");
    }
    else
    {
      strcpy(t->name,name);
      t->left=t->right=NULL;
    }
  }
  else if (strcmp(name,t->name)<0)
  {
    t->left=insert(name,t->left);
  }
  else if (strcmp(name,t->name)>0)
  {
    t->right=insert(name,t->right);
  }
  return t;
}

tree* delete(char name[],tree *t)
{
  tree *tmp;
  if (t==NULL)
  {
    printf("Element Not Found !!!\n");
  }
  else if (strcmp(name,t->name)<0)
  {
    t->left=delete(name,t->left);
  }
  else if (strcmp(name,t->name)>0)
  {
    t->right=delete(name,t->right);
  }
  else if (t->left && t->right)
  {
    tmp=findmin(t->right);
    strcpy(t->name,tmp->name);
    t->right=delete(t->name,t->right);
  }
  else
  {
    tmp=t;
    if (t->left==NULL)
    {
      t=t->right;
    }
    else if (t->right==NULL)
    {
      t=t->left;
    }
    free(tmp);
  }
  return t;
}

void inorder(tree* t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("%s\n",t->name);
    inorder(t->right);
  }
}

void printgc(char name[],tree *t)
{
  while(t!=NULL)
  {
    //printf("%s\n",t->name);
    if (strcmp(t->name,name)==0)
    {
      break;
    }
    else if(strcmp(name,t->name)<0)
      t=t->left;
    else if(strcmp(name,t->name)>0)
      t=t->right;
  }
  if(t==NULL)
  {
    printf("Name Not Found\n");
    return;
  }
  if(t->left)
  {
    if(t->left->left)
      printf("%s\n",t->left->left->name);
    if(t->left->right)
      printf("%s\n",t->left->right->name);
  }
  if(t->right)
  {
    if(t->right->left)
      printf("%s\n",t->right->left->name);
    if(t->right->right)
      printf("%s\n",t->right->right->name);
  }
}

tree* sibling(char name[],tree *t)
{
  if(t->right)
  {
    if(strcmp(t->right->name,name)==0)
    {
      if(t->left)
        return t->left;
      else
        return NULL;
    }
  }
  if(t->left)
  {
    if(strcmp(t->left->name,name)==0)
    {
      if(t->right)
        return t->right;
      else
        return NULL;
    }
  }
  if(strcmp(name,t->name)<0)
    t=sibling(name,t->left);
  else if(strcmp(name,t->name)>0)
    t=sibling(name,t->right);
  return t;
  
}

tree* findgp(char name[],tree *t)
{
  if(t->left)
  {
    if(t->left->left)
      if(strcmp(t->left->left->name,name)==0)
        return t;
    if(t->left->right)
      if(strcmp(t->left->right->name,name)==0)
        return t;
  }
  if(t->right)
  {
    if(t->right->left)
      if(strcmp(t->right->left->name,name)==0)
        return t;
    if(t->right->right)
      if(strcmp(t->right->right->name,name)==0)
        return t;
  }
  if(1)
  {
    if(strcmp(name,t->name)<0)
    {
      t=findgp(name,t->left);
      return t;
    }
    else if(strcmp(name,t->name)>0)
    {
      t=findgp(name,t->right);
      return t;
    }
  }
  return t;
}

int main()
{
  int ch=0;
  char name[100];
  tree *bst=NULL;
  scanf("%d",&n);
  names[] = { Kumar, Anusha, Ram, Charan, Mohan, Karthika, Chitra, Lakshmi, Abishek, Swetha, Tarun, Sanjana };
  for (int i = 0; i < 12; ++i)
  {
    bst=insert(names[i],bst);
  }

  printf("\nTree : \n");
  inorder(bst);
  printf("\n");
  
  while(ch<2)
  {
    tree *gp;
    printf("\nEnter name of Granchild : ");
    scanf("%s",name);
    gp=findgp(name,bst);
    if(gp!=NULL)
    {
      printf("%s\n",gp->name);
    }
    else
    {
      printf("Not Found \n");
    }
    ch++;
  }

  ch=0;
  while(ch<1)
  {
    printf("\nEnter name of GrandParent : ");
    scanf("%s",name);
    printgc(name,bst);
    ch++;
  }
  ch=0;
  while(ch<2)
  {
    tree *sib;
    printf("\nEnter name of Sibling : ");
    scanf("%s",name);
    sib=sibling(name,bst);
    if(sib!=NULL)
    {
      printf("%s\n", sib->name);
    }
    else
    {
      printf("No Sibling \n");
    }
    ch++;
  }

  printf("\nEnter name to delete : ");
  scanf("%s",name);
  bst=delete(name,bst);
  printf("\nTree : \n");
  inorder(bst);
  printf("\n");
  return 0;
}
