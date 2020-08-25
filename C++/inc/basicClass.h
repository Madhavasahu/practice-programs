/*
 * basic class.h
 *
 *  Created on: Apr 17, 2020
 *      Author: Madhava
 */

#ifndef BASICCLASS_H_
#define BASICCLASS_H_
#include <iostream>
using namespace std;
class Test{
private:
	int a;
	int b;
public:
	Test(void);
	Test(int a,int b=200);
	Test(const Test &test);
	void setData(void);
	void printData(void);
	int add(void);
};

#endif /* BASICCLASS_H_ */
