#include "17_fenwick_tree.h"

FenwickTree::FenwickTree(int n) : n_(n), tree_(n + 1, 0) {}

FenwickTree::FenwickTree(const std::vector<int> &data) : n_(static_cast<int>(data.size())), tree_(data.size() + 1, 0)
{
    for (int i = 0; i < n_; i++)
        Update(i + 1, data[i]);
}

int FenwickTree::Lowbit(int x) const
{
    return x & (-x);
}

void FenwickTree::Update(int index, int delta)
{
    while (index <= n_) {
        tree_[index] += delta;
        index += Lowbit(index);
    }
}

int FenwickTree::Query(int index) const
{
    int sum = 0;
    while (index > 0) {
        sum += tree_[index];
        index -= Lowbit(index);
    }
    return sum;
}

int FenwickTree::RangeQuery(int left, int right) const
{
    if (left > right)
        return 0;
    return Query(right) - Query(left - 1);
}
