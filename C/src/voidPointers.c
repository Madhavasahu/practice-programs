/*
 ============================================================================
 Name        : voidPointers.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int a;
	int b;
	int* c;
}A;
int main(void) {
int a=12;
char c='x';
char* d;
A aa={1662,13,&a};
A *sptr=&aa;
void *ptr = &a;
(*((int*)ptr))++;
printf("Accessing integer using VP %d\n",*((int*)ptr));
ptr= &c;   // Any datatype can be assigned to void pointer
d=ptr;     // void pointer can be assigned to any data type
printf("value of character C is %c\n",*((char*)ptr));
printf("value of character pointer D is %c\n",*d);
ptr =sptr;
printf("Accessing integer value using VP %d\n",((A *)ptr)->a); //accessing a member value using void pointer to struct type A
printf("Accessing integer pointer value using VP %d\n",*((A *)ptr)->c); //accessing a pointer to integer using void pointer to struct type A
}
