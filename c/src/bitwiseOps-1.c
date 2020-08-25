/*
 ============================================================================
 Name        : bitwiseOps-1.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(void) {
	char cd = 'P';
	cd = cd | ' ';  //changes any letter to lower case
	cd = cd & '_'; //changes any letter to upper case
	printf("%c",cd);
	return EXIT_SUCCESS;
}
