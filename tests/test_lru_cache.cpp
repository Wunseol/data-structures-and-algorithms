#include "self_test.h"
#include "../src/cache/lru_cache/20_lru_cache.h"

static void test_basic_put_get(void) {
    printf("  [Basic Put/Get]\n");
    LRUCache cache(2);
    cache.Put(1, 10);
    cache.Put(2, 20);
    ASSERT_EQ(cache.Get(1), 10);
    ASSERT_EQ(cache.Get(2), 20);
}

static void test_eviction(void) {
    printf("  [Eviction]\n");
    LRUCache cache(2);
    cache.Put(1, 10);
    cache.Put(2, 20);
    cache.Put(3, 30);
    ASSERT_EQ(cache.Get(1), -1);
    ASSERT_EQ(cache.Get(2), 20);
    ASSERT_EQ(cache.Get(3), 30);
}

static void test_update_existing(void) {
    printf("  [Update Existing]\n");
    LRUCache cache(2);
    cache.Put(1, 10);
    cache.Put(2, 20);
    cache.Put(1, 100);
    ASSERT_EQ(cache.Get(1), 100);
    cache.Put(3, 30);
    ASSERT_EQ(cache.Get(2), -1);
    ASSERT_EQ(cache.Get(1), 100);
}

static void test_get_nonexistent(void) {
    printf("  [Get Nonexistent]\n");
    LRUCache cache(2);
    ASSERT_EQ(cache.Get(99), -1);
    cache.Put(1, 10);
    ASSERT_EQ(cache.Get(99), -1);
}

static void test_get_refreshes_order(void) {
    printf("  [Get Refreshes Order]\n");
    LRUCache cache(2);
    cache.Put(1, 10);
    cache.Put(2, 20);
    cache.Get(1);
    cache.Put(3, 30);
    ASSERT_EQ(cache.Get(1), 10);
    ASSERT_EQ(cache.Get(2), -1);
}

int main(void) {
    TEST_BEGIN("LRU Cache");
    test_basic_put_get();
    test_eviction();
    test_update_existing();
    test_get_nonexistent();
    test_get_refreshes_order();
    TEST_END();
}
