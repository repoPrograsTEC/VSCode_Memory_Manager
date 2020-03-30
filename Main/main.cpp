#include<iostream>
#include "../Archivos/VSPtr.cpp"

using namespace std;


int main() {

    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();

    *myPtr1 = 5;
    cout << " Valor inicial myPtr1: " << *myPtr1 << endl;

    *myPtr2 = 20;
    cout << " Valor inicial myPtr2: " << *myPtr2 << endl << endl;

    cout << " Tipo de myPtr1: " << typeid(*myPtr1).name() << endl;
    cout << " Tipo de myPtr2: " << typeid(*myPtr2).name() << endl << endl;

    myPtr2 = myPtr1;
    cout << " Reasignacion de valor de myPtr2 hacia myPtr1: " << *myPtr2 << endl << endl;

    cout << " Valor intermedio de myPtr1: " << *myPtr1 << endl;
    cout << " Valor intermedio de myPtr2: " << *myPtr2 << endl << endl;

    myPtr2 = 11;
    cout << " Reasignacion de valor interno de myPtr2: " << *myPtr2 << endl << endl;

    cout << " Valor final de myPtr1: " << *myPtr1 << endl;
    cout << " Valor final de myPtr2: " << *myPtr2 << endl << endl;


    /*
    VSPtr<int> myPtr1 = VSPtr<int>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();
    VSPtr<int> myPtr3 = VSPtr<int>::New();
    VSPtr<int> myPtr4 = VSPtr<int>::New();

    *myPtr1 = 5;
    cout << endl << " Value myPtr1: " << *myPtr1 << endl;
    cout << " Address myPtr1: " << myPtr1.getAddress() << endl;
    cout << " RC myPtr1: " << myPtr1.getCount() << endl << endl;

    *myPtr2 = 20;
    cout << " Value myPtr2: " << *myPtr2 << endl;
    cout << " Address myPtr2: " << myPtr2.getAddress() << endl;
    cout << " RC myPtr2: " << myPtr2.getCount() << endl << endl;

    *myPtr3 = 70;
    cout << " Value myPtr3: " << *myPtr3 << endl;
    cout << " Address myPtr3: " << myPtr3.getAddress() << endl;
    cout << " RC myPtr3: " << myPtr3.getCount() << endl << endl;

    cout << " Value myPtr4: " << *myPtr4 << endl;
    cout << " Address myPtr4: " << myPtr4.getAddress() << endl;
    cout << " RC myPtr4: " << myPtr4.getCount() << endl << endl;


    cout << endl << "  ***  REASIGNACION DE PUNTEROS  ***  " << endl << endl;

    myPtr2 = myPtr1;
    cout << *myPtr2 << endl;
    cout << myPtr2.getAddress() << endl;
    cout << " Ref myPtr1: " << myPtr1.getCount() << endl;
    cout << " Ref myPtr2: " << myPtr2.getCount() << endl;
    cout << " Ref myPtr3: " << myPtr3.getCount() << endl << endl;

    myPtr3 = myPtr1;
    cout << *myPtr3 << endl;
    cout << myPtr3.getAddress() << endl;
    cout << " Ref myPtr1: " << myPtr1.getCount() << endl;
    cout << " Ref myPtr2: " << myPtr2.getCount() << endl;
    cout << " Ref myPtr3: " << myPtr3.getCount() << endl << endl;

    myPtr4 = myPtr1;
    cout << *myPtr4 << endl;
    cout << myPtr4.getAddress() << endl;
    cout << " Ref myPtr1: " << myPtr1.getCount() << endl;
    cout << " Ref myPtr2: " << myPtr2.getCount() << endl;
    cout << " Ref myPtr3: " << myPtr3.getCount() << endl;
    cout << " Ref myPtr4: " << myPtr4.getCount() << endl << endl;

    int valor = &myPtr1;
    cout << "Valor: : " << valor << endl << endl;
    */

    return 0;
}


