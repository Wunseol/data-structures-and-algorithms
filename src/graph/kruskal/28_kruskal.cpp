#include "28_kruskal.h"
#include <algorithm>

class UnionFind {
public:
    explicit UnionFind(int n) : parent_(n), rank_(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
        }
    }

    int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) {
            return false;
        }
        if (rank_[rx] < rank_[ry]) {
            parent_[rx] = ry;
        } else if (rank_[rx] > rank_[ry]) {
            parent_[ry] = rx;
        } else {
            parent_[ry] = rx;
            ++rank_[rx];
        }
        return true;
    }

private:
    std::vector<int> parent_;
    std::vector<int> rank_;
};

int kruskal(int n, const std::vector<std::tuple<int,int,int>>& edges) {
    auto sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(),
              [](const auto& a, const auto& b) { return std::get<2>(a) < std::get<2>(b); });

    UnionFind uf(n);
    int totalWeight = 0;
    int edgeCount = 0;

    for (auto [u, v, w] : sortedEdges) {
        if (uf.unite(u, v)) {
            totalWeight += w;
            ++edgeCount;
            if (edgeCount == n - 1) {
                break;
            }
        }
    }

    return totalWeight;
}
