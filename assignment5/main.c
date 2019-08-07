#include <stdio.h>
#include "queue.h"

int main()
{
    node *h1=(node*)malloc(sizeof(node));
    node *r1=h1;
    node *h2=(node*)malloc(sizeof(node));
    node *r2=h2;
    create(h1,r1,h2,r2);
    return 0;
}
