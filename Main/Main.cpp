




//  REVISAR CORRECTA ELIMINACION DE "DUMB" POINTERS EN EL CÓDIGO COMPLETO
// FUNCIONAMIENTO DE ASIGNACIÓN DE VALOR A VSPOINTER<string> SOLO CON * O &, NO CON ASIGNACIÓN DIRECTA






#include <iostream>
#include "../Archivos/CPP/VSPtr.cpp"
#include "../Archivos/CPP/ReferenceCounter.cpp"
#include "../Archivos/CPP/GarbageCollector.cpp"
#include "../Archivos/CPP/LinkedList.cpp"

using std::cin;
using std::cout;
using std::string;

int main(){

    VSPtr<double> myPtr1 = VSPtr<double>::New();
    VSPtr<int> myPtr2 = VSPtr<int>::New();
    VSPtr<int> myPtr3 = VSPtr<int>::New();
    VSPtr<double> myPtr4 = VSPtr<double>::New();
    VSPtr<char> myPtr5 = VSPtr<char>::New();
    VSPtr<char> myPtr6 = VSPtr<char>::New();
    VSPtr<int> myPtr7 = VSPtr<int>::New();
    VSPtr<string> myPtr8 = VSPtr<string>::New();
    VSPtr<string> myPtr9 = VSPtr<string>::New();
    VSPtr<bool> myPtr10 = VSPtr<bool>::New();
    VSPtr<bool> myPtr11 = VSPtr<bool>::New();

    sleep(2);
    *myPtr1 = 5.2;
    &myPtr2 = 20;
    *myPtr3 = 650;
    &myPtr4 = 60.5;
    *myPtr5 = 'c';
    *myPtr6 = 'a';
    &myPtr7 = 80;
    *myPtr8 = "hola";
    &myPtr9 = "prueba";
    *myPtr10 = false;
    &myPtr11 = true;

    sleep(2);
    myPtr3 = 500;

    sleep(2);
    myPtr2 = myPtr3;

    sleep(2);
    myPtr2 = 11;

    sleep(2);
    myPtr4 = myPtr1;

    sleep(2);
    myPtr4 = 100.15;

    sleep(2);
    myPtr5 = myPtr6;

    sleep(2);
    myPtr5 = 'b';

    sleep(2);
    myPtr8 = myPtr9;

    sleep(2);
    *myPtr8 = "Cambio";

    sleep(2);
    myPtr10 = myPtr11;

    sleep(2);
    myPtr10 = false;

    sleep(2);

    return 0;
}