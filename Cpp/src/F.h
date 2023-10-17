#include <chrono>
#include "Thing.h"
#pragma once

class F
{
public:
    Thing *P1;
    Thing *P2;
    std::chrono::duration<long, std::ratio<86400, 1>> D;

public:
    F() : P1(NULL), P2(NULL){};
};
