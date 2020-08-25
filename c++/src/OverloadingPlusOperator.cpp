//============================================================================
// Name        : OverloadingPlusOperator.cpp
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
	Test(void);
	Test(int);
	void print(void);
	friend ostream& operator<<(ostream &out, const Test &test);
	friend Test operator+(const Test &test2, const Test &test1);
};
ostream& operator<<(ostream &out, const Test &test){
	out<<test.a;
	return out;
}
Test operator+(const Test &test2, const Test &test1){
	return Test(test2.a + test1.a);
}
void Test::print(void){cout<<a<<endl;}
Test::Test(){a=0;}
Test::Test(int a):a(a){}
int main() {
	Test test(2);
	test.print();
	Test test2(34);
	Test test3 = test +test2;
	cout<<test3<<endl;
	return 0;
}
