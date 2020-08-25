//============================================================================
// Name        : copyConstructor.cpp
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
	//Test(const Test &ref);
	void getA(void);
	void setA(int a){this->a = a;}
	Test& operator=(const Test &ref);
};
Test& Test::operator =(const Test &ref){
	cout<<"equality operator called"<<endl;
	a = ref.a;
	return *this;
}
Test::Test(){a = 100;}
// We can define copy constructor in any of the following way.
/*Test::Test(const Test &ref){
	cout<<"copy constructor called"<<endl;
	this->a = ref.a; //this pointer refers to the object upon which this function is called
}*/
/*Test::Test(const Test &ref){
	cout<<"copy constructor called"<<endl;
	a = ref.a;
}*/
/*Test::Test(const Test &ref):a(ref.a){ //using initializer list
	cout<<"copy constructor called"<<endl;
}*/
void Test::getA(void){
	cout<<a<<endl;
}
int main() {
	/* If we dont create a copy constructor , compiler creates one and copies
	 * member by member.
	 * If we create one, then it is initialized with what we will initialize it in the copy constructor.
	 * If its not initialized with any value in the user copy constructor, its shows garbage when printed
	 */
	Test t1;
	t1.getA();
	t1.setA(323);
	//Test t2(t1); //copy constructor is called here which is original copy constructor calling method
	//t2.getA();
 	Test t3;
 	t3 = t1; // = operator calls the copy constructor is called here because there is not definition for =
 				 //operator.
	t3.getA();
	return 0;
}
