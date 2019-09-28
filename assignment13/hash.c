#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
struct Record
{
 char data[100];
 struct Record *link;
};

void insert(char *id, struct Record *hash_table[]);
int search_element(char *key, struct Record *hash_table[]);
void remove_record(char *key, struct Record *hash_table[]);
void show(struct Record *hash_table[]);
int hash_function(char *key);

int main()
{
 struct Record *hash_table[MAX];
 int count;
 char key[20]; 
 int option;
 char id[20];

 for(count = 0; count <= MAX - 1; count++)
 {
 hash_table[count] = NULL;
 }
 while(1)
 {
 printf("\n1. Insert a Record in Hash Table\n");
 printf("2. Search for a Record\n");
 printf("3. Delete a Record\n");
 printf("4. Show Hash Table\n");
 printf("5. Quit\n");
 printf("Enter your option : ");
 scanf("%d",&option);
 printf("\n");
 switch(option)
 {
 case 1:
 printf("Enter the string : ");
 scanf("%s", id);
 insert(id, hash_table);
 break;
 case 2:
 printf("Enter the element to search:\t");
 scanf("%s", key);
 count = search_element(key, hash_table);
 if(count == -1)
 { 
 printf("Element Not Found\n");
 }
 else
 {
 printf("Element Found in Chain:\t%d\n", count);
 }
 break;
 case 3:
 printf("Enter the element to delete:\t");
 scanf("%s", key);
 remove_record(key, hash_table);
 break;
 case 4:
 show(hash_table);
 break;
 case 5:
 exit(1);
 }
 }
 return 0;
}

void insert(char *id, struct Record *hash_table[])
{
 char key[20];
 int h;
 struct Record *temp;
 strcpy(key,id);
 if(search_element(key, hash_table) != -1)
 {
 printf("Duplicate Key\n");
 return;
 }
 h = hash_function(key);
 temp = malloc(sizeof(struct Record));
 strcpy(temp->data, id);
 temp->link = hash_table[h];
 hash_table[h] = temp;
}

void show(struct Record *hash_table[])
{
 int count;
 struct Record *ptr;
 for(count = 0; count < MAX; count++)
 {
 printf("\n[%3d]", count); 
 if(hash_table[count] != NULL)
 {
 	ptr = hash_table[count];
	 while(ptr->link != NULL)
	 {
	 	printf("%s -> ", ptr->data);
	 	ptr=ptr->link;
	 }
	 printf("%s", ptr->data);
 }
 }
 printf("\n");
}

int search_element(char key[], struct Record *hash_table[])
{
 int h;
 struct Record *ptr;
 h = hash_function(key);
 ptr = hash_table[h];
 while(ptr != NULL)
 {
 if(!strcmp(ptr->data, key))
 {
 return h;
 }
 ptr = ptr->link;
 }
 return -1;
}

void remove_record(char *key, struct Record *hash_table[])
{
 int h;
 struct Record *temp, *ptr;
 h = hash_function(key);
 if(hash_table[h]==NULL)
 {
 printf("Key %s Not Found\n", key);
 return;
 }
 if(!strcmp(hash_table[h]->data, key))
 {
 temp = hash_table[h];
 hash_table[h] = hash_table[h]->link;
 free(temp);
 return;
 } 
 ptr = hash_table[h];
 while(ptr->link != NULL)
 {
 if(!strcmp(ptr->link->data, key))
 {
 temp = ptr->link;
 ptr->link = temp->link;
 free(temp);
 return;
 }
 ptr = ptr->link;
 }
 printf("Key %s Not Found\n", key);
}

int hash_function(char *key)
{
	int hashval = 0;
 	for(int i = 0; i<strlen(key); i++)
 	{
 		hashval += (key[i])*(i + 1);
 	}
 	return hashval%2069;
} 