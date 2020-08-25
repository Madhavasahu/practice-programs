//============================================================================
// Name        : maps.cpp
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
	void print();
	~Test();
};
Test::~Test(void){
	cout<<"destructor called"<<endl;
}
Test::Test(const Test &test){
	cout<<"constructor called"<<endl;
	name = test.name;
	id = test.id;
}
Test::Test(void){name = "madhava";id = 512;}
Test::Test(string name,int id):name(name),id(id){}
void Test::print(void){cout<<name<<" "<<id<<endl;}
int main() {
	map<int,string>myNormalMap;  //primitive map
	myNormalMap[0] = "madhava";
	myNormalMap[1] = "sahu";
	for(auto it = myNormalMap.begin(); it != myNormalMap.end();++it){
		//cout<<it->first<<endl;;
		//cout<<it->second<<endl;
	}
	map<int,Test>myMap;  //custom map
	//myMap[0] = Test("jagaguu",23); //destructor is called here
	//myMap[1] = Test("jagagddddduu",223);
	myMap.insert(make_pair(2,Test("madhava sahu",100)));//copy constructor and destructor is called twice here
	map<int,Test>::iterator it;
	for(it = myMap.begin(); it != myMap.end();++it){
		cout<<it->first<<endl;; //to access key
		it->second.print(); //to access values. Need to call objects method otherwise we can use "it->second" after overloading the << operator
	}
	return 0;
}
