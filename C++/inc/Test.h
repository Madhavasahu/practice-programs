/*
 * Test.h
 *
 *  Created on: Apr 25, 2020
 *      Author: Madhava
 */

#ifndef TEST_H_
#define TEST_H_
#include<iostream>
#include <exception>
using namespace std;
class MyException:public exception{
private:
	string msg;
public:
	MyException(string);
	string returnMsg();
	virtual ~MyException();
	virtual const char* what()const throw();

};
class Test{
public:
	void somethingWrong(void);
};
#endif /* TEST_H_ */
