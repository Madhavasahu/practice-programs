//============================================================================
// Name        : ExceptionsExercise.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test{
public:
	Test();
	Test(const Test &ref);
};
Test::Test(const Test &ref){
	cout<<"copy constructor called"<<endl;
}
Test::Test(){
	cout<<"constructor called"<<endl;
}
void handleExceptions(){  //generic exception function to handle all types
	try{
		throw;
	}catch(Test &ref){
		cout<<"exception arised"<<endl;
	}catch(bad_alloc &ref){
		cout<<"bad_alloc arised"<<endl;
	}catch(char &c){
		cout<<"caught "<<c<<endl;
	}
}
int main() {
	try{
		throw 'a';
	}catch(...){
		handleExceptions();
	}
	return 0;
}
