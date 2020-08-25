//============================================================================
// Name        : VirtualBaseclasses.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Base{
private:
	int a;
public:
	Base(int a):a(a){cout<<"Base constructor called"<<endl;}
	void print(void){cout<<"Base print called"<<endl;}
	int getA(void){return a;}
};
class Child1:virtual public Base{   //here, the virtual keyword means create only one base object
	//The base object is shared between all objects in the inheritance tree and it is only constructed once.
public:
	Child1(int a):Base(a){cout<<"Child1 constructor called"<<endl;} //when creating Base object, this constructor to call Base
	//constructor is ignored
	void print(void){cout<<"Child1 print called"<<endl;}
};
class Child2:virtual public Base{
public:
	Child2(int a):Base(a){cout<<"Child2 constructor called"<<endl;}  //when creating Base object, this constructor to call Base
																	//constructor is ignored
	void print(void){cout<<"Child2 print called"<<endl;}
};
class Test{
public:
	Test(){cout<<"Test constructor called"<<endl;};
	void print(void){cout<<"Test print called"<<endl;}
};
class Child3:public Test{
public:
	Child3(){cout<<"Child3 constructor called"<<endl;};
	void print(void){cout<<"Child3 print called"<<endl;}
};
class Diamond: public Child1, public Child3, public Child2{  //here, this class constructor creates the Base class which is shared by child1 and child2.
	//this class is responsible for Base object creation
	//constructors are called from left to right.so first Child1 then Child3 then Child2
public:
	Diamond(int a):Base(a),Child1(a),Child2(a){cout<<"Diamond constructor called"<<endl;};
	void print(void){cout<<"Diamond print called"<<endl;}
};
int main() {
	Child1 obj(22222);
	cout<<obj.getA()<<endl;
	Diamond dia(2); //without virtual base classes the Base is created twice,once for child1, another time for child2
	dia.print();//without virtual base classes this is ambiguous to the compiler to which print to call.
				//i.e Child1's base print or Child2's base print
	cout<<dia.getA()<<endl;
	return 0;
}
