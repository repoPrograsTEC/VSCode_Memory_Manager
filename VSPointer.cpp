//
// Created by danbg on 3/23/2020.
//
#include <iostream>

using namespace std;

template <class T>
class VSPointer {
    T *ptr; // Actual pointer
public:
    // Constructor
    explicit VSPointer(T *p = NULL) { ptr = p; }

    // Destructor
    ~VSPointer() { delete (ptr); }

    //Sobrecargando operador de desreferenciación
    // Overloading dereferncing operator
    T &operator*() { return *ptr; }


    //Sobrecarga del operador de flecha para que se pueda
    //acceder a los miembros de T como
    //un puntero (útil si T representa una clase, estructura o tipo de unión)

    // Overloding arrow operator so that members of T can be accessed
    // like a pointer (useful if T represents a class or struct or
    // union type)
    T* operator -> () { return ptr; }
};
