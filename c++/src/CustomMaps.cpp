//============================================================================
// Name        : CustomMaps.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;
class Test{
private:
	string name;
	int id;
public:
	Test();
	Test(string,int);
	Test(const Test &test);
	void print()const;
	bool operator<(const Test &test)const;
};
bool Test::operator<(const Test &test)const{
	if (name == test.name){
		return id < test.id;
	}else{
		return name <test.name;
	}
}
Test::Test(const Test &test){
	//cout<<"constructor called"<<endl;
	name = test.name;
	id = test.id;
}
Test::Test(void){name = "madhava";id = 512;}
Test::Test(string name,int id):name(name),id(id){}
void Test::print(void)const{cout<<name<<" "<<id<<endl;}
int main() {
	map<Test,int>myMap;
	myMap[Test("ravi",35)] = 0; //copy constructor is called
	myMap[Test("ravi",33)] = 32; //copy constructor is called
	myMap[Test("kavitha",56)] = 1; //copy constructor is called
	for(auto it = myMap.begin(); it != myMap.end(); ++it){
		it->first.print();
		cout<<it->second<<endl;;
	}
	return 0;
}
