//============================================================================
// Name        : StaticVariables.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test {
private:
	int id;
	static int a;
public:
	Test(void);
	int getId(void);
};
Test::Test(void){
	id = ++a;
}
int Test::getId(void){
	return id;
}
int Test::a = 0;//need to define outside of the class
int main() {
	Test test[10];
	cout<<sizeof(test[0])<<endl;
	for(auto &ref:test)
		cout <<&ref<<" "<<ref.getId() << endl;
	return 0;
}
