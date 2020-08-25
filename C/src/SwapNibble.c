/*
 ============================================================================
 Name        : SwapNibble.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned char value=100;
	unsigned char swappedValue, tempa,tempb;
	tempa = (value ) << 4;
	printf("tempa is %d\n",tempa);
	tempb = (value ) >> 4;
	printf("tempb is %d\n",tempb);
	swappedValue = tempa | tempb;
	printf("swapped value is %d\n",swappedValue);
	return EXIT_SUCCESS;
}
