#include <iostream>
#include "ReferenceCounter.cpp"

using namespace std;

template <class T>
class VSPointer {
private:
    T *ptr;     //Puntero actual
    RC *ref;    //Contador de referencias
public:
    VSPointer();
    explicit VSPointer(T* pValue);
    VSPointer(const VSPointer<T>& sp);
    ~VSPointer();

    static VSPointer<int> New();

    T& operator* ();
    T* operator-> ();

    VSPointer<T>& operator = (const VSPointer<T>& sp);

};

template<class T>
VSPointer<T>::VSPointer() : ptr(0), ref(0){
    // Create a new ref
    ref = new RC();
    // Increment the ref count
    ref->AddRef();
}

template<class T>
VSPointer<T>::VSPointer(T *pValue) : ptr(pValue), ref(0){
    // Create a new ref
    ref = new RC();
    // Increment the ref count
    ref->AddRef();
}

template<class T>
VSPointer<T>::VSPointer(const VSPointer<T> &sp) : ptr(sp.ptr), ref(sp.ref) {
    // Copy constructor
    // Copy the data and ref pointer
    // and increment the ref count
    ref->AddRef();
}

template<class T>
VSPointer<T>::~VSPointer() {
    // Destructor
    // Decrement the ref count
    // if ref become zero delete the data
    if(ref->Release() == 0){
        delete ptr;
        delete ref;
    }
}

template<class T>
T& VSPointer<T>::operator*() {
    return *ptr;
}

template<class T>
T* VSPointer<T>::operator->() {
    return ptr;
}

template<class T>
VSPointer<T> &VSPointer<T>::operator=(const VSPointer<T> &sp) {
    // Assignment operator
    if (this != &sp) { // Avoid self assignment
        // Decrement the old ref count
        // if ref become zero delete the old data
        if(ref->Release() == 0){
            delete ptr;
            delete ref;
        }

        // Copy the data and ref pointer
        // and increment the ref count
        ptr = sp.ptr;
        ref = sp.ref;
        ref->AddRef();
    }
    return *this;
}

template<class T>
VSPointer<int> VSPointer<T>::New(){
    return VSPointer();
}






