#!/usr/bin/env python

from datetime import date
import unittest

from algorithm.ft import FT
from algorithm.finder import Finder
from algorithm.thing import Thing


class FinderTests(unittest.TestCase):

    def setUp(self):
        self.sue = Thing()
        self.greg = Thing()
        self.sarah = Thing()
        self.mike = Thing()
        self.sue.name = "Sue"
        self.sue.birthdate = date(1950, 1, 1)
        self.greg.name = "Greg"
        self.greg.birthdate = date(1952, 6, 1)
        self.sarah.name = "Sarah"
        self.sarah.birthdate = date(1982, 1, 1)
        self.mike.name = "Mike"
        self.mike.birthdate = date(1979, 1, 1)

    def test_returns_empty_results_when_given_empty_list(self):
        array = []
        finder = Finder(array)

        result = finder.find(FT.One)

        assert result.p1 is None
        assert result.p2 is None

    def test_returns_empty_results_when_given_one_ft(self):
        array = []
        array.append(self.sue)

        finder = Finder(array)

        result = finder.find(FT.One)

        assert result.p1 is None
        assert result.p2 is None

    def test_returns_one_two_for_two_fts(self):
        array = []
        array.append(self.sue)
        array.append(self.greg)
        finder = Finder(array)

        result = finder.find(FT.One)

        assert self.sue == result.p1
        assert self.greg == result.p2

    def test_returns_two_two_for_two_fts(self):
        array = []
        array.append(self.mike)
        array.append(self.greg)
        finder = Finder(array)

        result = finder.find(FT.Two)

        assert self.greg == result.p1
        assert self.mike == result.p2

    def test_returns_two_two_for_four_fts(self):
        array = []
        array.append(self.sue)
        array.append(self.sarah)
        array.append(self.mike)
        array.append(self.greg)
        finder = Finder(array)

        result = finder.find(FT.Two)

        assert self.sue == result.p1
        assert self.sarah == result.p2

    def test_returns_one_two_for_four_fts(self):
        array = []
        array.append(self.sue)
        array.append(self.sarah)
        array.append(self.mike)
        array.append(self.greg)
        finder = Finder(array)

        result = finder.find(FT.One)

        assert self.sue == result.p1
        assert self.greg == result.p2


if __name__ == "__main__":
    unittest.main()
