#include "../Headers/VSPtr.h"
using std::string;

template<class T>
VSPtr<T>::VSPtr() : ptr(0), ref(0){
    ref = new RC();
    ref->AddRef();
}
template<class T>
VSPtr<T>::VSPtr(T *pValue) : ptr(pValue), ref(0){
    ref = new RC();
    ref->AddRef();

    //AGREGANDO INSTANCIA VSPOINTER AL GARBAGE COLLECTOR
    GarbageCollector::getList()->createNode(this);
}
template<class T>
VSPtr<T>::VSPtr(const VSPtr<T> &sp) : ptr(sp.ptr), ref(sp.ref) {
    // Copy constructor
    // Copy the data and ref pointer
    // and increment the ref refCount
    ref->AddRef();
}
template<class T>
VSPtr<T>::~VSPtr() {
    GarbageCollector::setBoolDestructor();
    GarbageCollector::getList()->deleteAtPosition(this);

    if(ref->Release() == 0){
        delete ptr;
        delete ref;
        ptr = nullptr;
        ref = nullptr;

        // SI NO HAY MÁS VSPOINTER, SE ELIMINA LA LISTA Y EL GARBAGE COLLECTOR
        if (GarbageCollector::getList()->getLength() == 0){
            GarbageCollector::deleteInst();
        }
    } else{
        //EVITANDO PUNTEROS COLGANTES
        ptr = nullptr;
        ref = nullptr;
    }
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


        Node *current = new Node;
        Node *previous = new Node;
        current = (GarbageCollector::getList()) -> getHead();

        int tempID = 0;

        for(int i = 0; i < (GarbageCollector::getList()) -> getLength(); i++){
            if (typeid(T) == typeid(int) && (current->data.intType) == (VSPtr<int>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(float) && (current->data.floatType) == (VSPtr<float>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(double) && (current->data.doubleType) == (VSPtr<double>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(long) && (current->data.longType) == (VSPtr<long>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(char) && (current->data.charType) == (VSPtr<char>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(string) && (current->data.stringType) == (VSPtr<string>*)&sp){
                tempID = current->ID;
                break;
            } else if (typeid(T) == typeid(bool) && (current->data.boolType) == (VSPtr<bool>*)&sp){
                tempID = current->ID;
                break;
            } else{
                previous = current;
                current = current->next;
            }
        }


        Node *current2 = new Node;
        Node *previous2 = new Node;
        current2 = (GarbageCollector::getList()) -> getHead();

        for(int i = 0; i < (GarbageCollector::getList()) -> getLength(); i++){
            if (typeid(T) == typeid(int) && (current2->data.intType) == (VSPtr<int>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(float) && (current2->data.floatType) == (VSPtr<float>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(double) && (current2->data.doubleType) == (VSPtr<double>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(long) && (current2->data.longType) == (VSPtr<long>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(char) && (current2->data.charType) == (VSPtr<char>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(string) && (current2->data.stringType) == (VSPtr<string>*)this){
                current2->ID = tempID;
                break;
            } else if (typeid(T) == typeid(bool) && (current2->data.boolType) == (VSPtr<bool>*)this){
                current2->ID = tempID;
                break;
            } else{
                previous2 = current2;
                current2 = current2->next;
            }
        }
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(int sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(float sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(double sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(long sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(char sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(string sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}
template<class T>
VSPtr<T> &VSPtr<T>::operator=(bool sp) {
    if ((typeid(*ptr).name() == typeid(sp).name())) {
        *ptr = sp;
    }
    return *this;
}

template<class T>
VSPtr<T> VSPtr<T>::New(){
    if (GarbageCollector::getList() == nullptr) {
        GarbageCollector::init();
    }
    return VSPtr<T>(new T());
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
T VSPtr<T>::getAddressValue() {
    return *(this->ptr);
}
template<class T>
int VSPtr<T>::getCount() {
    return ref->getCount();
}