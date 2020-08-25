//============================================================================
// Name        : VirtualFunctions.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Animal{
public:
	virtual void speak(void) = 0;
	virtual void run(void) = 0;
	virtual ~Animal(){}
};
class Dog:public Animal{
public:
	virtual void speak(void){
		cout<<"I am dog"<<endl;
	}
	virtual void run(void){
		cout<<"I am a Dog and I am running"<<endl;
	}
};
void test(Animal &test){
	cout<<endl;
	test.run();
	test.speak();
}
int main() {
	//Animal animal ---> compile error to create object for abstract class
	Dog dog;
	Animal &ref = dog;  //but can create reference to it
	Animal *ptr = &dog; //can create pointer to it
	ptr->speak();
 	ref.run();
 	test(ref); //can pass reference
 	test(dog); //can pass child object and access it as reference

 	cout<<"using array"<<endl;
 	Animal *arr[5] = {&dog};
 	arr[0]->run();
 	arr[0]->speak();
 	return 0;
}
