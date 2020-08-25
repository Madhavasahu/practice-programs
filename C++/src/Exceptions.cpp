//============================================================================
// Name        : Exceptions.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test {
private:
	bool error = true;
public:
	void checkError(void);
	void setError(bool);
};
void Test::setError(bool status) {
	this->error = status;
}
void Test::checkError(void) {
	if (error) {
		throw 87 ;
	} else {
		cout << "error is " << error << endl;
	}
}
int main() {
	Test test;
	test.setError(true);
	try {
		test.checkError();
	}catch(const char *ptr){ //for catching const char pointer to string
		cout<<ptr<<endl;
	}catch(string &str){    //for catching strings
		cout<<str<<endl;
	}catch(int code){
		cout<<"Error code "<<code<<endl;
	}
	cout << "end of main" << endl;
	return 0;
}
