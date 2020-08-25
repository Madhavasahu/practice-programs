/*
 ============================================================================
 Name        : bitwiseOps-2.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num = 0;
	int i = 0;
	printf("Enter a decimal number ");
	scanf("%d",&num);
	for(i=0; i<32; i++){
		printf("%d ",((num <<i) & (1<<31)) ? 1:0);
	}
	return EXIT_SUCCESS;
}
