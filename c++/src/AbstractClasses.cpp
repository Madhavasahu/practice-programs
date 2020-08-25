//============================================================================
// Name        : AbstractClasses.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Base{
public:
	virtual void speak(void) = 0;
	virtual void run(void) = 0;
	virtual ~Base(void){}
};
void Base::run(void){                                  //we can provide default implementation to abstract classes
	cout<<"This is the default implemenation"<<endl;
}
class Derived: public Base{
public:
	virtual void speak(void){
		cout<<"I can speak English"<<endl;
	}
	/*virtual void run(void){
		cout<<"I can run fast"<<endl;
	}*/
};
class Derived2:public Derived{
public:
/*	virtual void speak(void){
		cout<<"I can speak French"<<endl;
	}*/
	virtual void run(void){
		//cout<<"I am a slow runner"<<endl;
		Base::run();    //need to use :: operator to call base version of run()
	}
};

int main() {
	Base *ptr = new Derived2;
	ptr->run();
	ptr->speak();
	delete ptr;
	return 0;
}
