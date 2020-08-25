/*
 ============================================================================
 Name        : pointerToFunctions.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void (*fptr)(int *a, int *b);
void utilityFunc(void (*fptr)(int *a, int *b), int *a, int *b);
void swap(int *a, int *b);
int main(void) {
	int a = 10;
	int b = 100;
	printf("Before swap %d %d\n", a, b);
	utilityFunc(swap, &a, &b);
	printf("After swap %d %d", a, b);
}
void utilityFunc(void (*fptr)(int *a, int *b), int *a, int *b) {
	fptr(a, b);
}
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
