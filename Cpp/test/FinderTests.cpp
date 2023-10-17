#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Finder.h"
using namespace std::chrono;

TEST_CASE("returns_Empty_Results_When_Given_Empty_List")
{
    std::vector<Thing> list{};
    Finder finder(list);

    F result = finder.Find(FT::One);

    CHECK_EQ(Thing(), result.P1);
    CHECK_EQ(Thing(), result.P2);
}

TEST_CASE("returns_Empty_Results_When_Given_One_FT")
{
    Thing sue("Sue", year_month_day(1950y, January, 1d));
    std::vector<Thing> list{sue};

    Finder finder(list);

    F result = finder.Find(FT::One);

    CHECK_EQ(Thing(), result.P1);
    CHECK_EQ(Thing(), result.P2);
}
TEST_CASE("returns_One_Two_For_Two_FTs")
{
    Thing sue{"Sue", std::chrono::year_month_day(1950y, January, 1d)};
    Thing greg{"Greg", std::chrono::year_month_day{1952y, May, 1d}};
    std::vector<Thing> list{sue, greg};
    Finder finder(list);

    F result = finder.Find(FT::One);

    CHECK_EQ(sue, result.P1);
    CHECK_EQ(greg, result.P2);
}

TEST_CASE("returns_Two_Two_For_Two_FTs")
{
    Thing mike{"Mike", std::chrono::year_month_day(1979y, January, 1d)};
    Thing greg{"Greg", std::chrono::year_month_day(1952y, May, 1d)};
    std::vector<Thing> list{mike, greg};
    Finder finder{list};

    F result = finder.Find(FT::Two);

    CHECK_EQ(greg, result.P1);
    CHECK_EQ(mike, result.P2);
}

TEST_CASE("returns_Two_Two_For_Four_FTs")
{
    Thing sue{"Sue", std::chrono::year_month_day{1950y, January, 1d}};
    Thing greg{"Greg", std::chrono::year_month_day{1952y, May, 1d}};
    Thing sarah{"Sarah", std::chrono::year_month_day{1982y, January, 1d}};
    Thing mike{"Mike", std::chrono::year_month_day{1979y, January, 1d}};
    std::vector<Thing> list{sue, sarah, mike, greg};
    Finder finder{list};

    F result = finder.Find(FT::Two);

    CHECK_EQ(sue, result.P1);
    CHECK_EQ(sarah, result.P2);
}

TEST_CASE("returns_One_Two_For_Four_FTs")
{
    Thing sue("Sue", std::chrono::year_month_day(1950y, January, 1d));
    Thing greg("Greg", std::chrono::year_month_day(1952y, May, 1d));
    Thing sarah("Sarah", std::chrono::year_month_day(1982y, January, 1d));
    Thing mike("Mike", std::chrono::year_month_day(1979y, January, 1d));
    std::vector<Thing> list{sue, sarah, mike, greg};
    Finder finder{list};

    F result = finder.Find(FT::One);

    CHECK_EQ(sue, result.P1);
    CHECK_EQ(greg, result.P2);
}