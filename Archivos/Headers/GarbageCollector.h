#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H

#include "LinkedList.h"

class GarbageCollector {
protected:
    int value_;
    static int length;

private:
    static GarbageCollector *inst_;
    template<typename T>
    static LinkedList<T> *list;
    static bool firstIter;
    static bool finished;
    static bool stopThread;

    GarbageCollector();
    GarbageCollector(const GarbageCollector &);
    GarbageCollector &operator=(const GarbageCollector &);

public:
    template<typename T>
    static void init();
    template<typename T>
    static GarbageCollector *getInstance();
    template<typename T>
    static LinkedList<T> *getList();
    template<typename T>
    static void deleteInst();

    int getValue();
    bool getIter();
    bool getFinished();
    bool getStopThread();
    void setValue(int val);

    template<typename T>
    static void executeThread();
    template<typename T>
    static void threadOn();
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
