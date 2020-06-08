#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H

#include "VSPtr.h"
#include <any>
#include <variant>
using std::any;
using std::variant;
using std::string;

/**
 *  Estructura que contiene todos los posibles tipos de objetos VSPtr que se pueden crear, basandose en el tipo de dato interno de este
 */
struct VSPtrType{
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo entero
     */
    VSPtr<int> *intType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo flotante
     */
    VSPtr<float> *floatType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo double
     */
    VSPtr<double> *doubleType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo long
     */
    VSPtr<long> *longType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo char
     */
    VSPtr<char> *charType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo string
     */
    VSPtr<string> *stringType;
    /**
     *  Variable que contiene una referencia al objeto VSPtr de tipo boolean
     */
    VSPtr<bool> *boolType;
};

/**
 *  Estructura que contiene la información de cada nodo de la lista enlazada
 */
struct Node {
    /**
     * Variable utilizada para almacenar la referencia al objeto VSPtr
     */
    VSPtrType data = VSPtrType();
    /**
     * Variable utilizada en validaciones y para almacenar el tipo de dato interno del objeto VSPtr
     */
    string dataType;
    /**
     * Variable utilizada para almacenar el ID autogenerado para cada objeto VSPtr
     */
    int ID;
    /**
     * Variable que contiene una referencia al siguiente nodo de la lista enlazada
     */
    Node *next;
};

/**
 *  Clase LinkedList que genera la estructura de datos utilizada para almacenar los objetos VSPtr
 */
class LinkedList {
private:
    /**
     * Variable que almacena la cabeza de la lista enlazada
     */
    Node *head;
    /**
     * Variable que almacena la cola de la lista enlazada
     */
    Node *tail;
    /**
     * Variable que almacena el largo de la lista enlazada
     */
    int length = 0;

public:
    /**
     * Constructor de la clase LinkedList
     */
    LinkedList();
    /**
     * Método que crea un nuevo nodo de la lista y establece todos los atributos requeridos con la información del objeto VSPtr ingresado
     * @tparam T - Tipo de dato interno del objeto VSPtr
     */
    template<typename T>
    void createNode(VSPtr<T> *);

    /**
     * Método que muestra en consola toda la información de cada nodo de la lista
     */
    void display();

    /**
     * Método que retorna el largo de la lista enlazada
     * @return Se retorna el largo de la lista enlazada
     */
    int getLength();
    /**
     * Método que retorna un nodo en una posición específica de la lista enlazada
     * @param id - ID del objeto VSPtr
     * @return Se retorna un nodo en una posición específica de la lista enlazada
     */
    Node* getAtPosition(int id);
    /**
     * Método que retorna la cabeza de la lista enlazada
     * @return Se retorna la cabeza de la lista enlazada
     */
    Node* getHead();

    /**
     * Método que inserta un nodo en la primera posición de la lista enlazada
     * @tparam T - Tipo de dato interno del objeto VSPtr
     */
    template<typename T>
    void insertAtFirst(VSPtr<T> *);
    /**
     * Método que inserta un nodo en la última posición de la lista enlazada
     * @tparam T - Tipo de dato interno del objeto VSPtr
     */
    template<typename T>
    void insertAtEnd(VSPtr<T> *);
    /**
     * Método que inserta un nodo en la posición deseada de la lista enlazada
     * @tparam T - Tipo de dato interno del objeto VSPtr
     * @param pos - Posición en la cual se insertará el objeto VSPtr en la lista enlazada
     * @param vsPtr - Objeto VSPtr a insertar en la lista enlazada
     */
    template<typename T>
    void insertAtPosition(int pos, VSPtr<T> *vsPtr);

    /**
     * Método que elimina el nodo que se encuentra en la primera posición de la lista enlazada
     */
    void deleteFirst();
    /**
     * Método que elimina el nodo que se encuentra en la última posición de la lista enlazada
     */
    void deleteLast();
    /**
     * Método que elimina un nodo específico de la lista enlazada
     * @tparam T - Tipo de dato interno del objeto VSPtr
     */
    template<typename T>
    void deleteAtPosition(VSPtr<T> *);
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__LINKEDLIST_H
