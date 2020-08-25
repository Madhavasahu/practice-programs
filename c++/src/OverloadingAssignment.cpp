//============================================================================
// Name        : OverloadingAssignment.cpp
// Author      : Madhava
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Test{
private:
	int id;
	string name;
	char *ptr;
public:
	Test(void);
	Test(int id, string name, const char *ptr);
	void print(void);
	const Test& operator=(const Test &test);
	bool operator==(const Test &test);
	bool operator!=(const Test &test);
};
bool Test::operator==(const Test &test){
	return (id == test.id);
}
bool Test::operator!=(const Test &test){
	return !(*this == test); //comparing this and test object using == operator that we already defined
}
const Test&  Test::operator=(const Test &test){
	cout<<"member Assignment operator called"<<endl;
	if(this == &test){
		cout<<"self assigned"<<endl; //this guards the memory leak when dynamically allocate memory
		return *this;
	}
	id = test.id;
	name = test.name;
	return *this; //returning this object
}
void Test::print(void){
	cout<<"Name :"<<name<<endl;
	cout<<"id :"<<id<<endl;
	cout<<"ptr :"<<ptr<<endl;
}
Test::Test(){
	ptr = nullptr;
	id = 0;
	name = "default";
}
Test::Test(int id, string name="unknown", const char *str="same here"){
	this->id = id;
	this->name = name;
	if(!id){
		ptr = nullptr;
	}else{
		ptr = new char[id];
		for(int i=0; i< id; i++)
			ptr[i] = str[i];
		//ptr = temp;
		//strcpy(this->ptr,str);
		/*while(*str){
			*temp = *str;
			temp++;
			str++;
		}
		*temp = '\0';*/
	}
}
int main() {
	Test test1(10);
	Test test2;
	test2.operator=(test1); //same as below syntax
	test2 = test1;
	test1.print();
	Test test3;
	if(test1 != test3){
		cout<<" Not Equal"<<endl;
	}else{
		cout<<"equal"<<endl;
	}
	if(test1 == test3){
			cout<<"Equal"<<endl;
		}else{
			cout<<"Not equal"<<endl;
		}
	return 0;
}
