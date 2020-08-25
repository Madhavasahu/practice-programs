//============================================================================
// Name        : OverloadingSubscriptOperator.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define LEN 10
class Test{
private:
	int a[LEN]{}; //initialize with 10 0's
public:
	Test();
	Test(int,int);
	int& operator[](int);
	void print(int);
};
void Test::print(int index){
	cout<<a[index]<<endl;
}
Test::Test(){
	a[0]=0;
}
Test::Test(int index,int value){
	a[index] = value;
}
int& Test::operator [](int index){
	cout<<"[] called"<<endl;
	return a[index];
}
int main() {
	Test test(0,100);
	test.print(0);
	test[10] = 4554;
	test.print(10);
	return 0;
}
