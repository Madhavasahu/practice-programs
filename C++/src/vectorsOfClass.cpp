#include <iostream>
#include <vector>
#define N 5

using namespace std;

class Test {
	// private variables
	int x, y;

public:
	// parameterised constructor

	Test(int x, int y)
		: x(x), y(y)
	{
	}

	// function to print
	void print()
	{
		cout << x << " " << y << endl;
	}
};

int main()
{
	// vector of type Test class
	vector<Test> v;

	// inserting object at the end of vector
	for (int i = 0; i < N; i++)
		v.push_back(Test(i, i + 1));

	// printing object content
	for (int i = 0; i < N; i++)
		v[i].print();

	return 0;
}
