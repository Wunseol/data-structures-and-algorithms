#include "self_test.h"
#include <string>
#include <vector>

int lcsDP(const std::string& s1, const std::string& s2);
int matrixChainOrder(const std::vector<int>& dims);

static void test_lcs_dp(void) {
    printf("  [LCS DP]\n");
    ASSERT_EQ(lcsDP("ABCBDAB", "BDCAB"), 4);
    ASSERT_EQ(lcsDP("AGGTAB", "GXTXAYB"), 4);
    ASSERT_EQ(lcsDP("", ""), 0);
    ASSERT_EQ(lcsDP("ABC", "DEF"), 0);
    ASSERT_EQ(lcsDP("ABC", "ABC"), 3);
}

static void test_matrix_chain(void) {
    printf("  [Matrix Chain]\n");
    ASSERT_EQ(matrixChainOrder({10, 30, 5, 60}), 4500);
    ASSERT_EQ(matrixChainOrder({40, 20, 30, 10, 30}), 26000);
    ASSERT_EQ(matrixChainOrder({10, 20}), 0);
}

int main(void) {
    TEST_BEGIN("Dynamic Programming");
    test_lcs_dp();
    test_matrix_chain();
    TEST_END();
}
