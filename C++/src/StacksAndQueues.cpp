//============================================================================
// Name        : StacksAndQueues.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
#include <stack>
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
};
Test::Test(const Test &test) {
	//cout << "constructor called" << endl;
	name = test.name;
	id = test.id;
}
Test::~Test() {/*cout<<"destructor is called"<<endl;*/
}
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
	stack<Test> testStack;
	testStack.push(Test("madhava", 23));
	testStack.push(Test("sahu", 33));
	testStack.push(Test("jagannadh", 45));
	//testStack.top().print(); //will print the top which last object pushed onto stack
	while (testStack.size() > 0) {
		Test &testObj = testStack.top(); // or we can combine testStack.top().print() to print objects
		testObj.print(); //will be print in LIFO order
		testStack.pop();
	}
	cout<<endl;
	queue<Test> testQueue;
	testQueue.push(Test("madhava", 23));
	testQueue.push(Test("sahu", 33));
	testQueue.push(Test("jagannadh", 45));
	//testQueue.front().print();  //prints the first object pushed into queue
	while(testQueue.size() > 0){
		testQueue.front().print(); //prints all the objects in FIFO order
		testQueue.pop();
	}
	return 0;
}
