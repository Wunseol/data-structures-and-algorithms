#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>

class FenwickTree {
public:
    explicit FenwickTree(int n);
    explicit FenwickTree(const std::vector<int> &data);

    void Update(int index, int delta);
    int Query(int index) const;
    int RangeQuery(int left, int right) const;

private:
    int n_;
    std::vector<int> tree_;

    int Lowbit(int x) const;
};

#endif
