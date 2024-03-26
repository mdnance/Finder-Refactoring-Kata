#include "f.h"
#include <stdlib.h>

F *createF()
{
    F *f = malloc(sizeof(F));
    f->P1 = NULL;
    f->P2 = NULL;
    f->D = 0;
    return f;
}

void destroyF(F *f)
{
    free(f);
}
