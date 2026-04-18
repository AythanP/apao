#ifndef SuperSuperInt_H
#define SuperSuperInt_H

#include "SuperInt.h"
#include <cstdlib>

class SuperSuperInt : public SuperInt {
    public:
        SuperSuperInt(int init, const char *name);

        ~SuperSuperInt();

        const int& theValue(void);
    private:
        SuperSuperInt();
};

#endif