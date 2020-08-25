//============================================================================
// Name        : constKeyword.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	static int aa; //This static value cant be initialized here. It has to be outside of the class
	const int a{12}; //this value gets replaced, if we call the constructor and initialize.
					//the value initialized in constructor will the final value
public:
	Test();
	int returnA();
	static void printAA();
};
void Test::printAA(){
	cout<<aa<<endl; //cant access non-static member a in this function. but can access static aa function.
}
int Test::aa = 34;  //static variable defined here
Test::Test():a(12){}
int Test::returnA(void){
	return aa;
}
int main() {
	/*
	 * We cant assign a constant value to a non constant pointer but we do the reverse.
	 */

	Test test;
	cout<<test.returnA()<<endl;
	test.printAA();
	const int a = 10;
	const int b = 20;
	int c = 30;
	const int *ptr1 = &a; //ptr1 is pointer to constant int --> ptr can point to different var of same type,
						  // the value pointed by it , cannot be changed
	int const *ptr2 = &b; //same as above.
	int* const ptr3 = &c; //ptr3 is a constant pointer to int -->the pointer cant be changed
						 // but the value pointed by it can change.
	const int* const ptr4 = &a; //ptr4 is a constant pointer to constant int--> pointer and its value both cant change.
	cout<<*ptr4<<endl;
	//a = 1200;  //we can change a(if its not a const int) by a but not by pointer
	//ptr4 = &c; error
	//*ptr4 = 323;error
	ptr1 =  &b; //right
	//*ptr1 = 283; //wrong..writing to read only location pointed by ptr1
	cout<<*ptr1<<endl;
	//ptr3 = &a; //wrong.. ptr3 is read only pointer
	*ptr3 = 2323;  //but the value can be changed
	cout<<*ptr2<<endl;
	cout<<*ptr3<<endl;
	cout<<*ptr4<<endl;
	return 0;
}
