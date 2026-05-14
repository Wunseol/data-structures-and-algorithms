#include "self_test.h"
#include "../src/hash_table/bloom_filter/19_bloom_filter.h"

static void test_add_and_contains(void) {
    printf("  [Add and Contains]\n");
    BloomFilter bf(1000, 3);
    bf.Add("hello");
    bf.Add("world");
    ASSERT_TRUE(bf.Contains("hello"));
    ASSERT_TRUE(bf.Contains("world"));
}

static void test_empty_filter(void) {
    printf("  [Empty Filter]\n");
    BloomFilter bf(1000, 3);
    ASSERT_FALSE(bf.Contains("anything"));
    ASSERT_FALSE(bf.Contains("hello"));
}

static void test_false_positive_rate(void) {
    printf("  [False Positive Rate]\n");
    BloomFilter bf(10000, 7);
    for (int i = 0; i < 1000; i++) {
        bf.Add("item" + std::to_string(i));
    }
    int false_positives = 0;
    for (int i = 1000; i < 2000; i++) {
        if (bf.Contains("item" + std::to_string(i))) {
            false_positives++;
        }
    }
    ASSERT_TRUE(false_positives < 50);
}

int main(void) {
    TEST_BEGIN("Bloom Filter");
    test_add_and_contains();
    test_empty_filter();
    test_false_positive_rate();
    TEST_END();
}
