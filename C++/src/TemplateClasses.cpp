//============================================================================
// Name        : TemplateClasses.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
template <class T>   //here need to specify that this is a template class. We can use template <typename T> also.
class Test{
private:
	T obj;
public:
	Test(T obj);
	void print(void);
};
template <class T,class U>   // a global template function.
//when there is only one class T, no need to call the function by specifying types but when we have two(T,U) we have to specify them
//while calling.
T sum(T var1, T var2){
	return U(var1+var2);
}
template<class T>            //here need to specify that it is a template class
void Test<T>::print(void){   //here need to specify that print is from Test class with T as parameter. Just void Test::print(void) WONT WORK
	cout<<obj<<endl;
}
template<class T>
Test<T>::Test(T obj){
	this->obj = obj;
}
int main() {
	Test<int>test(23);
	test.print();
	string name(" madhava");
	string sah("sahu");
	//cout<<sum(sah,name)<<endl; //calling sum on strings
	cout<<sum<int,int>(2,3)<<endl;      // calling sum of ints. need to specify the data types for more than one data types(T,U)
	//cout<<sum(2,3)<<endl; //no need to specify datatypes for single data type(i.e T)
	cout<<sum<int,float>(2.2,3.3)<<endl;
	return 0;
}
