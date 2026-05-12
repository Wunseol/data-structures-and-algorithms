#ifndef HASH_TABLE_CHAINING_H
#define HASH_TABLE_CHAINING_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct HashNode {
    KeyType key;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    int size;
    int count;
} HashTableChaining;

HashTableChaining *htc_create(int size);
int htc_insert(HashTableChaining *ht, KeyType key);
HashNode *htc_search(HashTableChaining *ht, KeyType key);
int htc_delete(HashTableChaining *ht, KeyType key);
void htc_traverse(HashTableChaining *ht);
void htc_destroy(HashTableChaining *ht);
float htc_load_factor(HashTableChaining *ht);

#endif
