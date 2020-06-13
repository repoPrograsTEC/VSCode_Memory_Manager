#ifndef VSPTR_LIBRARY_H
#define VSPTR_LIBRARY_H
#include "VSPtr.h"
#include "GarbageCollector.h"

template<class T>
class VSPtr;

class GarbageCollector;

void Debbug();

extern "C" bool TestConection(const char* ip, int host);

extern "C" void sendData (const char* path, const char* user);

extern "C" void recvData(const char* path, const char* user);

#endif //VSPTR_LIBRARY_H
