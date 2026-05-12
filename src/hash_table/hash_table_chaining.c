#include "hash_table_chaining.h"

static int hash(int key, int size) {
    return key % size;
}

HashTableChaining *htc_create(int size) {
    HashTableChaining *ht = (HashTableChaining *)malloc(sizeof(HashTableChaining));
    if (!ht) return NULL;
    ht->buckets = (HashNode **)calloc(size, sizeof(HashNode *));
    if (!ht->buckets) {
        free(ht);
        return NULL;
    }
    ht->size = size;
    ht->count = 0;
    return ht;
}

int htc_insert(HashTableChaining *ht, KeyType key) {
    if (!ht) return 0;
    int idx = hash(key, ht->size);
    HashNode *cur = ht->buckets[idx];
    while (cur) {
        if (cur->key == key) return 0;
        cur = cur->next;
    }
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    if (!node) return 0;
    node->key = key;
    node->next = ht->buckets[idx];
    ht->buckets[idx] = node;
    ht->count++;
    return 1;
}

HashNode *htc_search(HashTableChaining *ht, KeyType key) {
    if (!ht) return NULL;
    int idx = hash(key, ht->size);
    HashNode *cur = ht->buckets[idx];
    while (cur) {
        if (cur->key == key) return cur;
        cur = cur->next;
    }
    return NULL;
}

int htc_delete(HashTableChaining *ht, KeyType key) {
    if (!ht) return 0;
    int idx = hash(key, ht->size);
    HashNode *cur = ht->buckets[idx];
    HashNode *prev = NULL;
    while (cur) {
        if (cur->key == key) {
            if (prev)
                prev->next = cur->next;
            else
                ht->buckets[idx] = cur->next;
            free(cur);
            ht->count--;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void htc_traverse(HashTableChaining *ht) {
    if (!ht) return;
    for (int i = 0; i < ht->size; i++) {
        printf("Bucket[%d]: ", i);
        HashNode *cur = ht->buckets[i];
        if (!cur) {
            printf("NULL");
        }
        while (cur) {
            printf("%d", cur->key);
            if (cur->next) printf(" -> ");
            cur = cur->next;
        }
        printf("\n");
    }
}

void htc_destroy(HashTableChaining *ht) {
    if (!ht) return;
    for (int i = 0; i < ht->size; i++) {
        HashNode *cur = ht->buckets[i];
        while (cur) {
            HashNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(ht->buckets);
    free(ht);
}

float htc_load_factor(HashTableChaining *ht) {
    if (!ht || ht->size == 0) return 0.0f;
    return (float)ht->count / ht->size;
}
