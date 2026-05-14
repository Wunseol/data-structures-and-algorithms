#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity);
    int Get(int key);
    void Put(int key, int value);

private:
    int capacity_;
    std::list<std::pair<int, int>> list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
};

#endif
