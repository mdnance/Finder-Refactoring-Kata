#include "finder.h"
#include <stdlib.h>

void initializeList(List *list, int size)
{
    list->p = malloc(size * sizeof(Thing *));
    list->size = size;
}

void destroyList(List *list)
{
    free(list->p);
}

Finder *createFinder(List *p)
{
    Finder *finder = malloc(sizeof(Finder));
    finder->_p = p;
    return finder;
}

void destroyFinder(Finder *finder)
{
    free(finder);
}

F *find(Finder *finder, FT ft)
{
    List *tr = malloc(sizeof(List));
    initializeList(tr, finder->_p->size * (finder->_p->size - 1) / 2);

    for (int i = 0; i < finder->_p->size - 1; i++)
    {
        for (int j = i + 1; j < finder->_p->size; j++)
        {
            F *r = createF();
            if (finder->_p->p[i]->birthDate < finder->_p->p[j]->birthDate)
            {
                r->P1 = finder->_p->p[i];
                r->P2 = finder->_p->p[j];
            }
            else
            {
                r->P1 = finder->_p->p[j];
                r->P2 = finder->_p->p[i];
            }
            r->D = r->P2->birthDate - r->P1->birthDate;
            tr->p[(i * (2 * finder->_p->size - i - 1)) / 2 + (j - i - 1)] = r;
        }
    }

    if (tr->size < 1)
    {
        F *emptyF = createF();
        destroyList(tr);
        return emptyF;
    }

    F *answer = tr->p[0];
    for (int k = 1; k < tr->size; k++)
    {
        F *result = tr->p[k];
        switch (ft)
        {
        case One:
            if (result->D < answer->D)
            {
                answer = result;
            }
            break;

        case Two:
            if (result->D > answer->D)
            {
                answer = result;
            }
            break;
        }
    }

    destroyList(tr);
    return answer;
}
