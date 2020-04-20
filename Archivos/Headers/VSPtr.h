#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H

#include "ReferenceCounter.h"
#include "GarbageCollector.h"

template<class T>
class VSPtr {
private:
    T *ptr;
    RC *ref;
    int ID = 0;
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

    static VSPtr<T> New();

    T *getAddress();
    int getCount();
    int getID();
    void setID(int);
};


#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
