"""树状数组（Fenwick Tree / Binary Indexed Tree）

核心操作复杂度：
  update:      O(log n)
  query:       O(log n)
  range_query: O(log n)

对应 C/C++ 源码路径：src/tree/fenwick_tree/
"""

from __future__ import annotations
from typing import List


class FenwickTree:
    def __init__(self, n: int) -> None:
        self._n: int = n
        self._tree: List[int] = [0] * (n + 1)

    def update(self, index: int, delta: int) -> None:
        while index <= self._n:
            self._tree[index] += delta
            index += index & -index

    def query(self, index: int) -> int:
        s = 0
        while index > 0:
            s += self._tree[index]
            index -= index & -index
        return s

    def range_query(self, left: int, right: int) -> int:
        if left > right:
            return 0
        return self.query(right) - self.query(left - 1)

    def __str__(self) -> str:
        return f"FenwickTree(n={self._n}, tree={self._tree})"


if __name__ == "__main__":
    data = [1, 3, 5, 7, 9, 11]
    ft = FenwickTree(len(data))
    for i, val in enumerate(data):
        ft.update(i + 1, val)

    print(f"初始数组(1-based): {data}")
    print(f"query(1) = {ft.query(1)} (期望: 1)")
    print(f"query(3) = {ft.query(3)} (期望: 9)")
    print(f"query(6) = {ft.query(6)} (期望: 36)")
    print(f"range_query(2, 4) = {ft.range_query(2, 4)} (期望: 15)")
    print(f"range_query(1, 6) = {ft.range_query(1, 6)} (期望: 36)")

    ft.update(2, 7)
    print(f"\nupdate(2, +7) 后:")
    print(f"query(3) = {ft.query(3)} (期望: 16)")
    print(f"range_query(2, 4) = {ft.range_query(2, 4)} (期望: 22)")

    ft.update(5, -4)
    print(f"\nupdate(5, -4) 后:")
    print(f"query(6) = {ft.query(6)} (期望: 39)")
    print(f"range_query(3, 6) = {ft.range_query(3, 6)} (期望: 28)")

    print(f"\n{ft}")
