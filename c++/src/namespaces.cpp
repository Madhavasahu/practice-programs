//============================================================================
// Name        : namespaces.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//constructors cannot be inherited
#include <iostream>
using namespace std;
class Animal{
private:
	int a;
public:
	void speak(void);
	Animal(int);
	Animal(void);
	void info(void);
};
void Animal::info(void){
	cout<<"a is "<<a<<endl;
}
Animal::Animal(void){
	cout<<"Animal default called"<<endl;
	a = 100;
}
void Animal::speak(void){
	cout<<"I'm a common animal"<<a<<endl;
}
Animal::Animal(int a):a(a){
	cout<<"Animal constructor called"<<endl;
}
class Cats:public Animal{
public:
	Cats(void);
	Cats(int);
	void speak(void);
};
Cats::Cats(int a):Animal(a){}
Cats::Cats(void){
	cout<<"Cats constructor called"<<endl;
}
void Cats::speak(void){
	cout<<"I'm a cat"<<endl;
}
class Tiger:public Cats{
public:
	Tiger(void);
	Tiger(int);
	void speak(void);
};
Tiger::Tiger(int a):Cats(a){}
Tiger::Tiger(void){
	cout<<"Tiger constructor called"<<endl;
}
void Tiger::speak(void){
	cout<<"I'm a tiger"<<endl;
}
int main(){
	Tiger tiger;
	tiger.speak();
	return 0;
}
