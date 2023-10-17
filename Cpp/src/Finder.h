#pragma once

#include <vector>

#include "Thing.h"
#include "FT.h"
#include "F.h"

class Finder {
    private:
     const std::vector<Thing> _p;

    public:
     Finder(std::vector<Thing> p) : _p(p) {}

     F Find(FT ft);

};