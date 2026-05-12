#ifndef SELF_TEST_H
#define SELF_TEST_H

#include <stdio.h>
#include <stdlib.h>

static int __test_count = 0;
static int __test_pass = 0;
static int __test_fail = 0;

#define ASSERT_EQ(actual, expected) do { \
    __test_count++; \
    if ((actual) == (expected)) { \
        __test_pass++; \
    } else { \
        __test_fail++; \
        fprintf(stderr, "  FAIL: %s:%d: ASSERT_EQ(%s, %s) => actual=%d, expected=%d\n", \
            __FILE__, __LINE__, #actual, #expected, (int)(actual), (int)(expected)); \
    } \
} while(0)

#define ASSERT_TRUE(condition) do { \
    __test_count++; \
    if (condition) { \
        __test_pass++; \
    } else { \
        __test_fail++; \
        fprintf(stderr, "  FAIL: %s:%d: ASSERT_TRUE(%s)\n", \
            __FILE__, __LINE__, #condition); \
    } \
} while(0)

#define ASSERT_FALSE(condition) do { \
    __test_count++; \
    if (!(condition)) { \
        __test_pass++; \
    } else { \
        __test_fail++; \
        fprintf(stderr, "  FAIL: %s:%d: ASSERT_FALSE(%s)\n", \
            __FILE__, __LINE__, #condition); \
    } \
} while(0)

#define ASSERT_NULL(ptr) do { \
    __test_count++; \
    if ((ptr) == NULL) { \
        __test_pass++; \
    } else { \
        __test_fail++; \
        fprintf(stderr, "  FAIL: %s:%d: ASSERT_NULL(%s)\n", \
            __FILE__, __LINE__, #ptr); \
    } \
} while(0)

#define ASSERT_NOT_NULL(ptr) do { \
    __test_count++; \
    if ((ptr) != NULL) { \
        __test_pass++; \
    } else { \
        __test_fail++; \
        fprintf(stderr, "  FAIL: %s:%d: ASSERT_NOT_NULL(%s)\n", \
            __FILE__, __LINE__, #ptr); \
    } \
} while(0)

#define TEST_BEGIN(name) \
    printf("Running tests: %s\n", name); \
    __test_count = 0; __test_pass = 0; __test_fail = 0;

#define TEST_END() \
    printf("  Results: %d/%d passed", __test_pass, __test_count); \
    if (__test_fail > 0) printf(", %d FAILED", __test_fail); \
    printf("\n"); \
    return __test_fail;

#endif
