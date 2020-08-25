//============================================================================
// Name        : constructors.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test {
private:
	int a;
	int b;
public:
	void setTest(int a, int b);
	int getA();
	int getB();
	Test(void);
	void speak();
	void run();
	~Test(void);
};
int Test::getA() {
	return a;
}
int Test::getB() {
	return b;
}
void Test::setTest(int a, int b) {
	this->a = a;
	this->b = b;
}
Test::~Test(void) {
	cout << "Test destructor called" << endl;
}
Test::Test(void) {
	cout << "Test constructor called" << endl;
	a = 10;
	b = 10;
}
void Test::run() {
	cout << "I am running" << endl;
}
void Test::speak() {
	cout << "I am speaking" << endl;
}
int main() {
	cout << "Main program called" << endl;
	{
		//static Test test; //goes out of scope after main program ended
		Test test; // goes out of scope after the block ends
		test.run();
		test.speak();
	}

	Test test; //will not give any error, because it is outside of the scope
	int a = 0, b = 0;
	printf("default values are:: \n");
	cout << "a is " << test.getA() << endl;
	cout << "b is " << test.getB() << endl;
	cout << "Enter a " << endl;
	cin >> a;
	cout << "Enter b " << endl;
	cin >> b;
	test.setTest(a, b);
	cout << "a is " << test.getA() << endl;
	cout << "b is " << test.getB() << endl;
	cout << "Main program ended" << endl;
	return 0;
}
