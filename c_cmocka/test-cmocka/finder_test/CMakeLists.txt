project(finder-cmocka C)

add_cmocka_test(finder_test
        SOURCES finder_tests.c
        LINK_LIBRARIES src cmocka-static)
add_cmocka_test_environment(add_test)
