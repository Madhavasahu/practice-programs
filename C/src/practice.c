/*
 ============================================================================
 Name        : practice.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct __attribute__((__packed__))Test{ //stops structure padding
	int a;
	struct Test *next;
};
int main(void) {
	int *ptr = NULL;

	struct Test test;
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	printf("%d",sizeof(test));
	return EXIT_SUCCESS;
}
