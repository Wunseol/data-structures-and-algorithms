"""线段树（Segment Tree）

核心操作复杂度：
  build:  O(n)
  update: O(log n)
  query:  O(log n)

对应 C/C++ 源码路径：src/tree/segment_tree/
"""

from __future__ import annotations
from typing import List


class SegmentTree:
    def __init__(self, data: List[int]) -> None:
        self._data: List[int] = data[:]
        self._n: int = len(data)
        self._tree: List[int] = [0] * (4 * self._n)
        if self._n > 0:
            self._build(1, 0, self._n - 1)

    def _build(self, node: int, left: int, right: int) -> None:
        if left == right:
            self._tree[node] = self._data[left]
            return
        mid = left + (right - left) // 2
        self._build(2 * node, left, mid)
        self._build(2 * node + 1, mid + 1, right)
        self._tree[node] = self._tree[2 * node] + self._tree[2 * node + 1]

    def update(self, index: int, value: int) -> None:
        if index < 0 or index >= self._n:
            return
        self._data[index] = value
        self._update(1, 0, self._n - 1, index, value)

    def _update(self, node: int, left: int, right: int, index: int, value: int) -> None:
        if left == right:
            self._tree[node] = value
            return
        mid = left + (right - left) // 2
        if index <= mid:
            self._update(2 * node, left, mid, index, value)
        else:
            self._update(2 * node + 1, mid + 1, right, index, value)
        self._tree[node] = self._tree[2 * node] + self._tree[2 * node + 1]

    def query(self, left: int, right: int) -> int:
        if left < 0 or right >= self._n or left > right:
            return 0
        return self._query(1, 0, self._n - 1, left, right)

    def _query(self, node: int, left: int, right: int, ql: int, qr: int) -> int:
        if ql > right or qr < left:
            return 0
        if ql <= left and right <= qr:
            return self._tree[node]
        mid = left + (right - left) // 2
        return self._query(2 * node, left, mid, ql, qr) + self._query(
            2 * node + 1, mid + 1, right, ql, qr
        )

    def __str__(self) -> str:
        return f"SegmentTree(data={self._data})"


if __name__ == "__main__":
    data = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(data)

    print(f"初始数组: {data}")
    print(f"query(0, 5) = {st.query(0, 5)} (期望: 36)")
    print(f"query(1, 3) = {st.query(1, 3)} (期望: 15)")
    print(f"query(2, 4) = {st.query(2, 4)} (期望: 21)")

    st.update(1, 10)
    print(f"\nupdate(1, 10) 后:")
    print(f"query(0, 5) = {st.query(0, 5)} (期望: 43)")
    print(f"query(1, 3) = {st.query(1, 3)} (期望: 22)")

    st.update(3, 0)
    print(f"\nupdate(3, 0) 后:")
    print(f"query(0, 5) = {st.query(0, 5)} (期望: 36)")
    print(f"query(2, 4) = {st.query(2, 4)} (期望: 14)")

    print(f"\n{st}")
