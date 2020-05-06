#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
#include "../Headers/GarbageCollector.h"
using std::cout;
using std::endl;
using std::thread;
using namespace std::literals::chrono_literals;

GarbageCollector *GarbageCollector::inst_ = nullptr;
template<typename T>
LinkedList<T> *GarbageCollector::list = nullptr;

int GarbageCollector::length = 0;
bool GarbageCollector::firstIter = true;
bool GarbageCollector::finished = false;
bool GarbageCollector::stopThread = false;

template<typename T>
void GarbageCollector::init() {
    cout << "   ***   ENTRANDO AL MÉTODO init()!   ***" << endl;
    GarbageCollector::inst_ = GarbageCollector::getInstance<T>();

    //EJECUCIÓN DE THREAD
    GarbageCollector::threadOn<T>();
}

GarbageCollector::GarbageCollector() {
    value_ = 0;
}
template<typename T>
GarbageCollector *GarbageCollector::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new GarbageCollector();
        list<T> = new LinkedList<T>();
    }
    return inst_;
}
template<typename T>
LinkedList<T> *GarbageCollector::getList() {
    return list<T>;
}
template<typename T>
void GarbageCollector::deleteInst(){
    cout << "\n********        ********        ********        ********         ********        ********        "
            "********        ********        ********       ********        ******** " << endl;

    cout << "\n\n----->   Borrando lista: " << list<T> << endl;
    cout << "----->   Borrando instancia de GarbageCollector: " << inst_ << endl;

    delete GarbageCollector::getList<T>();
    delete GarbageCollector::getInstance<T>();
    list<T> = nullptr;
    inst_ = nullptr;

    cout << "\n\n----->   Borrando lista: " << list<T> << endl;
    cout << "----->   Borrando instancia de GarbageCollector: " << inst_ << endl;
}

int GarbageCollector::getValue() {
    return value_;
}
bool GarbageCollector::getIter() {
    return firstIter;
}
bool GarbageCollector::getFinished() {
    return finished;
}
bool GarbageCollector::getStopThread() {
    return stopThread;
}
void GarbageCollector::setValue(int val) {
    value_ = val;
}

template<typename T>
void GarbageCollector::executeThread(){
    while(!stopThread) {
        if(GarbageCollector::inst_ == nullptr){
            break;
        }else {
            GarbageCollector::length = GarbageCollector::getList<T>()->getLength();

            cout << endl << "****************************************************"
                            "**************************************************** " << endl;
            cout << "       EN EL WHILE DEL THREAD! " << endl;

            if (GarbageCollector::length == 0 && !firstIter) {
                stopThread = true;
            } else {
                firstIter = false;
                GarbageCollector::getList<T>()->display();
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

    cout << endl << "****************************************************" << endl << endl;
    cout << "                 SALIENDO DEL THREAD                    " << endl;
    cout << endl << "****************************************************" << endl << endl;
}
template<typename T>
void GarbageCollector::threadOn() {
    cout << endl << "   ***   EJECUTANDO THREAD!   ***   " << endl;

    thread t1(executeThread<T>);

    t1.detach();

}