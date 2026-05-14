#include "self_test.h"
#include "../src/tree/fenwick_tree/17_fenwick_tree.h"

static void test_basic_operations(void) {
    printf("  [Basic Operations]\n");
    FenwickTree ft(5);
    ft.Update(1, 1);
    ft.Update(2, 2);
    ft.Update(3, 3);
    ft.Update(4, 4);
    ft.Update(5, 5);
    ASSERT_EQ(ft.Query(5), 15);
    ASSERT_EQ(ft.Query(3), 6);
    ASSERT_EQ(ft.Query(1), 1);
}

static void test_range_query(void) {
    printf("  [Range Query]\n");
    FenwickTree ft(5);
    ft.Update(1, 1);
    ft.Update(2, 2);
    ft.Update(3, 3);
    ft.Update(4, 4);
    ft.Update(5, 5);
    ASSERT_EQ(ft.RangeQuery(2, 4), 9);
    ASSERT_EQ(ft.RangeQuery(1, 5), 15);
    ASSERT_EQ(ft.RangeQuery(3, 3), 3);
}

static void test_from_vector(void) {
    printf("  [From Vector]\n");
    std::vector<int> data = {10, 20, 30, 40, 50};
    FenwickTree ft(data);
    ASSERT_EQ(ft.Query(5), 150);
    ASSERT_EQ(ft.RangeQuery(2, 4), 90);
}

int main(void) {
    TEST_BEGIN("Fenwick Tree");
    test_basic_operations();
    test_range_query();
    test_from_vector();
    TEST_END();
}
