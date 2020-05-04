#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include "../Headers/GarbageCollector.h"
using std::cout;
using std::endl;
using std::thread;
using namespace std::literals::chrono_literals;

template<typename T>
GarbageCollector<T> *GarbageCollector<T>::inst_ = nullptr;
template<typename T>
LinkedList<T> *GarbageCollector<T>::list = nullptr;
template<typename T>
int GarbageCollector<T>::length = 0;
template<typename T>
bool GarbageCollector<T>::firstIter = true;
template<typename T>
bool GarbageCollector<T>::finished = false;
template<typename T>
bool GarbageCollector<T>::stopThread = false;

template<typename T>
void GarbageCollector<T>::init() {
    cout << "   ***   ENTRANDO AL MÉTODO init()!   ***" << endl;
    GarbageCollector::inst_ = GarbageCollector::getInstance();

    //EJECUCIÓN DE THREAD
    GarbageCollector<T>::threadOn();
}
template<typename T>
GarbageCollector<T>::GarbageCollector() {
    value_ = 0;
}

template<typename T>
GarbageCollector<T> *GarbageCollector<T>::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new GarbageCollector();
        list = new LinkedList<T>();
    }
    return inst_;
}
template<typename T>
LinkedList<T> *GarbageCollector<T>::getList() {
    return list;
}
template<typename T>
void GarbageCollector<T>::deleteInst(){
    cout << "\n********        ********        ********        ********         ********        ********        "
            "********        ********        ********       ********        ******** " << endl;

    cout << "\n\n----->   Borrando lista: " << list << endl;
    cout << "----->   Borrando instancia de GarbageCollector: " << inst_ << endl;

    delete GarbageCollector<T>::getList();
    delete GarbageCollector<T>::getInstance();
    list = nullptr;
    inst_ = nullptr;

    cout << "\n\n----->   Borrando lista: " << list << endl;
    cout << "----->   Borrando instancia de GarbageCollector: " << inst_ << endl;
}

template<typename T>
int GarbageCollector<T>::getValue() {
    return value_;
}
template<typename T>
bool GarbageCollector<T>::getIter() {
    return firstIter;
}
template<typename T>
bool GarbageCollector<T>::getFinished() {
    return finished;
}
template<typename T>
bool GarbageCollector<T>::getStopThread() {
    return stopThread;
}

template<typename T>
void GarbageCollector<T>::setValue(int val) {
    value_ = val;
}

template<typename T>
void GarbageCollector<T>::executeThread(){
    while(!stopThread) {
        if(GarbageCollector<T>::inst_ == nullptr){
            break;
        }else {
            GarbageCollector::length = GarbageCollector<T>::getList()->getLength();

            cout << endl << "****************************************************"
                            "**************************************************** " << endl;
            cout << "       EN EL WHILE DEL THREAD! " << endl;

            if (GarbageCollector::length == 0 && !firstIter) {
                stopThread = true;
            } else {
                firstIter = false;
                GarbageCollector<T>::getList()->display();
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    cout << endl << "****************************************************" << endl << endl;
    cout << "                 SALIENDO DEL THREAD                    " << endl;
    cout << endl << "****************************************************" << endl << endl;
}

template<typename T>
void GarbageCollector<T>::threadOn() {
    cout << endl << "   ***   EJECUTANDO THREAD!   ***   " << endl;

    thread t1(executeThread);

    t1.detach();

}