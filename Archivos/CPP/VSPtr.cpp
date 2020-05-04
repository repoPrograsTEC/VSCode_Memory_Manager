#include <iostream>
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
    GarbageCollector<T>::getList()->createNode(this);

    cout << "   ***   SALIENDO DEL CONSTRUCTOR VSPtr!   ***   " << endl;

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
    cout << "\n\nLLamada al destructor de ----->" << "  INSTANCIA VSPOINTER: " << this << "   PTR: " << this->ptr << "   *PTR: " << *(this->ptr) << endl;

    GarbageCollector<T>::getList()->deleteAtPosition(this);

    if(ref->Release() == 0){
        cout << "-------->   Borrando ptr: " << ptr << "       RC: " << ref << endl;
        delete ptr;
        delete ref;
        ptr = nullptr;
        ref = nullptr;
        cout << "-------->   Borrando ptr: " << ptr << "       RC: " << ref << endl << endl;

        // SI NO HAY MÁS VSPOINTER, SE ELIMINA LA LISTA Y EL GARBAGE COLLECTOR
        if (GarbageCollector<T>::getList()->getLength() == 0){
            GarbageCollector<T>::deleteInst();
            sleep(2);
        }

    } else{

        //EVITANDO PUNTEROS COLGANTES
        cout << "-------->   Borrando ptr: " << ptr << "       RC: " << ref << endl;
        ptr = nullptr;
        ref = nullptr;
        cout << "-------->   Borrando ptr: " << ptr << "       RC: " << ref << endl << endl;
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
        if(ref->Release() == 0){
            delete ptr;
            delete ref;

            ptr = nullptr;
            ref = nullptr;
        }

        // Copy the data and ref pointer
        // and increment the ref refCount
        ptr = sp.ptr;
        ref = sp.ref;
        ref->AddRef();








        //*******************************

        Node<T> *temp = new Node<T>;
        temp = (GarbageCollector<T>::getList()) -> getHead();
        while(temp->data != &sp){
            temp = temp->next;
        }

        int tempID = temp -> ID;


        Node<T> *temp2 = new Node<T>;
        temp2 = (GarbageCollector<T>::getList()) -> getHead();
        while(temp2->data != this){
            temp2 = temp2->next;
        }

        temp2->ID = tempID;

        //*******************************







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

        //GarbageCollector<T>::getList()->assignAll(this->ID, sp);

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

    return VSPtr<T>(new int());
}

template<class T>
VSPtr<T> *VSPtr<T>::getInstanceAddress() {
    return this;
}
template<class T>
T *VSPtr<T>::getAddress() {
    return this->ptr;
}
template<class T>
int VSPtr<T>::getCount() {
    return ref->getCount();
}