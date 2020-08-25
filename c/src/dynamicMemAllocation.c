/*
 ============================================================================
 Name        : dynamicMemAllocation.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *ptr = 0;
	int size = 0;
	printf("Enter the no.of elements");
	scanf("%d", &size);
	ptr = (int*) malloc(size * sizeof(int));
	if(ptr == NULL)
		exit(1);
	for (int i = 0; i < size; i++) {
		printf("Enter element %d :", i);
		scanf("%d", &ptr[i]);
	}
	for (int i = 0; i < size; i++) {
		printf("Element %d is %d\n", i, ptr[i]);
	}
}
