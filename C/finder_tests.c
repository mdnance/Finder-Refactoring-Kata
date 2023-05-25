#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "finder.h"

static void test_EmptyResultsWhenGivenEmptyList(void **state)
{
    List p;
    p.p = NULL;
    p.size = 0;

    Finder *finder = createFinder(&p);
    F *result = find(finder, One);

    assert_null(result->P1);
    assert_null(result->P2);

    destroyFinder(finder);
}

static void test_EmptyResultsWhenGivenOneFT(void **state)
{
    List p;
    p.p = malloc(sizeof(Thing *));
    p.p[0] = createThing("Sue", 50);
    p.size = 1;

    Finder *finder = createFinder(&p);
    F *result = find(finder, One);

    assert_null(result->P1);
    assert_null(result->P2);

    destroyFinder(finder);
    destroyThing(p.p[0]);
    free(p.p);
}

// TODO add the other test functions for the remaining test cases...

static const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_EmptyResultsWhenGivenEmptyList),
    cmocka_unit_test(test_EmptyResultsWhenGivenOneFT),
    // TODO add the other test functions to the test group...
};

int main(void)
{
    return cmocka_run_group_tests(tests, NULL, NULL);
}
