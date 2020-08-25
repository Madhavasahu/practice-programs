//============================================================================
// Name        : STL-Vectors.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//void getVector(vector<Test> &ref);
class Test{
	int a=0;
public:
	Test(){/*//cout<<"constructor called"<<endl;*/}
	Test(int);
	void setA(int);
	int getA(void);
};
void getVector(vector<Test> &ref){
	unsigned int vectorSize;
	unsigned int a;
	cout<<"Enter the size of the vector"<<endl;
	cin>>vectorSize;
	for(uint32_t i = 0;i <vectorSize;i++){
			cout<<"Enter "<<i<<" th value "<<endl;
			cin>>a;
			ref.push_back(Test(a));
			//test[i].setA(a);
		}
	cout<<ref[0].getA();
}
void printVector(vector<Test> &ref){
	vector<Test>::iterator it;
		for(it = ref.begin(); it != ref.end(); it++)
				cout<<"value of "<<it->getA()<<endl;
}
Test::Test(int a):a(a){}
void Test::setA(int a){this->a = a;}
int Test::getA(void){return a;}
int main() {
	vector<Test>test;
	//getVector(test);
	//printVector(test);
	vector<int> test2(5,10);
	cout<<test2.size()<<endl;
	test2.resize(100);
	cout<<test2.max_size()<<endl;
	test2.shrink_to_fit();
	cout<<test2.capacity()<<endl;
	cout<<test2.max_size()<<endl;
	/*for(uint32_t i=0; i<vectorSize;i++)
		cout<<"value of "<<i<<"th Value:: " <<test[i].getA()<<endl;
*/
/*	vector<string>names;
	names.push_back("madhava");
	names.push_back("jaggu");
	names.push_back("sahu");
	for(uint32_t i = 0;i<names.size();i++) //iterating through for loops
		cout<<names[i]<<endl;
	vector<string>::iterator it;
	for(it = names.begin(); it != names.end(); it++){
		cout<<*it<<endl;
		if(*it == "sahu")
			printf("hell worl");
	}*/
	return 0;
}
