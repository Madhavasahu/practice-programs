#include<iostream>
using namespace std;
template <class T>
void print(T obj){
    cout<<obj<<endl;
}
template <>
void print(int obj){
    cout<<"specializated version called "<<obj<<endl;
}
int main(int argc, char* argv[]){
    print<int>(23);
    print<string>("Madhava sahu");

	return 0;
}
