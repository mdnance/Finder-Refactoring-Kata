#include "thing.h"
#include <stdlib.h>
#include <string.h>

Thing *createThing(const char *name, long long birthDate)
{
    Thing *thing = malloc(sizeof(Thing));
    thing->name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(thing->name, name);
    thing->birthDate = birthDate;
    return thing;
}

void destroyThing(Thing *thing)
{
    free(thing->name);
    free(thing);
}
