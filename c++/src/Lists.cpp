//============================================================================
// Name        : Lists.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;
int main() {
	list<int> myList(3, 4);
	myList.push_front(23);
	myList.push_back(323); //we can push back and front in a list but cant do push front in vector for performance reason
	list<int>::iterator it;
	for (auto it = myList.begin(); it != myList.end(); ++it) {
		if (*it == 323) {
			myList.insert(it, 33); //inserts 33 before 323 in the list
		}
		cout << *it << endl;
	}
	myList.pop_back(); //popping back for the list
	myList.pop_front(); //popping from front of the list
	it = myList.begin();
	it++;
	it = myList.erase(it); //erasing using iterator
	cout << "after erasing " << endl;
	for (auto it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << endl;
	}
	myList.clear();
	for (auto it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << endl;  //nothing gets printed on stdout
	}
	return 0;
}
