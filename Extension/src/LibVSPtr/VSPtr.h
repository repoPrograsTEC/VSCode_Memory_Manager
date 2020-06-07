#ifndef VSPTR_VSPTR_H
#define VSPTR_VSPTR_H

#include "ReferenceCounter.h"

using std::string;

template<class T>
class VSPtr {
private:
    T *ptr;
    RC *ref;
public:
    VSPtr();
    explicit VSPtr(T *pValue);
    VSPtr(const VSPtr<T> &sp);
    ~VSPtr();

    T &operator*();
    T &operator&();
    VSPtr<T> *operator->();
    VSPtr<T> &operator=(const VSPtr<T> &sp);
    VSPtr<T> &operator=(int);
    VSPtr<T> &operator=(float);
    VSPtr<T> &operator=(double);
    VSPtr<T> &operator=(long);
    VSPtr<T> &operator=(char);
    VSPtr<T> &operator=(string);
    VSPtr<T> &operator=(bool);

    static VSPtr<T> New();

    VSPtr<T>* getInstanceAddress();
    T* getAddress();
    T getAddressValue();
    int getCount();
};

//SE DEFINE AL FINAL PARA QUE EL MÉTODO CREATENODE DE LINKEDLIST RECONOZCA LA CLASE VSPTR



#endif
