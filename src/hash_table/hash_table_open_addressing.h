#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyTypeOA;

typedef enum { EMPTY, OCCUPIED, DELETED } SlotStatus;

typedef struct {
    KeyTypeOA key;
    SlotStatus status;
} HashSlot;

typedef struct {
    HashSlot *slots;
    int size;
    int count;
} HashTableOA;

HashTableOA *htoa_create(int size);
int htoa_insert(HashTableOA *ht, KeyTypeOA key);
int htoa_search(HashTableOA *ht, KeyTypeOA key);
int htoa_delete(HashTableOA *ht, KeyTypeOA key);
void htoa_traverse(HashTableOA *ht);
void htoa_destroy(HashTableOA *ht);
float htoa_load_factor(HashTableOA *ht);

#endif
