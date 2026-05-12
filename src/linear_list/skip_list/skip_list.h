#ifndef SKIP_LIST_H
#define SKIP_LIST_H

static constexpr int SKIPLIST_MAX_LEVEL = 16;

struct SkipNode {
    int key;
    int value;
    SkipNode **forward;
};

class SkipList {
public:
    SkipList();
    ~SkipList();

    void Insert(int key, int value);
    bool Search(int key, int &value);
    bool Delete(int key);
    void Display() const;
    void Destroy();

private:
    SkipNode *header_;
    int level_;

    int RandomLevel();
    SkipNode *CreateNode(int key, int value, int level);
};

#endif
