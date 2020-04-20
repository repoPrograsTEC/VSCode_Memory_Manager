#include <iostream>
#include "../Headers/ReferenceCounter.h"

using std::cout;
using std::endl;

void RC::AddRef() {
    // Increment the reference refCount
    refCount++;
}
int RC::Release() {
    // Decrement the reference refCount and
    // return the reference refCount.
    int value = refCount;
    cout << endl << "       Disminuyendo RC de: " << refCount << " a: " << --value << endl;
    return --refCount;
}
int RC::getCount() {
    return refCount;
}

