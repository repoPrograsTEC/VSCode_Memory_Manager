#include <iostream>
#include "../Archivos/CPP/VSPtr.cpp"
#include "../Archivos/CPP/ReferenceCounter.cpp"
#include "../Archivos/CPP/GarbageCollector.cpp"
#include "../Archivos/CPP/LinkedList.cpp"

using std::cin;
using std::cout;

int main(){

    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();

    *myPtr1 = 5;
    &myPtr2 = 20;

    myPtr2 = myPtr1;
    myPtr2 = 11;


    return 0;
}