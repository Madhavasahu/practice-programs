#include<iostream>
using namespace std;
template <class T>
class Test{
private:
        T obj;
public:
        void print();
        Test(T obj);
};
template <class T>
Test<T>::Test(T obj):obj(obj){}
template <class T>
void Test<T>::print(){
    cout<<obj<<endl;
}
int main(int argc, char* argv[]){
    Test<string>test("Madhava sahu");
    test.print();

	return 0;
}
