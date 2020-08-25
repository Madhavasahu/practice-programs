/*
 ============================================================================
 Name        : CStrings.c
 Author      : Madhava
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapUsingPointers(char **str1, char **str2) { //swapping strings using pointers
	char *temp = '\0';
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
char* my_strcpy(char *dst, char *src) { //user defined strcpy()
	char *copyString = dst;
	while (*src) {
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return copyString;
}
void swapUsingArrays(char *str1, char *str2) { //swaping strings using actual data
	char temp[10] = { '\0' };
	my_strcpy(temp, str2);
	my_strcpy(str2, str1);
	my_strcpy(str1, temp);
}
int main(void) {
	char str1[10] = "Madhava";
	char str2[10] = "Sahu";
	char *sstr1 = "abc";
	char *sstr2 = "cba";
	printf("Before swap s1:%s\n", str1);
	printf("Before swap s2:%s\n", str2);
	swapUsingArrays(str1, str2);
	printf("\nAfter swap s1:%s\n", str1);
	printf("After swap s2:%s\n", str2);
	printf("\nBefore swap sstr1:%s\n", sstr1);
	printf("Before swap sstr2:%s\n", sstr2);
	swapUsingPointers(&sstr1, &sstr2);
	printf("\nAfter swap sstr1:%s\n", sstr1);
	printf("After swap sstr2:%s\n", sstr2);

	printf("\nBefore copy str1 :%s\n", str1);
	printf("After copy str1 :%s", my_strcpy(str1, str2));

	return EXIT_SUCCESS;
}
