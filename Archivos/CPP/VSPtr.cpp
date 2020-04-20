#include <iostream>
#include <thread>
#include <unistd.h>
#include "../Headers/VSPtr.h"
using std::cout;
using std::endl;

template<class T>
VSPtr<T>::VSPtr() : ptr(0), ref(0){
    ref = new RC();
    ref->AddRef();
}
template<class T>
VSPtr<T>::VSPtr(T *pValue) : ptr(pValue), ref(0){
    cout << "   ***   SALIENDO DEL MÉTODO New()!     ***   " << endl << endl;
    cout << "   ***   ENTRANDO AL CONSTRUCTOR VSPtr!   ***   " << endl;

    ref = new RC();
    ref->AddRef();

    //AGREGANDO INSTANCIA VSPOINTER AL GARBAGE COLLECTOR
    GarbageCollector<T>::getList()->createNode(ptr);

    //ESTABLECIENDO ID DEL VSPOINTER
    ID = GarbageCollector<T>::getList()->getLength();

    cout << "   ***   SALIENDO DEL CONSTRUCTOR VSPtr!   ***   " << endl;
    cout << "****************************************************" << endl << endl;


    sleep(2);

}
template<class T>
VSPtr<T>::VSPtr(const VSPtr<T> &sp) : ptr(sp.ptr), ref(sp.ref) {
    // Copy constructor
    // Copy the data and ref pointer
    // and increment the ref refCount
    ref->AddRef();
    sleep(3);
}
template<class T>
VSPtr<T>::~VSPtr() {
    cout << "LLamada al destructor de ----->" << "  ID: " << this->ID << "   Data: " << ptr << endl;

    GarbageCollector<T>::getList()->deleteAtPosition(this->ID);

    if(ref->Release() == 0){
        cout << "       Borrando Puntero: " << ptr << endl;
        delete ptr;
        ptr = nullptr;

        cout << "       Borrando RC: " << ref->getCount() << endl << endl;
        delete ref;
        ref = nullptr;

        // SI NO HAY MÁS VSPOINTER, SE ELIMINA LA LISTA Y EL GARBAGE COLLECTOR
        if (GarbageCollector<T>::getList()->getLength() == 0){

            delete GarbageCollector<T>::getList();
            delete GarbageCollector<T>::getInstance();

            sleep(2);

            GarbageCollector<T>::deleteInst();

            sleep(2);
        }

    } else{

        //EVITANDO PUNTEROS COLGANTES
        cout << "----->   Borrando ptr: " << ptr << "       RC: " << ref << endl;
        ptr = nullptr;
        ref = nullptr;
        cout << "----->   Borrando ptr: " << ptr << "       RC: " << ref << endl << endl;
    }
    sleep(2);
}

template<class T>
T &VSPtr<T>::operator*() {
    return *ptr;
}
template<class T>
T &VSPtr<T>::operator&() {
    return *ptr;
    }

template<class T>
VSPtr<T> *VSPtr<T>::operator->() {
    return this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(const VSPtr<T> &sp) {
    // Assignment operator
    if (this != &sp) { // Avoid self assignment
        // Decrement the old ref refCount
        // if ref become zero delete the old data
        int idActual = 0;
        if(ref->Release() == 0){
            idActual = this->ID;
            delete ptr;
            delete ref;
        }

        // Copy the data and ref pointer
        // and increment the ref refCount
        ptr = sp.ptr;
        ref = sp.ref;
        ref->AddRef();

        (GarbageCollector<T>::getList()->getAtPosition(idActual))-> data = ptr;

        sleep(3);
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(int sp) {
    cout << endl << " ** Reasignacion de valor interno ** "<< endl;
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        cout << " ** Asignando valor ** "<< endl << endl;

        *ptr = sp;

        GarbageCollector<T>::getList()->assignAll(this->ID, sp);

        sleep(3);
    }
    return *this;
}

template<class T>
VSPtr<T> VSPtr<T>::New(){
    if (GarbageCollector<T>::getList() == nullptr) {
        GarbageCollector<T>::init();
    }

    cout << endl << "   ***   ENTRANDO AL MÉTODO New()!   ***" << endl;

    return VSPtr(new int());
}

template<class T>
T* VSPtr<T>::getAddress() {
    return ptr;
}
template<class T>
int VSPtr<T>::getCount() {
    return ref->getCount();
}
template<class T>
int VSPtr<T>::getID() {
    return ID;
}
template<class T>
void VSPtr<T>::setID(int id) {
    ID = id;
}