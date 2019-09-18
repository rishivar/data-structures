#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include “avl.h”

avltree searchword(char word[],avltree t)
{
    while(t!=NULL)
    {
        if(strcmp(word,t->word)==0)
            return t;
        else if(strcmp(word,t->word)<1)
            return searchword(word,t->left);
        else
            return searchword(word,t->right);
    }
    if(t==NULL)
        return NULL;
}

int main()
{

        avltree t=NULL, temp;
        char s[20];
        char word[15][40]={"Algorithm","Animation","Bit","Browser","Clipboard","Compiler","Digital","Printer","Encoding","Gateway","Hardware","Internet","Memory","Monitor","Password"};
		char hindi[15][40]={"कलनविधि","एनीमेशन","बिट","ब्राउज़र","कर्तनपट्ट","संकलक","डिजिटल","छापनेवालायंत्र","संकेतीकरण","प्रवेशद्वार","हार्डवेयर","अंतराजाल","याददाश्त","मॉनिटर","संकेत-शब्द"};
		char tam[15][40]={"நெறிமுறை","அசைவூட்டம்","நுண்மி","உலாவி","மறைப்பலகை","தொகுப்பி","எண்மின்","அச்சுப்பொறி","குறியாக்கம்","நுழைவாயில்","வன்பொருள்","இணையம்","நினைவகம்","கணித்திரை","கடவுச்சொல்"};

		for(int i=0; i<15;i++)
		{	
	       	printf("Inserting %s in tree \n\n", word[i]);
        	t=insert(word[i],tam[i],hindi[i],t);
        	printf("\n");
        	inorder(t);
        	printf("\n");
        }

        int ch = 1;
        do
        {
            printf("Enter word to find: ");
            scanf("%s", s);
            temp=searchword(s,t);
            if(temp==NULL)
                printf("No word found.\n");
            else
                printf("Word:%s\nTamil meaning:%s\nHindi meaning:%s\n",temp->word,temp->tamil,temp->hindi);
            printf("Do you want to continue?(1.Yes/ 2.No)");
            scanf("%d", &ch);
        }while(ch==1);
    
    
        return 0;
    
}