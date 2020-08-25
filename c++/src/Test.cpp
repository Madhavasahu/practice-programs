/*
 * Test.cpp
 *
 *  Created on: Apr 25, 2020
 *      Author: Madhava
 */

#include "Test.h"

MyException::MyException(string msg) {
	cout<<"constructor called"<<endl;
	this->msg = msg;
	// TODO Auto-generated constructor stub

}
string MyException::returnMsg() {
	return msg;
}
MyException::~MyException() {
	cout<<"destructor called"<<endl;
	// TODO Auto-generated destructor stub
}
const char* MyException::what(void)const throw(){
	return "Something bad happened"; //giving static message
}
void Test::somethingWrong(void){
	bool error = true;
	if(error)
		throw MyException("something went bad"); //giving dynamic message through constructor
}
