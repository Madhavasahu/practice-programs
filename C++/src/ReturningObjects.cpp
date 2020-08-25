//============================================================================
// Name        : ReturningObjects.cpp
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
	void getA();
	Test(const Test&);
	//Test& returNRef();
	static Test* returnPtr();
	static Test returnCopy();

 };
void Test::getA(void){
	cout<<"value of a is "<<a<<endl;
}

Test::Test(const Test&test){
	cout<<"copy constructor called"<<endl;
	a = test.a;
}
Test::Test(){
	cout<<"constructor called"<<endl;
	a = 100;
}
Test::~Test(){
	cout<<"destructor called"<<endl;
}
/*Test& Test::returNRef(){
	Test test;
	return test;
}*/
Test* Test::returnPtr(){
	cout<<"return ptr"<<endl;
	Test *test = new Test();
	return test;
}
Test Test::returnCopy(){
	cout<<"return copy"<<endl;
	return Test();
}
int main() {
	Test test = Test::returnCopy(); //using static function we can call them without object and with :: operator
	Test *ptr = Test::returnPtr();
	ptr->getA();
	delete ptr; //calls the destructor
 	return 0;
}
