"""顺序表（Sequential List）

核心操作复杂度：
  append:  O(1) 均摊
  insert:  O(n)
  delete:  O(n)
  get:     O(1)
  find:    O(n)

对应 C/C++ 源码路径：src/linear_list/sequential_list/
"""

from __future__ import annotations
from typing import Any


class SequentialList:
    def __init__(self, capacity: int = 10) -> None:
        self._data: list[Any] = [None] * capacity
        self._size: int = 0
        self._capacity: int = capacity

    def _resize(self, new_capacity: int) -> None:
        new_data: list[Any] = [None] * new_capacity
        for i in range(self._size):
            new_data[i] = self._data[i]
        self._data = new_data
        self._capacity = new_capacity

    def append(self, item: Any) -> None:
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        self._data[self._size] = item
        self._size += 1

    def insert(self, index: int, item: Any) -> None:
        if index < 0 or index > self._size:
            raise IndexError(f"Index {index} out of range")
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        for i in range(self._size, index, -1):
            self._data[i] = self._data[i - 1]
        self._data[index] = item
        self._size += 1

    def delete(self, index: int) -> Any:
        if index < 0 or index >= self._size:
            raise IndexError(f"Index {index} out of range")
        removed = self._data[index]
        for i in range(index, self._size - 1):
            self._data[i] = self._data[i + 1]
        self._data[self._size - 1] = None
        self._size -= 1
        if 0 < self._size < self._capacity // 4:
            self._resize(self._capacity // 2)
        return removed

    def get(self, index: int) -> Any:
        if index < 0 or index >= self._size:
            raise IndexError(f"Index {index} out of range")
        return self._data[index]

    def find(self, item: Any) -> int:
        for i in range(self._size):
            if self._data[i] == item:
                return i
        return -1

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        elements = [str(self._data[i]) for i in range(self._size)]
        return "[" + ", ".join(elements) + "]"


if __name__ == "__main__":
    sl = SequentialList()
    sl.append(10)
    sl.append(20)
    sl.append(30)
    print(f"After append: {sl}")

    sl.insert(1, 15)
    print(f"After insert(1, 15): {sl}")

    print(f"get(2) = {sl.get(2)}")
    print(f"find(20) = {sl.find(20)}")
    print(f"find(99) = {sl.find(99)}")

    sl.delete(1)
    print(f"After delete(1): {sl}")

    print(f"len = {len(sl)}")
