#include<iostream>
#include<cstring>
using namespace std;
class Test{
private:
	int a;
	char *name;
public:
	Test(const char *name);
	void printVars(void);
	~Test();
};
Test::~Test(void){
	cout<<"destructor called"<<endl;
	delete [] name;
}
void Test::printVars(void){
	cout<<a<<endl;
	cout<<name<<endl;
}
Test::Test(const char *name){
	cout<<"constructor called"<<endl;
	a=90;
	this->name = new char[20];
	strcpy(this->name,name);
}
int main(int argc, char* argv[]){
	const char name[] ="madhavasahu";
	Test test(name);
	test.printVars();
	return 0;
}
