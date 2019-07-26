#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int IsEmpty( List L );
void Find( char X[], List L );;
void Create( char X[], List L, Position P );
void PrintList( const List L );
void addbeg(List L, char X[]);
void addafter(List L, char X[], int Location);
void delete(List L, char X[]);
void PrintAlph(const List L);
