//============================================================================
// Name        : RangeBasedLoops.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int>myVector(23,2);
	myVector.push_back(34);
	myVector.push_back(232);
	for(auto ref:myVector){
		cout<<ref<<' ';
	}
	cout<<endl;
	for (int n : {0, 1, 2, 3, 4, 5})
		cout << n << ' ';
	return 0;
}
