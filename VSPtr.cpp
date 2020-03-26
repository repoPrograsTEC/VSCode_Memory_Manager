#include <iostream>

using namespace std;

template <class T>
class VSPtr {
    T *ptr; // Actual pointer
public:
    // Constructor
    explicit VSPtr(T *p = NULL);

    // Destructor
    ~VSPtr();

    //Sobrecargando operador de desreferenciación
    T &operator*();

    //Sobrecarga del operador de flecha para que se pueda acceder a los miembros de T como
    //un puntero (útil si T representa una clase, estructura o tipo de unión)
    T* operator -> ();

    static VSPtr New();
};

template<class T>
VSPtr<T>::VSPtr(T *p) {
    ptr = p;
}

template<class T>
VSPtr<T>::~VSPtr() {
    delete (ptr);
}

template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}

template<class T>
T *VSPtr<T>::operator->() {
    return ptr;
}

template<class T>
VSPtr<T> VSPtr<T>::New() {
    return VSPtr(new int());
}

