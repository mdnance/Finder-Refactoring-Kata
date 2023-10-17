#include <chrono>

#include "Finder.h"

F Finder::Find(FT ft)
{
    std::vector<F> tr;

    for (int i = 0; i < _p.size() - 1; i++)
    {
        for (int j = i + 1; j < _p.size(); j++)
        {
            F r;
            if (_p[i].birthDate < _p[j].birthDate)
            {
                r.P1 = _p[i];
                r.P2 = _p[j];
            }
            else
            {
                r.P1 = _p[j];
                r.P2 = _p[i];
            }
            r.D = std::chrono::sys_days(r.P2.birthDate) - std::chrono::sys_days(r.P1.birthDate);
            tr.push_back(r);
        }
    }

    if (tr.size() < 1)
    {
        return F();
    }

    F answer = tr[0];
    for (F result : tr)
    {
        switch (ft)
        {
        case One:
            if (result.D < answer.D)
            {
                answer = result;
            }
            break;

        case Two:
            if (result.D > answer.D)
            {
                answer = result;
            }
            break;
        }
    }

    return answer;
}
