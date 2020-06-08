#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H

#include "ReferenceCounter.h"
using std::string;

/**
 * Clase VSPtr que se encarga de tratar los objetos creados como smart pointers
 * @tparam T - La clase VSPtr es de tipo template
 */
template<class T>
class VSPtr {
private:
    /**
     * Puntero interno del objeto VSPtr
     */
    T *ptr;
    /**
     * Variable para almacenar el conteo de referencias sobre el objeto VSPtr
     */
    RC *ref;
public:
    /**
     * Constructor por defecto de la clase VSPtr
     */
    VSPtr();
    /**
     * Constructor con parámetro inicial que indica el tipo de VSPtr
     * @param pValue - Tipo de VSPtr
     */
    explicit VSPtr(T *pValue);
    /**
     * Constructtor de copia para los objetos VSPtr
     * @param sp - Valor que se debe almacenar cuando el objeto VSPtr es copiado
     */
    VSPtr(const VSPtr<T> &sp);
    /**
     * Destructor de objetos VSPtr para administrar la correcta eliminación de la memoria utilizada
     */
    ~VSPtr();

    /**
     * Método que sobrecarga el operador * para lograr acceder al valor almacenado en el objeto VSPtr
     * @return Se retorna el valor interno del objeto VSPtr
     */
    T &operator*();
    /**
    * Método que sobrecarga el operador & para lograr acceder al valor almacenado en el objeto VSPtr
    * @return Se retorna el valor interno del objeto VSPtr
    */
    T &operator&();
    /**
     * Método que sobrecarga el operador -> para lograr acceder a la dirección de memoria del valor almacenado en el objeto VSPtr
     * @return Se retorna la dirección de memoria del valor interno del objeto VSPtr
     */
    VSPtr<T> *operator->();
    /**
     * Método que sobrecarga el operador = para lograr copiar objetos VSPtr
     * @param sp - Objeto VSPtr a copiar
     * @return Se retorna una copia del objeto VSPtr en el objeto actual en caso de coincidir en el tipo de dato interno
     */
    VSPtr<T> &operator=(const VSPtr<T> &sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo entero que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(int sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo flotante que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(float sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo double que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(double sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo long que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(long sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo char que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(char sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo string que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(string sp);
    /**
     * Método que sobrecarga el operador = para lograr asignar el valor deseado como un atributo del objeto VSPtr
     * @param sp - Valor de tipo boolean que se desea asignar como atributo al objeto VSPtr
     * @return Se retorna el objeto VSPtr que se acaba de cambiar
     */
    VSPtr<T> &operator=(bool sp);

    /**
     * Método que genera las instancias de los objetos VSPtr
     * @return Se retorna el objeto VSPtr creado
     */
    static VSPtr<T> New();

    /**
     * Método que retorna la dirección de memoria de la instancia del objeto VSPtr
     * @return Se retorna la dirección de memoria de la instancia del objeto VSPtr
     */
    VSPtr<T>* getInstanceAddress();
    /**
     * Método que retorna la dirección de memoria del puntero interno del objeto VSPtr
     * @return Se retorna la dirección de memoria del puntero interno del objeto VSPtr
     */
    T* getAddress();
    /**
     * Método que retorna el valor guardado en la dirección de memoria del puntero interno del objeto VSPtr
     * @return Se retorna el valor guardado en la dirección de memoria del puntero interno del objeto VSPtr
     */
    T getAddressValue();
    /**
     * Método que retorna el conteo de referencias de un objeto VSPtr
     * @return Se retorna el conteo de referencias de un objeto VSPtr
     */
    int getCount();
};


//SE DEFINE AL FINAL PARA QUE EL MÉTODO CREATENODE DE LINKEDLIST RECONOZCA LA CLASE VSPTR
#include "GarbageCollector.h"


#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__VSPTR_H
