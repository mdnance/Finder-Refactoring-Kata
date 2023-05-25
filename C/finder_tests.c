#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <cmocka.h>
#include <stdlib.h>
#include "finder.h"

static void test_EmptyResultsWhenGivenEmptyList(void** state)
{
    List p;
    p.p = NULL;
    p.size = 0;

    Finder* finder = createFinder(&p);
    F* result = find(finder, One);

    assert_null(result->P1);
    assert_null(result->P2);

    destroyFinder(finder);
}

static void test_EmptyResultsWhenGivenOneFT(void** state)
{
    List p;
    p.p = malloc(sizeof(Thing*));
    p.p[0] = createThing("Sue", 50);
    p.size = 1;

    Finder* finder = createFinder(&p);
    F* result = find(finder, One);

    assert_null(result->P1);
    assert_null(result->P2);

    destroyFinder(finder);
    destroyThing(p.p[0]);
    free(p.p);
}

static void test_OneTwoForTwoFTs(void** state)
{
    List p;
    p.p = malloc(2 * sizeof(Thing*));
    p.p[0] = createThing("Sue", 50);
    p.p[1] = createThing("Greg", 52);
    p.size = 2;

    Finder* finder = createFinder(&p);
    F* result = find(finder, One);

    assert_string_equal(result->P1->name, "Sue");
    assert_string_equal(result->P2->name, "Greg");

    destroyFinder(finder);
    destroyThing(p.p[0]);
    destroyThing(p.p[1]);
    free(p.p);
}

static void test_TwoTwoForTwoFTs(void** state)
{
    List p;
    p.p = malloc(2 * sizeof(Thing*));
    p.p[0] = createThing("Mike", 79);
    p.p[1] = createThing("Greg", 52);
    p.size = 2;

    Finder* finder = createFinder(&p);
    F* result = find(finder, Two);

    assert_string_equal(result->P1->name, "Greg");
    assert_string_equal(result->P2->name, "Mike");

    destroyFinder(finder);
    destroyThing(p.p[0]);
    destroyThing(p.p[1]);
    free(p.p);
}

static void test_TwoTwoForFourFTs(void** state)
{
    List p;
    p.p = malloc(4 * sizeof(Thing*));
    p.p[0] = createThing("Sue", 50);
    p.p[1] = createThing("Sarah", 82);
    p.p[2] = createThing("Mike", 79);
    p.p[3] = createThing("Greg", 52);
    p.size = 4;

    Finder* finder = createFinder(&p);
    F* result = find(finder, Two);

    assert_string_equal(result->P1->name, "Sue");
    assert_string_equal(result->P2->name, "Sarah");

    destroyFinder(finder);
    destroyThing(p.p[0]);
    destroyThing(p.p[1]);
    destroyThing(p.p[2]);
    destroyThing(p.p[3]);
    free(p.p);
}

static void test_OneTwoForFourFTs(void** state)
{
    List p;
    p.p = malloc(4 * sizeof(Thing*));
    p.p[0] = createThing("Sue", 50);
    p.p[1] = createThing("Sarah", 82);
    p.p[2] = createThing("Mike", 79);
    p.p[3] = createThing("Greg", 52);
    p.size = 4;

    Finder* finder = createFinder(&p);
    F* result = find(finder, One);

    assert_string_equal(result->P1->name, "Sue");
    assert_string_equal(result->P2->name, "Greg");

    destroyFinder(finder);
    destroyThing(p.p[0]);
    destroyThing(p.p[1]);
    destroyThing(p.p[2]);
    destroyThing(p.p[3]);
    free(p.p);
}

static const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_EmptyResultsWhenGivenEmptyList),
    cmocka_unit_test(test_EmptyResultsWhenGivenOneFT),
    cmocka_unit_test(test_OneTwoForTwoFTs),
    cmocka_unit_test(test_TwoTwoForTwoFTs),
    cmocka_unit_test(test_TwoTwoForFourFTs),
    cmocka_unit_test(test_OneTwoForFourFTs),
};

int main(void)
{
    return cmocka_run_group_tests(tests, NULL, NULL);
}
