#include<iostream>
#include "VSPointer.cpp"

using namespace std;

int main() {
    VSPointer<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}