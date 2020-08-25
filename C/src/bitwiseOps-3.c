/*
 ============================================================================
 Name        : bitwiseOps-3.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 0;
	printf("Enter a number: ");
	scanf("%d",&a);
	if (a & 1)
		printf("odd");
	else
		printf("even");
	return EXIT_SUCCESS;
}
