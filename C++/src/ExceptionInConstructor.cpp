//============================================================================
// Name        : ExceptionInConstructor.cpp
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
	Test(int);
	~Test();
};
Test::~Test(){
	cout<<"destructor called"<<endl;
}
Test::Test(int a){
	this->a = a;
	if(a == 0)
		throw a;
	cout<<"value of a "<<a<<endl;
}

int main() {
	try{
	Test test(0);
	}catch(int &ref){
		cout<<"error"<<endl;
	}
	return 0;
}
