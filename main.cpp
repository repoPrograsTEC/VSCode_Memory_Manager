#include<iostream>
#include "VSPtr.cpp"
using namespace std;


int main() {
    VSPtr<int> ptr = VSPtr<int>::New();
    *ptr = 20;
    cout << *ptr << endl;
    cout << &ptr << endl;
    return 0;
}
