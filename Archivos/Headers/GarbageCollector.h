#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H

#include "LinkedList.h"

/**
 * Clase Garbage Collector que se encarga de administrar la memoria del programa automáticamente
 */
class GarbageCollector {
protected:
    /**
     *  Variable que almacena el valor de inicialización de la clase Garbage Collector
     */
    int value_;
    /**
     *  Variable que contiene el largo de la estructura de datos utilizada para almacenar los objetos VSPtr
     */
    static int length;

private:
    /**
     * Variable que contiene la instancia del Garbage Collector
     */
    static GarbageCollector *inst_;
    /**
     * Variable que contiene la estructura de datos que almacena todos los objetos de tipo VSPtr
     */
    static LinkedList *list;
    /**
     * Variable utilizada para validación de inicio del thread
     */
    static bool firstIter;
    /**
     * Variable utilizada para validación de finalización del thread
     */
    static bool finished;
    /**
     * Variable utilizada para validación de finalización del thread
     */
    static bool stopThread;
    /**
     * Variable utilizada para validación de la correcta eliminación de la instancia del Garbage Collector
     */
    static bool inDestructor;

    /**
     * Constructor por defecto de la clase Garbage Collector
     */
    GarbageCollector();
    /**
     * Constructor de la clase Garbage Collector
     */
    GarbageCollector(const GarbageCollector &);
    /**
     * Método que sobrecarga el operador = para evitar reasignación de la instancia del Garbage Collector
     * @return Se retorna la referencia a la instancia del Garbage Collector
     */
    GarbageCollector &operator=(const GarbageCollector &);

public:
    /**
     * Método que inicializa la clase Garbage Collector para que cumpla con el comportamiento del patrón de diseño Singleton
     */
    static void init();
    /**
     * Método que retorna la instancia de la clase Garbage Collector
     * @return Se retorna la instancia de la clase Garbage Collector
     */
    static GarbageCollector *getInstance();
    /**
     * Método que retorna la instancia de la estructura de datos utilizada dentro de la clase Garbage Collector
     * @return Se retorna la instancia de la estructura de datos utilizada dentro de la clase Garbage Collector
     */
    static LinkedList *getList();
    /**
     * Método que elimina las instancias del Garbage Collector y la estructura de datos utilizada cuando estas ya no se ocupen
     */
    static void deleteInst();

    /**
     * Método que devuelve el valor de la variable value_
     * @return Se retorna el valor de la variable value_
     */
    int getValue();
    /**
     * Método que devuelve el valor de la variable firstIter
     * @return Se retorna el valor de la variable firstIter
     */
    bool getIter();
    /**
      * Método que devuelve el valor de la variable finished
      * @return Se retorna el valor de la variable finished
      */
    bool getFinished();
    /**
     * Método que devuelve el valor de la variable stopThread
     * @return Se retorna el valor de la variable stopThread
     */
    bool getStopThread();
    /**
      * Método que devuelve el valor de la variable inDestructor
      * @return Se retorna el valor de la variable inDestructor
      */
    static bool getBoolDestructor();
    /**
     * Método que cambia el valor de la variable inDestructor
     */
    static void setBoolDestructor();
    /**
     * Método que establece el valor de la variable value_
     * @param val - Valor que se desea establecer en la variable value_
     */
    void setValue(int val);

    /**
     * Método que ejecuta las validaciones respectivas del thread para su correcto funcionamiento
     */
    static void executeThread();
    /**
     * Método que se encarga de ejecutar el thread de la clase Garbage Collector cada 1 segundo
     */
    static void threadOn();
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
