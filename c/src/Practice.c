/*
 ============================================================================
 Name        : Practice.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned int num;
	int i;
	printf("Enter the decimal number");
	scanf ("%u", &num);
	for ( i = 0; i<32; i++)
	{
	printf ("%d", (num << i & 1 << 31 ) ? 1:0);
	}
}
