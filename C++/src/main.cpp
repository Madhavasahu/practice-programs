//============================================================================
// Name        : Basic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "basicClass.h"
using namespace std;

int main() {
	Test test=2;
	test.printData();
	test.setData();
	Test test2(test);
	test2.printData();
	cout<<"the sum is "<<test.add()<<endl;;
	return 0;
}
