from .thing import Thing
from .ft import FT
from .f import F


class Finder:
    def __init__(self, p: list[Thing]):
        self._p = p

    def find(self, ft: FT):
        tr = []

        for i in range(len(self._p)-1):
            for j in range(i+1, len(self._p)):
                r = F()
                if self._p[i].birthdate < self._p[j].birthdate:
                    r.p1 = self._p[i]
                    r.p2 = self._p[j]
                else:
                    r.p1 = self._p[j]
                    r.p2 = self._p[i]
                r.d = (r.p2.birthdate - r.p1.birthdate).total_seconds()
                tr.append(r)

        if len(tr) < 1:
            return F()

        answer = tr[0]
        for result in tr:
            if ft == FT.One:
                if result.d < answer.d:
                    answer = result

            elif ft == FT.Two:
                if result.d > answer.d:
                    answer = result

        return answer
