//============================================================================
// Name        : sets.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
using namespace std;
class Test {
private:
	string name;
	int id;
public:
	Test();
	Test(string, int);
	Test(const Test &test);
	void print() const;
	~Test();
	bool operator<(const Test &test) const;
};
bool Test::operator<(const Test &test) const {
	return name < test.name;  //sort the same pairs based upon their name
}
Test::Test(const Test &test) {
	cout << "constructor called" << endl;
	name = test.name;
	id = test.id;
}
Test::~Test(){cout<<"destructor is called"<<endl;}
Test::Test(void) {
	name = "madhava";
	id = 512;
}
Test::Test(string name, int id) :
		name(name), id(id) {
}
void Test::print(void) const {
	cout << name << " " << id << endl;
}

int main() {
	set<int> mySet;
	mySet.insert(10);
	mySet.insert(30);
	mySet.insert(30); //wont allow insertion of this value
	mySet.insert(40);
	for (auto it = mySet.begin(); it != mySet.end(); ++it) {
		cout << *it << endl;
	}

	auto itFind = mySet.find(40);
	if (itFind != mySet.end()) {
		cout << *itFind << " Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
	if (mySet.count(30)) {
		cout << "Number found" << endl;
	}

	set<Test> tests;
	tests.insert(Test("Madhava", 10)); //constructor and destructor is called here sequentially
	tests.insert(Test("sahu", 10));
	tests.insert(Test("Jagannadh", 20));
	for (auto it = tests.begin(); it != tests.end(); ++it) {
		it->print();
	}
	//all the above three objects are destroyed here
	return 0;
}
