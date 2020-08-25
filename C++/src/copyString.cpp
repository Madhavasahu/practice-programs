//============================================================================
// Name        : copyString.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	const char *ptr1 = "madhava";
	char *ptr3=0;
	char *ptr2 = new char[strlen(ptr1)+1];
	ptr3 = ptr2;
	while(*ptr1){
		*ptr2 = *ptr1;
		ptr2++;
		ptr1++;
	}
	*ptr2 = '\0';
	printf("%s",ptr3);
	return 0;
}
