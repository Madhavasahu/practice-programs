/*
 * definitions.h
 *
 *  Created on: Apr 17, 2020
 *      Author: Madhava
 */

#ifndef DEFINITIONS_CPP_
#define DEFINITIONS_CPP_
#include "basicClass.h"

Test::Test(const Test &test){
	cout<<"copy constructor called"<<endl;
	a = test.a;
	b = test.b;
}
Test::Test():a(10),b(10){
	cout<<"Default constructor called"<<endl;
}
Test::Test(int a,int b):a(a),b(b){
	cout<<"parametrized constructor called"<<endl;
}
void Test::setData(void){
	cout<<"Enter the values::"<<endl;
	cin>>a>>b;
	this->a = a;
	this->b = b;
}
void Test::printData(void){
	cout<<"Printing the class data"<<endl;
	cout<<a<<" "<<b<<endl;
}
int Test::add(void){
	return a+b;
}
#endif /* DEFINITIONS_CPP_ */
