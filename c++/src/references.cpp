//============================================================================
// Name        : references.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef struct{
	string s1="madahva";
}STRCT;

ostream& operator<<(ostream &out,const STRCT &ref2){
	out << &(ref2.s1);
	return out;
}
void change(STRCT &ref){
	cout<<"ref address "<<(ref)<<endl;
	ref.s1 = "Madhava";
}
void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main() {
	int cc= 100;
	int  &ccref = cc;
	cc =100;
	int cs=300;
	ccref = cs;
	ccref = 400;
	printf("%d",cs);

	/*int a=1000;
	int &ref = a;
	cout<<"a value  "<<a<<endl;
	ref =320;
	cout<<"a value after changing it by ref "<<a<<endl;
	int b = 200;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	STRCT ex;
	cout<<"ex address "<<&(ex.s1)<<endl;
	change(ex);
	cout<<ex.s1<<endl;*/
	return 0;
}
