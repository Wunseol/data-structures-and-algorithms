"""Kruskal 最小生成树算法

核心操作复杂度：O(E log E)

对应 C/C++ 源码路径：src/graph/kruskal/
"""
from __future__ import annotations
from typing import List, Tuple


class _UnionFind:
    def __init__(self, n: int) -> None:
        self._parent: List[int] = list(range(n))
        self._rank: List[int] = [0] * n

    def find(self, x: int) -> int:
        if self._parent[x] != x:
            self._parent[x] = self.find(self._parent[x])
        return self._parent[x]

    def unite(self, x: int, y: int) -> bool:
        rx = self.find(x)
        ry = self.find(y)
        if rx == ry:
            return False
        if self._rank[rx] < self._rank[ry]:
            self._parent[rx] = ry
        elif self._rank[rx] > self._rank[ry]:
            self._parent[ry] = rx
        else:
            self._parent[ry] = rx
            self._rank[rx] += 1
        return True


def kruskal(n: int, edges: List[Tuple[int, int, int]]) -> int:
    sorted_edges = sorted(edges, key=lambda e: e[2])
    uf = _UnionFind(n)
    total_weight = 0
    edge_count = 0

    for u, v, w in sorted_edges:
        if uf.unite(u, v):
            total_weight += w
            edge_count += 1
            if edge_count == n - 1:
                break

    return total_weight


if __name__ == "__main__":
    edges: List[Tuple[int, int, int]] = [
        (0, 1, 10), (0, 2, 6), (0, 3, 5),
        (1, 3, 15), (2, 3, 4),
    ]
    result = kruskal(4, edges)
    print(f"最小生成树总权重: {result}")

    assert result == 19
