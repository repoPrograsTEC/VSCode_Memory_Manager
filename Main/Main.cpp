




//  REVISAR CORRECTA ELIMINACION DE "DUMB" POINTERS EN EL CÓDIGO COMPLETO
//  REVISAR EL CORRECTO USO DE TEMPLATES EN GENERAL







#include <iostream>
#include "../Archivos/CPP/VSPtr.cpp"
#include "../Archivos/CPP/ReferenceCounter.cpp"
#include "../Archivos/CPP/GarbageCollector.cpp"
#include "../Archivos/CPP/LinkedList.cpp"

using std::cin;
using std::cout;
using std::string;

int main(){

    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();
    VSPtr<int> myPtr3 = VSPtr<int>::New();

    cout << "   VSPTR DESDE MAIN: " << (myPtr1.getInstanceAddress()) << "   " << (myPtr1.getAddress()) << "     *ptr: " << *(myPtr1.getAddress()) << "  " << endl;
    cout << "   VSPTR DESDE MAIN: " << (myPtr2.getInstanceAddress()) << "   " << (myPtr2.getAddress()) << "     *ptr: " << *(myPtr2.getAddress()) << "  " << endl;
    cout << "   VSPTR DESDE MAIN: " << (myPtr3.getInstanceAddress()) << "   " << (myPtr3.getAddress()) << "     *ptr: " << *(myPtr3.getAddress()) << "  " << endl;


    *myPtr1 = 5;
    &myPtr2 = 20;
    *myPtr3 = 650;

    sleep(1);
    myPtr3 = 500;

    sleep(1);
    myPtr2 = myPtr1;
    myPtr2 = 11;

    cout << "   VSPTR DESDE MAIN: " << (myPtr1.getInstanceAddress()) << "   " << (myPtr1.getAddress()) << "     *ptr: " << *(myPtr1.getAddress()) << "  " << endl;
    cout << "   VSPTR DESDE MAIN: " << (myPtr2.getInstanceAddress()) << "   " << (myPtr2.getAddress()) << "     *ptr: " << *(myPtr2.getAddress()) << "  " << endl;
    cout << "   VSPTR DESDE MAIN: " << (myPtr3.getInstanceAddress()) << "   " << (myPtr3.getAddress()) << "     *ptr: " << *(myPtr3.getAddress()) << "  " << endl;
    sleep(1);


    return 0;
}