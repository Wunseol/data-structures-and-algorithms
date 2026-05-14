#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>

class SegmentTree {
public:
    explicit SegmentTree(const std::vector<int> &data);

    void Update(int index, int value);
    int Query(int left, int right) const;

private:
    std::vector<int> tree_;
    int n_;

    void Build(const std::vector<int> &data, int node, int left, int right);
    void UpdateHelper(int node, int left, int right, int index, int value);
    int QueryHelper(int node, int left, int right, int ql, int qr) const;
};

#endif
