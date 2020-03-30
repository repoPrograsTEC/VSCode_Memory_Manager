#include <iostream>
#include "ReferenceCounter.cpp"

using namespace std;

template <class T>
class VSPtr {
private:
    T *ptr;     //Puntero actual
    RC *ref;    //Contador de referencias
public:
    VSPtr();
    explicit VSPtr(T* pValue);
    VSPtr(const VSPtr<T>& sp);
    ~VSPtr();

    T& operator* ();
    T& operator& ();
    T* operator-> ();
    VSPtr<T>& operator = (const VSPtr<T>& sp);
    VSPtr<T>& operator = (int sp);

    static VSPtr<int> New();
    T* getAddress();
    int getCount();


};


template<class T>
VSPtr<T>::VSPtr() : ptr(0), ref(0){
    // Create a new ref
    ref = new RC();
    // Increment the ref count
    ref->AddRef();
}

template<class T>
VSPtr<T>::VSPtr(T *pValue) : ptr(pValue), ref(0){
    // Create a new ref
    ref = new RC();
    // Increment the ref count
    ref->AddRef();
}

template<class T>
VSPtr<T>::VSPtr(const VSPtr<T> &sp) : ptr(sp.ptr), ref(sp.ref) {
    // Copy constructor
    // Copy the data and ref pointer
    // and increment the ref count
    ref->AddRef();
}

template<class T>
VSPtr<T>::~VSPtr() {
    // Destructor
    // Decrement the ref count
    // if ref become zero delete the data
    cout << "LLamada al destructor de: " << ptr << endl;
    if(ref->Release() == 0){
        cout << "Borrando Puntero: " << ptr << endl;
        delete ptr;
        cout << "Borrando RC: " << ref->getCount() << endl << endl;
        delete ref;
    }
}

template<class T>
T& VSPtr<T>::operator*() {
    return *ptr;
}

template<class T>
T &VSPtr<T>::operator&() {
    return *ptr;
}

template<class T>
T* VSPtr<T>::operator->() {
    return this;
}

template<class T>
VSPtr<T> &VSPtr<T>::operator=(const VSPtr<T> &sp) {
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
VSPtr<T> &VSPtr<T>::operator=(int sp) {
    cout << endl << " ** Reasignacion de valor interno ** "<< endl;
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        cout << " ** Asignando valor ** "<< endl << endl;
        *ptr = sp;
    }
    return *this;
}

template<class T>
VSPtr<int> VSPtr<T>::New(){
    return  VSPtr(new int());
}

template<class T>
int VSPtr<T>::getCount() {
    return ref->getCount();
}

template<class T>
T* VSPtr<T>::getAddress() {
    return ptr;
}
