//============================================================================
// Name        : ComplexDataTypes.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	map<string, vector<int> >myMap;
	myMap["madhava"].push_back(3);
	myMap["sahu"].push_back(4);
	for(auto it = myMap.begin(); it != myMap.end(); ++it){
		cout<<it->first<<endl;
		vector<int>temp = it->second;   //return a member of vector
		cout<<"size is "<<temp.size()<<endl; //thats why this is always 1
		for(auto it = temp.begin(); it != temp.end(); ++it){
			cout<<*it<<endl;
		}
	}
	return 0;
}
