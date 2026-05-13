#include "self_test.h"
#include "../src/hash_table/hash_table_chaining.h"
#include "../src/hash_table/hash_table_open_addressing.h"

static void test_chaining(void) {
    printf("  [Chaining Hash Table]\n");

    HashTableChaining *ht = htc_create(7);
    ASSERT_NOT_NULL(ht);
    ASSERT_EQ(ht->count, 0);
    ASSERT_TRUE(htc_load_factor(ht) < 0.001f);

    ASSERT_EQ(htc_insert(ht, 10), 1);
    ASSERT_EQ(htc_insert(ht, 20), 1);
    ASSERT_EQ(htc_insert(ht, 15), 1);
    ASSERT_EQ(ht->count, 3);

    ASSERT_NOT_NULL(htc_search(ht, 10));
    ASSERT_NOT_NULL(htc_search(ht, 20));
    ASSERT_NOT_NULL(htc_search(ht, 15));
    ASSERT_NULL(htc_search(ht, 99));

    ASSERT_EQ(htc_search(ht, 10)->key, 10);
    ASSERT_EQ(htc_search(ht, 20)->key, 20);

    ASSERT_EQ(htc_delete(ht, 20), 1);
    ASSERT_NULL(htc_search(ht, 20));
    ASSERT_EQ(ht->count, 2);

    ASSERT_EQ(htc_delete(ht, 20), 0);

    ASSERT_EQ(htc_delete(ht, 10), 1);
    ASSERT_EQ(htc_delete(ht, 15), 1);
    ASSERT_EQ(ht->count, 0);
    ASSERT_TRUE(htc_load_factor(ht) < 0.001f);

    htc_destroy(ht);
}

static void test_open_addressing(void) {
    printf("  [Open Addressing Hash Table]\n");

    HashTableOA *ht = htoa_create(11);
    ASSERT_NOT_NULL(ht);
    ASSERT_EQ(ht->count, 0);
    ASSERT_TRUE(htoa_load_factor(ht) < 0.001f);

    ASSERT_EQ(htoa_insert(ht, 10), 1);
    ASSERT_EQ(htoa_insert(ht, 20), 1);
    ASSERT_EQ(htoa_insert(ht, 30), 1);
    ASSERT_EQ(ht->count, 3);

    ASSERT_TRUE(htoa_search(ht, 10) >= 0);
    ASSERT_TRUE(htoa_search(ht, 20) >= 0);
    ASSERT_TRUE(htoa_search(ht, 30) >= 0);
    ASSERT_TRUE(htoa_search(ht, 99) < 0);

    ASSERT_EQ(htoa_delete(ht, 20), 1);
    ASSERT_TRUE(htoa_search(ht, 20) < 0);
    ASSERT_EQ(ht->count, 2);

    ASSERT_EQ(htoa_delete(ht, 20), 0);

    ASSERT_EQ(htoa_delete(ht, 10), 1);
    ASSERT_EQ(htoa_delete(ht, 30), 1);
    ASSERT_EQ(ht->count, 0);
    ASSERT_TRUE(htoa_load_factor(ht) < 0.001f);

    htoa_destroy(ht);
}

int main(void) {
    TEST_BEGIN("Hash Table");

    test_chaining();
    test_open_addressing();

    TEST_END();
}
