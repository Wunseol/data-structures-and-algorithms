"""最大堆（Max Heap）

核心操作复杂度：
  insert:      O(log n)
  extract_max: O(log n)
  peek:        O(1)
  heapify:     O(n)

对应 C/C++ 源码路径：src/heap/max_heap/
"""

from __future__ import annotations
from typing import Any


class MaxHeap:
    def __init__(self) -> None:
        self._data: list[Any] = []

    def _parent(self, i: int) -> int:
        return (i - 1) // 2

    def _left(self, i: int) -> int:
        return 2 * i + 1

    def _right(self, i: int) -> int:
        return 2 * i + 2

    def _sift_up(self, i: int) -> None:
        while i > 0 and self._data[self._parent(i)] < self._data[i]:
            self._data[self._parent(i)], self._data[i] = self._data[i], self._data[self._parent(i)]
            i = self._parent(i)

    def _sift_down(self, i: int) -> None:
        size = len(self._data)
        while True:
            largest = i
            left = self._left(i)
            right = self._right(i)
            if left < size and self._data[left] > self._data[largest]:
                largest = left
            if right < size and self._data[right] > self._data[largest]:
                largest = right
            if largest == i:
                break
            self._data[i], self._data[largest] = self._data[largest], self._data[i]
            i = largest

    def insert(self, item: Any) -> None:
        self._data.append(item)
        self._sift_up(len(self._data) - 1)

    def extract_max(self) -> Any:
        if not self._data:
            raise IndexError("Extract from empty heap")
        max_val = self._data[0]
        last = self._data.pop()
        if self._data:
            self._data[0] = last
            self._sift_down(0)
        return max_val

    def peek(self) -> Any:
        if not self._data:
            raise IndexError("Peek from empty heap")
        return self._data[0]

    def heapify(self, arr: list[Any]) -> None:
        self._data = list(arr)
        for i in range(len(self._data) // 2 - 1, -1, -1):
            self._sift_down(i)

    def __len__(self) -> int:
        return len(self._data)

    def __str__(self) -> str:
        return str(self._data)


if __name__ == "__main__":
    h = MaxHeap()
    h.insert(3)
    h.insert(1)
    h.insert(6)
    h.insert(5)
    h.insert(2)
    h.insert(4)
    print(f"Heap: {h}")
    print(f"peek = {h.peek()}")

    print(f"extract_max = {h.extract_max()}")
    print(f"After extract: {h}")

    h2 = MaxHeap()
    h2.heapify([4, 10, 3, 5, 1])
    print(f"Heapify result: {h2}")
    print(f"peek = {h2.peek()}")
    print(f"len = {len(h2)}")
