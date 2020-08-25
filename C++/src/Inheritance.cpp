//============================================================================
// Name        : Inheritance.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;


int main() {
	vector<int>Test{1,2,3,4};
	vector<int>::iterator it;
	for(it = Test.begin(); it != Test.end(); it++)
		cout<<*it<<endl;
	cout<<"size:: "<<Test.size()<<endl;
	cout<<"Capacity:: "<<Test.capacity()<<endl;
	Test.clear();
	cout<<"size:: "<<Test.size()<<endl;
	cout<<"Capacity:: "<<Test.capacity()<<endl;
	Test.resize(23);
	Test.reserve(32320);
	cout<<"size:: "<<Test.size()<<endl;
		cout<<"Capacity:: "<<Test.capacity()<<endl;
	return 0;
}
