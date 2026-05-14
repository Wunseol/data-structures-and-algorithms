#include "19_bloom_filter.h"
#include <functional>

BloomFilter::BloomFilter(int size, int num_hashes)
    : num_hashes_(num_hashes), bits_(size, false)
{
}

size_t BloomFilter::HashWithSeed(const std::string &item, int seed) const
{
    std::hash<std::string> hasher;
    return hasher(std::to_string(seed) + item) % bits_.size();
}

void BloomFilter::Add(const std::string &item)
{
    for (int i = 0; i < num_hashes_; i++) {
        bits_[HashWithSeed(item, i)] = true;
    }
}

bool BloomFilter::Contains(const std::string &item) const
{
    for (int i = 0; i < num_hashes_; i++) {
        if (!bits_[HashWithSeed(item, i)])
            return false;
    }
    return true;
}
