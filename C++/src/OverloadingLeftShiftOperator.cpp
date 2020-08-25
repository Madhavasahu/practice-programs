//============================================================================
// Name        : OverloadingLeftShiftOperator.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test{
private:
	int id;
public:
	Test(int);
	friend ostream& operator<<(ostream &out, const Test &test);
	friend istream& operator>>(istream &out, Test &test);
};

istream& operator>>(istream &in, Test &test){
	in>>test.id;
	return in;
}
Test::Test(int id):id(id){}
ostream& operator<<(ostream &out, const Test &test){ //You will get an error if we add const keyword at the end. because
													//this function is not a member of the class. We add const to stop modify class instances
												 //since this function is not at all from any class, we get a error, if we add const at the tail.
	out<<"ID is "<<test.id;
	return out;
}

int main() {
	Test test(2);
	cout<<test<<endl;
	cout<<"enter new ID"<<endl;
	cin>>test;
	cout<<test<<endl;
	return 0;
}
