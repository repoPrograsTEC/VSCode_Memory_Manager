#ifndef PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
#define PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H

#include "LinkedList.h"

template<class T>
class GarbageCollector {
protected:
    int value_;
    static int length;

private:
    static GarbageCollector *inst_;
    static LinkedList<T> *list;
    static bool firstIter;
    static bool finished;
    static bool stopThread;
    GarbageCollector();
    GarbageCollector(const GarbageCollector &);
    GarbageCollector &operator=(const GarbageCollector &);

public:
    static void init();
    static GarbageCollector *getInstance();
    static LinkedList<T> *getList();
    static void deleteInst();

    int getValue();
    bool getIter();
    bool getFinished();
    bool getStopThread();
    void setValue(int val);

    static void executeThread();

    static void threadOn();
};

#endif //PRUEBAS_DE_FUNCIONALIDAD__PROYECTO_1__GARBAGECOLLECTOR_H
