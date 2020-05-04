#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H

#include "ReferenceCounter.h"
using std::ostream;
using std::endl;

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

    static VSPtr<T> New();

    VSPtr<T>* getInstanceAddress();
    T* getAddress();
    int getCount();
};


//SE DEFINE AL FINAL PARA QUE EL MÉTODO CREATENODE DE LINKEDLIST RECONOZCA LA CLASE VSPTR
#include "GarbageCollector.h"


#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
