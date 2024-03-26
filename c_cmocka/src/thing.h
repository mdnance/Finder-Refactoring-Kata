#ifndef THING_H
#define THING_H

typedef struct
{
    char *name;
    long long birthDate;
} Thing;

Thing *createThing(const char *name, long long birthDate);
void destroyThing(Thing *thing);

#endif /* THING_H */
