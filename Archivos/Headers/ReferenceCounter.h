#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H

class RC{
private:
    int refCount;
public:
    void AddRef();
    int Release();
    int getCount();
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H
