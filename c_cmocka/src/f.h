#ifndef F_H
#define F_H

#include "thing.h"

typedef struct
{
    Thing *P1;
    Thing *P2;
    long long D;
} F;

F *createF();
void destroyF(F *f);

#endif /* F_H */
