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
LinkedList *GarbageCollector::list = nullptr;

int GarbageCollector::length = 0;
bool GarbageCollector::firstIter = true;
bool GarbageCollector::finished = false;
bool GarbageCollector::stopThread = false;
bool GarbageCollector::inDestructor = false;


void GarbageCollector::init() {
    cout << "   ***   ENTRANDO AL MÉTODO init()!   ***" << endl;
    GarbageCollector::inst_ = GarbageCollector::getInstance();

    //EJECUCIÓN DE THREAD
    GarbageCollector::threadOn();
}

GarbageCollector::GarbageCollector() {
    value_ = 0;
}
GarbageCollector *GarbageCollector::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new GarbageCollector();
        list = new LinkedList();
    }
    return inst_;
}
LinkedList *GarbageCollector::getList() {
    return list;
}

void GarbageCollector::deleteInst(){
    cout << "\n********        ********        ********        ********         ********        ********        "
            "********        ********        ********       ********        ******** " << endl;

    cout << "\n\n----->   Borrando lista: " << list << endl;
    cout << "----->   Borrando instancia de GarbageCollector: " << inst_ << endl;

    delete GarbageCollector::getList();
    delete GarbageCollector::getInstance();
    list = nullptr;
    inst_ = nullptr;

    cout << "\n\n----->   Borrando lista: " << list << endl;
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
bool GarbageCollector::getBoolDestructor() {
    return inDestructor;
}
void GarbageCollector::setBoolDestructor() {
    GarbageCollector::inDestructor = true;
}
void GarbageCollector::setValue(int val) {
    value_ = val;
}

void GarbageCollector::executeThread(){
    while(!stopThread) {
        if(GarbageCollector::inst_ == nullptr){
            break;
        }else {
            GarbageCollector::length = GarbageCollector::getList()->getLength();

            cout << endl << "****************************************************"
                            "**************************************************** " << endl;
            cout << "       EN EL WHILE DEL THREAD! " << endl;

            if (GarbageCollector::length == 0 && !firstIter) {
                stopThread = true;
            } else {
                firstIter = false;
                if (!inDestructor) {
                    GarbageCollector::getList()->display();
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    cout << endl << "****************************************************" << endl << endl;
    cout << "                 SALIENDO DEL THREAD                    " << endl;
    cout << endl << "****************************************************" << endl << endl;
}

void GarbageCollector::threadOn() {
    cout << endl << "   ***   EJECUTANDO THREAD!   ***   " << endl;

    thread t1(executeThread);

    t1.detach();
}