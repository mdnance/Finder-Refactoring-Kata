#ifndef FINDER_H
#define FINDER_H

#include "f.h"
#include "ft.h"
#include "thing.h"

typedef struct
{
    Thing **p;
    int size;
} List;

typedef struct
{
    List *_p;
} Finder;

void initializeList(List *list, int size);
void destroyList(List *list);

Finder *createFinder(List *p);
void destroyFinder(Finder *finder);

F *find(Finder *finder, FT ft);

#endif /* FINDER_H */
