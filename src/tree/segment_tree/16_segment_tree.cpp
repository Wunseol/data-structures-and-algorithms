#include "16_segment_tree.h"

SegmentTree::SegmentTree(const std::vector<int> &data)
{
    n_ = static_cast<int>(data.size());
    tree_.resize(4 * n_, 0);
    if (n_ > 0)
        Build(data, 1, 0, n_ - 1);
}

void SegmentTree::Build(const std::vector<int> &data, int node, int left, int right)
{
    if (left == right) {
        tree_[node] = data[left];
        return;
    }
    int mid = left + (right - left) / 2;
    Build(data, 2 * node, left, mid);
    Build(data, 2 * node + 1, mid + 1, right);
    tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
}

void SegmentTree::Update(int index, int value)
{
    if (index < 0 || index >= n_)
        return;
    UpdateHelper(1, 0, n_ - 1, index, value);
}

void SegmentTree::UpdateHelper(int node, int left, int right, int index, int value)
{
    if (left == right) {
        tree_[node] = value;
        return;
    }
    int mid = left + (right - left) / 2;
    if (index <= mid)
        UpdateHelper(2 * node, left, mid, index, value);
    else
        UpdateHelper(2 * node + 1, mid + 1, right, index, value);
    tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
}

int SegmentTree::Query(int left, int right) const
{
    if (left < 0 || right >= n_ || left > right)
        return 0;
    return QueryHelper(1, 0, n_ - 1, left, right);
}

int SegmentTree::QueryHelper(int node, int left, int right, int ql, int qr) const
{
    if (ql > right || qr < left)
        return 0;
    if (ql <= left && right <= qr)
        return tree_[node];
    int mid = left + (right - left) / 2;
    return QueryHelper(2 * node, left, mid, ql, qr) +
           QueryHelper(2 * node + 1, mid + 1, right, ql, qr);
}
