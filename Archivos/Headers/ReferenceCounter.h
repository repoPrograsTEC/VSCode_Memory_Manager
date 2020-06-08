#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H

/**
 * Clase RC que se encarga de llevar el conteo de referencias sobre los objetos VSPtr
 */
class RC{
private:
    /**
     * Variable para almacenar el conteo de referencias
     */
    int refCount;
public:
    /**
     * Método que agrega referencias al objeto VSPtr
     */
    void AddRef();
    /**
     * Método que elimina referencias del objeto VSPtr
     * @return Se retorna el valor actual del conteo de referencias del objeto VSPtr
     */
    int Release();
    /**
     * Método que muestra la cantidad de referencias del objeto VSPtr
     * @return Se retorna el valor actual del conteo de referencias del objeto VSPtr
     */
    int getCount();
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__REFERENCECOUNTER_H
