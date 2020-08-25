#include<iostream>
using namespace std;
#include "Test.h"
int main(){
    Test test;
    try{
    	test.somethingWrong();
    }catch(MyException &ref){
    	//cout<<ref.what()<<endl;
    	cout<<ref.returnMsg()<<endl;
    }
	return 0;
}
