#include "skip_list.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

SkipList::SkipList()
{
    header_ = CreateNode(0, 0, SKIPLIST_MAX_LEVEL);
    level_ = 0;
    for (int i = 0; i < SKIPLIST_MAX_LEVEL; i++) {
        header_->forward[i] = nullptr;
    }
    srand(static_cast<unsigned>(time(nullptr)));
}

SkipList::~SkipList()
{
    Destroy();
}

SkipNode *SkipList::CreateNode(int key, int value, int level)
{
    SkipNode *node = new SkipNode;
    node->key = key;
    node->value = value;
    node->forward = new SkipNode *[level];
    for (int i = 0; i < level; i++) {
        node->forward[i] = nullptr;
    }
    return node;
}

int SkipList::RandomLevel()
{
    int lvl = 1;
    while ((rand() & 1) && lvl < SKIPLIST_MAX_LEVEL) {
        lvl++;
    }
    return lvl;
}

void SkipList::Insert(int key, int value)
{
    SkipNode *update[SKIPLIST_MAX_LEVEL];
    SkipNode *cur = header_;

    for (int i = level_ - 1; i >= 0; i--) {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
            cur = cur->forward[i];
        }
        update[i] = cur;
    }

    cur = cur->forward[0];

    if (cur != nullptr && cur->key == key) {
        cur->value = value;
        return;
    }

    int newLevel = RandomLevel();
    if (newLevel > level_) {
        for (int i = level_; i < newLevel; i++) {
            update[i] = header_;
        }
        level_ = newLevel;
    }

    SkipNode *newNode = CreateNode(key, value, newLevel);
    for (int i = 0; i < newLevel; i++) {
        newNode->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = newNode;
    }
}

bool SkipList::Search(int key, int &value)
{
    SkipNode *cur = header_;
    for (int i = level_ - 1; i >= 0; i--) {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
            cur = cur->forward[i];
        }
    }
    cur = cur->forward[0];
    if (cur != nullptr && cur->key == key) {
        value = cur->value;
        return true;
    }
    return false;
}

bool SkipList::Delete(int key)
{
    SkipNode *update[SKIPLIST_MAX_LEVEL];
    SkipNode *cur = header_;

    for (int i = level_ - 1; i >= 0; i--) {
        while (cur->forward[i] != nullptr && cur->forward[i]->key < key) {
            cur = cur->forward[i];
        }
        update[i] = cur;
    }

    cur = cur->forward[0];

    if (cur == nullptr || cur->key != key) {
        return false;
    }

    for (int i = 0; i < level_; i++) {
        if (update[i]->forward[i] != cur) {
            break;
        }
        update[i]->forward[i] = cur->forward[i];
    }

    delete[] cur->forward;
    delete cur;

    while (level_ > 1 && header_->forward[level_ - 1] == nullptr) {
        level_--;
    }

    return true;
}

void SkipList::Display() const
{
    for (int i = level_ - 1; i >= 0; i--) {
        SkipNode *cur = header_->forward[i];
        printf("Level %d: ", i);
        while (cur != nullptr) {
            printf("%d ", cur->key);
            cur = cur->forward[i];
        }
        printf("\n");
    }
}

void SkipList::Destroy()
{
    SkipNode *cur = header_;
    while (cur != nullptr) {
        SkipNode *next = cur->forward[0];
        delete[] cur->forward;
        delete cur;
        cur = next;
    }
    header_ = nullptr;
    level_ = 0;
}
