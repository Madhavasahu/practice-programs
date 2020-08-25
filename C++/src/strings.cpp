//============================================================================
// Name        : strings.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;
namespace madhava{
string toString(int number);
}
string madhava::toString(int number){
	stringstream ss;
	ss<<number;
	return ss.str();
}
int main() {
	string s1 = "madhava sahu";
	int ab=100;
	int ba;
	stringstream ss(s1);
	ss  << ab;  //putting into string stream
	ss >>ba; //extracting from string stream
	cout<<"ba is "<<ba<<endl;
	cout<<ss.str()<<endl;
	cout<<typeid(ab).name()<<endl; //to get the datatype type
	s1 = madhava::toString(ab);
	cout<<s1<<typeid(s1).name()<<endl;
	/*string s1 = "Madhava";
	string s2 = "Sahu";
	string s3 = s1+s2;
	int a=100;
	cout<<"the length is "<<s3.length()<<endl;;
	cout<<s1<<s2<<endl; //just printing the concatenated string
	cout<<s3<<endl; // storing and then printing the concatenated string
	cout<<"Enter your name"<<endl;
	getline(cin,s3);
	cout<<"Hello "<<s3<<endl;
	cout<<"Enter your age"<<endl;
	//cin.ignore(3267,'\n'); // ignore up to 32767 characters until a \n is removed
	int age;
	cin>>age;
	cout<<"you are "<<age<<" years older"<<endl;
	stringstream example ;
	example << s3;
	example << a;
	string s4 = example.str(); //to get the string out of example stream
	string s5;
	example >>s5; //to put whatever in example stream output it into s5
	cout<<s5<<endl;
	cout<<s4<<endl;
*/
	return 0;
}
