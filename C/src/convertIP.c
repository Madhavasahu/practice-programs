/*
 ============================================================================
 Name        : convertIP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Here strtol takes three parameters
// 1.pointer to src string pointer
// 2.Address of char pointer - reference to the next character in string after the numerical value returned by strtol function
// 3.base for conversion
int main(void) {
    char IP[20] = {0};
	const char *str = IP;
	int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    int integerIP = 0;
    printf("Enter the IP: ");
    scanf("%[^\n]s",IP);
    printf("Given IP is: %s\n",IP);
	val1 = strtol(str,(char**)&str,10); //now IP points to .168.551.102
	str++; //incremented by 1 to point to 168.551.102
	val2 = strtol(str,(char**)&str,10); //now str points to .551.102
	str++; //incremented by 1 to point to 551.102
	val3 = strtol(str,(char**)&str,10); //now str points to .102
	str++; //incremented by 1 to point to 102
	val4 = strtol(str,(char**)&str,10); //point to null
	integerIP = (val1 * (int)(pow(256,3))) + (val2 * (int)(pow(256,2))) + (val3 * (int)(pow(256,1))) + (val4 * (int)(pow(256,0)));
	printf("Value is %p\n",(void*)integerIP);
	return EXIT_SUCCESS;
}
