//============================================================================
// Name        : OverloadingDereferenceOperator.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test{
private:
	int real;
	int img;
public:
	Test();
	Test(int,int);
	friend ostream& operator<<(ostream&, const Test&);
	Test operator*()const;
	Test& operator++(int);
	Test& operator++();
	Test& operator=(const Test& test);
};
Test& Test::operator=(const Test &test){
	if(this != &test){
		real = test.real;
	}
	return *this;
}
Test& Test::operator++(int a){
	real++;
	return *this;
}
Test& Test::operator++(void){
	++real;
	return *this;
}
Test::Test(){
	real = 0;
	img  = 0;
}
Test::Test(int real,int imaginary):real(real),img(imaginary){

}

/*ostream& operator<<(ostream &out, const Test &test){ //You will get an error if we add const keyword at the end. because
													//this function is not a member of the class. We add const to stop modify class instances
												 //since this function is not at all from any class, we get a error, if we add const at the tail.
	out<<"ID is "<<test.id;
	return out;
}*/
ostream& operator<<(ostream& out, const Test& test){
	out<<test.real;
	return out;
}
Test Test::operator*(void)const{
	cout<<"* called"<<endl;
	return Test(real,-img);
}
int main() {
	Test test(10,2);
	cout<<*test<<endl;
	test++;
	cout<<test<<endl;
	++test;
	cout<<test<<endl;
	Test test2;
	test2 = test;
	cout<<test2<<endl;
	return 0;
}
