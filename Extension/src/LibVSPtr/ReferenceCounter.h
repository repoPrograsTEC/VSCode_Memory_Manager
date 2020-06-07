#ifndef VSPTR_REFERENCECOUNTER_H
#define VSPTR_REFERENCECOUNTER_H

class RC{
private:
    int refCount;
public:
    void AddRef();
    int Release();
    int getCount();
};

#endif
