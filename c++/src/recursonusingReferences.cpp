//============================================================================
// Name        : recursonusingReferences.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int f(int &x,int c){//here x is passed by reference so gets incremented everytime, c is passed by value
					//so compiler creates a new copy for every iteration.
	cout<<x<<" "<<c<<endl;
	c = c-1;
	if (c == 0) return 1 ;
	x = x+1;
	int a = f(x,c) * x;
	cout<<"a is "<<a<<endl;
	cout<<"x is "<<x<<endl;
	return a;
}
int main() {
	int k{10};
	cout<<k<<endl;
	int a=5,c=5;
	cout<<f(a,c)<<endl;;
	return 0;
}
