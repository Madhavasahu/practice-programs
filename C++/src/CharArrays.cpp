//============================================================================
// Name        : CharArrays.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	char Array[] = "Madhava";
	char ptr[]{'1','2'};
	cout<<sizeof(Array)<<endl;
	cout<<sizeof(ptr)<<endl;
	for(uint32_t i=0;i<sizeof(ptr);i++)
		cout<<"ptr["<<i<<"] --> "<<(int)(&(ptr[i]))<<endl;; //special syntax to print the address of characters
	return 0;
}
