//============================================================================
// Name        : ArrayOfObjects.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Test{
private:
	string letter;
public:
	Test();
	~Test();
	void setLetter(char letter);
	void getLetter(void);
};
Test::Test(){
	//cout<<"constructor called"<<endl;
	letter = 'a';
}
Test::~Test(){
	//cout<<"destructor called"<<endl;
}
void Test::setLetter(char letter){
	this->letter = letter;
}
void Test::getLetter(void){
	cout<<"letter is "<<letter<<endl;
}
int main() {
	Test *ptr = new Test[26];
	char letter = 'a';
	for(int i=0;i<26;i++){
		string name(1,letter);    //return 1 number of a. if string name(23,letter).then gives 23 letters
		ptr[i].setLetter(letter); //we cant access using ptr[i]->syntax because ptr[i] points to a object not a ptr
		ptr[i].getLetter();
		letter++;
	}
	delete [] ptr;
	return 0;
}
