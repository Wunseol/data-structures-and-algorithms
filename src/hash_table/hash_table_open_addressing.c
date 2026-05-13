#include "hash_table_open_addressing.h"

static int hash_oa(int key, int size) {
    return key % size;
}

HashTableOA *htoa_create(int size) {
    HashTableOA *ht = (HashTableOA *)malloc(sizeof(HashTableOA));
    if (!ht) return NULL;
    ht->slots = (HashSlot *)malloc(size * sizeof(HashSlot));
    if (!ht->slots) {
        free(ht);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        ht->slots[i].status = EMPTY;
    }
    ht->size = size;
    ht->count = 0;
    return ht;
}

int htoa_insert(HashTableOA *ht, KeyTypeOA key) {
    if (!ht) return 0;
    int h = hash_oa(key, ht->size);
    int first_deleted = -1;
    for (int i = 0; i < ht->size; i++) {
        int idx = (h + i) % ht->size;
        if (ht->slots[idx].status == OCCUPIED) {
            if (ht->slots[idx].key == key) return 0;
        } else if (ht->slots[idx].status == DELETED) {
            if (first_deleted == -1) first_deleted = idx;
        } else {
            int insert_idx = (first_deleted != -1) ? first_deleted : idx;
            ht->slots[insert_idx].key = key;
            ht->slots[insert_idx].status = OCCUPIED;
            ht->count++;
            return 1;
        }
    }
    if (first_deleted != -1) {
        ht->slots[first_deleted].key = key;
        ht->slots[first_deleted].status = OCCUPIED;
        ht->count++;
        return 1;
    }
    return 0;
}

int htoa_search(HashTableOA *ht, KeyTypeOA key) {
    if (!ht) return -1;
    int h = hash_oa(key, ht->size);
    for (int i = 0; i < ht->size; i++) {
        int idx = (h + i) % ht->size;
        if (ht->slots[idx].status == EMPTY) return -1;
        if (ht->slots[idx].status == OCCUPIED && ht->slots[idx].key == key)
            return idx;
    }
    return -1;
}

int htoa_delete(HashTableOA *ht, KeyTypeOA key) {
    if (!ht) return 0;
    int pos = htoa_search(ht, key);
    if (pos == -1) return 0;
    ht->slots[pos].status = DELETED;
    ht->count--;
    return 1;
}

void htoa_traverse(HashTableOA *ht) {
    if (!ht) return;
    for (int i = 0; i < ht->size; i++) {
        printf("Slot[%d]: ", i);
        if (ht->slots[i].status == EMPTY)
            printf("EMPTY");
        else if (ht->slots[i].status == DELETED)
            printf("DELETED");
        else
            printf("%d (OCCUPIED)", ht->slots[i].key);
        printf("\n");
    }
}

void htoa_destroy(HashTableOA *ht) {
    if (!ht) return;
    free(ht->slots);
    free(ht);
}

float htoa_load_factor(HashTableOA *ht) {
    if (!ht || ht->size == 0) return 0.0f;
    return (float)ht->count / ht->size;
}
