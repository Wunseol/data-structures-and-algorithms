#include "self_test.h"
#include <string>
#include <vector>

std::vector<int> zFunction(const std::string& s);
std::vector<int> zSearch(const std::string& text, const std::string& pattern);

static void test_z_function(void) {
    printf("  [Z Function]\n");
    auto z = zFunction("aabxaab");
    ASSERT_EQ(z[0], 7);
    ASSERT_EQ(z[1], 1);
    ASSERT_EQ(z[2], 0);
    ASSERT_EQ(z[3], 0);
    ASSERT_EQ(z[4], 3);
    ASSERT_EQ(z[5], 1);
    ASSERT_EQ(z[6], 0);
}

static void test_z_search(void) {
    printf("  [Z Search]\n");
    auto matches = zSearch("AABAACAADAABAABA", "AABA");
    ASSERT_EQ((int)matches.size(), 3);
    ASSERT_EQ(matches[0], 0);
    ASSERT_EQ(matches[1], 9);
    ASSERT_EQ(matches[2], 12);
}

static void test_z_single_char(void) {
    printf("  [Z Single Char]\n");
    auto z = zFunction("a");
    ASSERT_EQ(z[0], 1);
}

static void test_z_all_same(void) {
    printf("  [Z All Same]\n");
    auto z = zFunction("aaaa");
    ASSERT_EQ(z[0], 4);
    ASSERT_EQ(z[1], 3);
    ASSERT_EQ(z[2], 2);
    ASSERT_EQ(z[3], 1);
}

int main(void) {
    TEST_BEGIN("Z Algorithm");
    test_z_function();
    test_z_search();
    test_z_single_char();
    test_z_all_same();
    TEST_END();
}
