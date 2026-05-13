"""哈希表 - 开放地址法 / 线性探测（Hash Table with Open Addressing）

核心操作复杂度：
  insert: O(1) 平均
  search: O(1) 平均
  delete: O(1) 平均

对应 C/C++ 源码路径：src/hash_table/hash_table_open_addressing.h
"""

from __future__ import annotations
from typing import Any


class HashTableOpenAddressing:
    _DELETED = object()

    def __init__(self, capacity: int = 16) -> None:
        self._capacity = capacity
        self._size = 0
        self._keys: list[Any] = [None] * capacity
        self._values: list[Any] = [None] * capacity

    def _hash(self, key: Any) -> int:
        return hash(key) % self._capacity

    def _probe(self, key: Any) -> int | None:
        index = self._hash(key)
        first_deleted: int | None = None
        for _ in range(self._capacity):
            if self._keys[index] is None:
                return first_deleted if first_deleted is not None else index
            if self._keys[index] is self._DELETED:
                if first_deleted is None:
                    first_deleted = index
            elif self._keys[index] == key:
                return index
            index = (index + 1) % self._capacity
        return first_deleted

    def insert(self, key: Any, value: Any) -> None:
        if self._size >= self._capacity - 1:
            raise RuntimeError("Hash table is full")
        index = self._probe(key)
        if index is None:
            raise RuntimeError("Hash table is full")
        if self._keys[index] == key:
            self._values[index] = value
            return
        self._keys[index] = key
        self._values[index] = value
        self._size += 1

    def search(self, key: Any) -> Any | None:
        index = self._hash(key)
        for _ in range(self._capacity):
            if self._keys[index] is None:
                return None
            if self._keys[index] == key:
                return self._values[index]
            index = (index + 1) % self._capacity
        return None

    def delete(self, key: Any) -> bool:
        index = self._hash(key)
        for _ in range(self._capacity):
            if self._keys[index] is None:
                return False
            if self._keys[index] == key:
                self._keys[index] = self._DELETED
                self._values[index] = None
                self._size -= 1
                return True
            index = (index + 1) % self._capacity
        return False

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        pairs: list[str] = []
        for i in range(self._capacity):
            if self._keys[i] is not None and self._keys[i] is not self._DELETED:
                pairs.append(f"{self._keys[i]}: {self._values[i]}")
        return "{" + ", ".join(pairs) + "}"


if __name__ == "__main__":
    ht = HashTableOpenAddressing()
    ht.insert("name", "Bob")
    ht.insert("age", 25)
    ht.insert("city", "Shanghai")

    print(f"After insert: {ht}")
    print(f"search('age') = {ht.search('age')}")
    print(f"search('email') = {ht.search('email')}")

    ht.insert("age", 26)
    print(f"After update age: {ht.search('age')}")

    ht.delete("city")
    print(f"After delete('city'): {ht}")
    print(f"len = {len(ht)}")
