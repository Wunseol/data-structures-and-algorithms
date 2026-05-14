#include "20_lru_cache.h"

LRUCache::LRUCache(int capacity) : capacity_(capacity) {}

int LRUCache::Get(int key)
{
    auto it = map_.find(key);
    if (it == map_.end())
        return -1;
    list_.splice(list_.begin(), list_, it->second);
    return it->second->second;
}

void LRUCache::Put(int key, int value)
{
    auto it = map_.find(key);
    if (it != map_.end()) {
        it->second->second = value;
        list_.splice(list_.begin(), list_, it->second);
        return;
    }
    if (static_cast<int>(list_.size()) >= capacity_) {
        auto last = list_.back();
        map_.erase(last.first);
        list_.pop_back();
    }
    list_.emplace_front(key, value);
    map_[key] = list_.begin();
}
