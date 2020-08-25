//============================================================================
// Name        : UsingFunctionPointers.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
bool match(string name){
	return name.size() == 2;
}

void countStrings(vector<string> &ref, bool (*pmatch)(string name)){
	int count = 0;
	for(unsigned int i=0;i<ref.size();i++){
		if(pmatch(ref[i])){
			count++;
		}
	}
	cout<<"No of string with size 2 are "<<count<<endl;
}
int main() {
	vector<string>names;
	names.push_back("hello");
	names.push_back("hi");
	countStrings(names,match); //passing match function
	return 0;
}
