"""并查集（Union-Find / Disjoint Set Union）

核心操作复杂度：
  find:      O(α(n)) 近似 O(1)
  union:     O(α(n)) 近似 O(1)
  connected: O(α(n)) 近似 O(1)
  count:     O(1)

包含路径压缩和按秩合并优化。
对应 C/C++ 源码路径：src/graph/union_find/
"""

from __future__ import annotations


class UnionFind:
    def __init__(self, n: int) -> None:
        self._parent: list[int] = list(range(n))
        self._rank: list[int] = [0] * n
        self._count: int = n

    def find(self, x: int) -> int:
        if self._parent[x] != x:
            self._parent[x] = self.find(self._parent[x])
        return self._parent[x]

    def union(self, x: int, y: int) -> None:
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x == root_y:
            return
        if self._rank[root_x] < self._rank[root_y]:
            self._parent[root_x] = root_y
        elif self._rank[root_x] > self._rank[root_y]:
            self._parent[root_y] = root_x
        else:
            self._parent[root_y] = root_x
            self._rank[root_x] += 1
        self._count -= 1

    def connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def count(self) -> int:
        return self._count


if __name__ == "__main__":
    uf = UnionFind(10)
    uf.union(1, 2)
    uf.union(2, 3)
    uf.union(4, 5)

    print(f"connected(1, 3) = {uf.connected(1, 3)}")
    print(f"connected(1, 4) = {uf.connected(1, 4)}")
    print(f"count = {uf.count()}")

    uf.union(3, 4)
    print(f"After union(3,4), connected(1, 5) = {uf.connected(1, 5)}")
    print(f"count = {uf.count()}")
