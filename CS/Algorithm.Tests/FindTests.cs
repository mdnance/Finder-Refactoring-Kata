﻿using System;
using System.Collections.Generic;
using Xunit;

namespace Algorithm.Tests
{    
    public class FindTests
    {
        [Fact]
        public void Returns_Empty_Results_When_Given_Empty_List()
        {
            var list = new List<Thing>();
            var finder = new Find(list);

            var result = finder.Finder(FT.One);

            Assert.Null(result.P1);
            Assert.Null(result.P2);
        }

        [Fact]
        public void Returns_Empty_Results_When_Given_One_FT()
        {
            var list = new List<Thing>() { sue };
            var finder = new Find(list);

            var result = finder.Finder(FT.One);

            Assert.Null(result.P1);
            Assert.Null(result.P2);
        }

        [Fact]
        public void Returns_One_Two_For_Two_FTs()
        {
            var list = new List<Thing>() { sue, greg };
            var finder = new Find(list);

            var result = finder.Finder(FT.One);

            Assert.Same(sue, result.P1);
            Assert.Same(greg, result.P2);
        }

        [Fact]
        public void Returns_Two_Two_For_Two_FTs()
        {
            var list = new List<Thing>() { greg, mike };
            var finder = new Find(list);

            var result = finder.Finder(FT.Two);

            Assert.Same(greg, result.P1);
            Assert.Same(mike, result.P2);
        }

        [Fact]
        public void Returns_Two_Two_For_Four_FTs()
        {
            var list = new List<Thing>() { greg, mike, sarah, sue };
            var finder = new Find(list);

            var result = finder.Finder(FT.Two);

            Assert.Same(sue, result.P1);
            Assert.Same(sarah, result.P2);
        }

        [Fact]
        public void Returns_One_Two_For_Four_FTs()
        {
            var list = new List<Thing>() { greg, mike, sarah, sue };
            var finder = new Find(list);

            var result = finder.Finder(FT.One);

            Assert.Same(sue, result.P1);
            Assert.Same(greg, result.P2);
        }

        Thing sue = new Thing() {NameString = "Sue", BirthDate = new DateTime(1950, 1, 1)};
        Thing greg = new Thing() {NameString = "Greg", BirthDate = new DateTime(1952, 6, 1)};
        Thing sarah = new Thing() { NameString = "Sarah", BirthDate = new DateTime(1982, 1, 1) };
        Thing mike = new Thing() { NameString = "Mike", BirthDate = new DateTime(1979, 1, 1) };
    }
}