//============================================================================
// Name        : StandardExceptions.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Test {
public:
	Test() {
		while (true) {
			new int[100000000ul]; //throws bad_alloc exception for being not able to create huge dynamic memory
		}
	}
};
int main() {
		try {
			Test test;
		} catch (const std::bad_alloc &e) {
			std::cout << "Allocation failed: " << e.what() << '\n';
		}
	return 0;
}
