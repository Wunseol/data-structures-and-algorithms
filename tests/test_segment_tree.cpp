#include "self_test.h"
#include "../src/tree/segment_tree/16_segment_tree.h"

static void test_basic_query(void) {
    printf("  [Basic Query]\n");
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);
    ASSERT_EQ(st.Query(0, 5), 36);
    ASSERT_EQ(st.Query(2, 4), 21);
    ASSERT_EQ(st.Query(0, 0), 1);
    ASSERT_EQ(st.Query(5, 5), 11);
}

static void test_update(void) {
    printf("  [Update]\n");
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree st(data);
    st.Update(2, 10);
    ASSERT_EQ(st.Query(2, 2), 10);
    ASSERT_EQ(st.Query(0, 5), 41);
}

static void test_single_element(void) {
    printf("  [Single Element]\n");
    std::vector<int> data = {42};
    SegmentTree st(data);
    ASSERT_EQ(st.Query(0, 0), 42);
    st.Update(0, 100);
    ASSERT_EQ(st.Query(0, 0), 100);
}

int main(void) {
    TEST_BEGIN("Segment Tree");
    test_basic_query();
    test_update();
    test_single_element();
    TEST_END();
}
