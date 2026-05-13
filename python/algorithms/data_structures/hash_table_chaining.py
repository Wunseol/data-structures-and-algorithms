"""哈希表 - 链地址法（Hash Table with Chaining）

核心操作复杂度：
  insert: O(1) 平均
  search: O(1) 平均
  delete: O(1) 平均

对应 C/C++ 源码路径：src/hash_table/hash_table_chaining.h
"""

from __future__ import annotations
from typing import Any


class HashTableChaining:
    def __init__(self, capacity: int = 16) -> None:
        self._capacity = capacity
        self._size = 0
        self._buckets: list[list[tuple[Any, Any]]] = [[] for _ in range(capacity)]

    def _hash(self, key: Any) -> int:
        return hash(key) % self._capacity

    def insert(self, key: Any, value: Any) -> None:
        index = self._hash(key)
        for i, (k, _) in enumerate(self._buckets[index]):
            if k == key:
                self._buckets[index][i] = (key, value)
                return
        self._buckets[index].append((key, value))
        self._size += 1

    def search(self, key: Any) -> Any | None:
        index = self._hash(key)
        for k, v in self._buckets[index]:
            if k == key:
                return v
        return None

    def delete(self, key: Any) -> bool:
        index = self._hash(key)
        for i, (k, _) in enumerate(self._buckets[index]):
            if k == key:
                self._buckets[index].pop(i)
                self._size -= 1
                return True
        return False

    def __len__(self) -> int:
        return self._size

    def __str__(self) -> str:
        pairs: list[str] = []
        for bucket in self._buckets:
            for k, v in bucket:
                pairs.append(f"{k}: {v}")
        return "{" + ", ".join(pairs) + "}"


if __name__ == "__main__":
    ht = HashTableChaining()
    ht.insert("name", "Alice")
    ht.insert("age", 30)
    ht.insert("city", "Beijing")

    print(f"After insert: {ht}")
    print(f"search('name') = {ht.search('name')}")
    print(f"search('email') = {ht.search('email')}")

    ht.insert("age", 31)
    print(f"After update age: {ht.search('age')}")

    ht.delete("city")
    print(f"After delete('city'): {ht}")
    print(f"len = {len(ht)}")
