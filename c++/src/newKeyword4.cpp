//============================================================================
// Name        : newKeyword4.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	int a;
public:
	Test();
	~Test();
};
Test::Test(void){
	cout<<"Constructor called on "<<this<<endl;
	a = 100;
}
Test::~Test(void){
	cout<<"Destructor called on "<<this<<endl;
}
int main() {
	Test *ptr2 = new Test[5];
	cout<<endl;
	delete [] ptr2;
	return 0;
}
