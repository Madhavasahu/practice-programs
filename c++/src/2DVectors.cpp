//============================================================================
// Name        : 2DVectors.cpp
// Author      : Madhava
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
void printVecIterator(vector< vector<int> > &ref ,vector< vector<int> >::iterator row, vector< int >::iterator col){
	//observe syntax for accessing iterators while passing to function. here we accepting as a reference
	for(row = ref.begin(); row != ref.end();++row){
			for(col = row->begin(); col !=row->end(); ++col ){
				cout<<*col<<" "<<flush;
				if(*col == 3)
					printf("\nHello world..I got 3\n");
			}
			cout<<endl;
		}
}
void printVecLoops(vector<vector<int>>&grid){ //taking reference of a 2D Vector
	for(unsigned int i = 0 ;i<grid.size();++i){
			for(unsigned int j=0;j<grid[i].size(); ++j){
				cout<<grid[i][j]<<" "<<flush;
			}
			cout<<endl;
		}
}
int main() {
	/* initializig the 2D vectors. two approaches
	 * 1.vector<vector<int>> grid(3,vector<int>(4,7));  --> A 2D vector with 3 rows 4 columns each row has 7
	 * 2.vector< vector<int> > grid;  do not initialize any value here.
		vector<int>rows(4,9); create individual rows and columns
		vector<int>cols(5,10);
		grid.push_back(rows); push_back rows then columns
		grid.push_back(cols);
	 */

/*	vector< vector<int> > grid;
	vector<int>rows(4,9);
	vector<int>cols(5,10);
	grid.push_back(rows);
	grid.push_back(cols);*/
	vector<vector<int>> grid(3,vector<int>(4,7));
	vector< vector<int> >::iterator row;
	vector< int >::iterator col;
	grid[1].push_back(34);
	grid[0].push_back(3);
	grid.push_back(vector<int>(4,2)); //adding a single row(i.e vector) to last of the 2D-vector
	cout<<"with Iterators"<<endl;
	printVecIterator(grid,row,col);
	cout<<"with Loops "<<endl;
	printVecLoops(grid);
	return 0;
}
