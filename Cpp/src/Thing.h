#pragma once
#include <string>
#include <chrono>
using namespace std::literals;

class Thing
{
public:
    std::string name;
    std::chrono::year_month_day birthDate;

    Thing(auto name, auto birthDate) : name(name), birthDate(birthDate)
    {
    }

    Thing() : name(""), birthDate(1900y, std::chrono::January, 1d) {}
};

inline bool operator==(const Thing &lhs, const Thing &rhs)
{
    return lhs.name==rhs.name && lhs.birthDate==rhs.birthDate;
}
