//============================================================================
// Name        : Files.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream outFile;
	fstream inFile;
	string file = "sample.txt";
	outFile.open(file,ios::out);
	inFile.open(file,ios::in);
	if(outFile.is_open()){
		outFile<<"HELLO WORLD"<<endl;
		outFile<<"welcome to c++"<<endl;
		outFile.close();
	}else{
		cout<<"not able to open file "<<file<<endl;
	}
	if(inFile.is_open()){
		string line;
		while(inFile){
			getline(inFile,line);
			cout<<line<<endl;
		}
		inFile.close();
	}else{
		cout<<"not able to open file "<<file<<endl;
	}
	return 0;
}
