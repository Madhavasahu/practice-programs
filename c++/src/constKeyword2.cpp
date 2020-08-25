//============================================================================
// Name        : constKeyword2.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	string name;
public:
	Test();
	void setName(string name);
	string getName(void)const;
};
Test::Test(){
	name = "unknown";
}
void Test::setName(string name){
	this->name = name;
}
string Test::getName(void)const{ //cant change the instance variable value
	return name;
}
int main() {
	Test test;
	test.setName("Madhava");
	cout<<"My name is "<<test.getName()<<endl;;
	return 0;
}
