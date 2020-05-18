#include "../Headers/ReferenceCounter.h"

void RC::AddRef() {
    // Increment the reference refCount
    refCount++;
}
int RC::Release() {
    // Decrement the reference refCount and
    // return the reference refCount.
    int value = refCount;
    return --refCount;
}
int RC::getCount() {
    return refCount;
}

