#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <vector>

class BloomFilter {
public:
    BloomFilter(int size, int num_hashes);
    void Add(const std::string &item);
    bool Contains(const std::string &item) const;

private:
    int num_hashes_;
    std::vector<bool> bits_;

    size_t HashWithSeed(const std::string &item, int seed) const;
};

#endif
