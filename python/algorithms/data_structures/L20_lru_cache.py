"""LRU 缓存（Least Recently Used Cache）

核心操作复杂度：
  get: O(1)
  put: O(1)

对应 C/C++ 源码路径：src/cache/lru_cache/
"""

from __future__ import annotations
from collections import OrderedDict
from typing import Any


class LRUCache:
    def __init__(self, capacity: int) -> None:
        self._capacity = capacity
        self._cache: OrderedDict[Any, Any] = OrderedDict()

    def get(self, key: Any) -> Any | None:
        if key not in self._cache:
            return None
        self._cache.move_to_end(key)
        return self._cache[key]

    def put(self, key: Any, value: Any) -> None:
        if key in self._cache:
            self._cache.move_to_end(key)
            self._cache[key] = value
            return
        if len(self._cache) >= self._capacity:
            self._cache.popitem(last=False)
        self._cache[key] = value

    def __len__(self) -> int:
        return len(self._cache)

    def __str__(self) -> str:
        items = [f"{k}:{v}" for k, v in self._cache.items()]
        return "{" + ", ".join(items) + "}"


if __name__ == "__main__":
    cache = LRUCache(2)

    cache.put(1, 10)
    cache.put(2, 20)
    print(f"put(1,10), put(2,20) -> {cache}")

    print(f"get(1) = {cache.get(1)}")

    cache.put(3, 30)
    print(f"put(3,30) 淘汰key=2 -> {cache}")

    print(f"get(2) = {cache.get(2)}")

    cache.put(4, 40)
    print(f"put(4,40) 淘汰key=1 -> {cache}")

    print(f"get(1) = {cache.get(1)}")
    print(f"get(3) = {cache.get(3)}")
    print(f"get(4) = {cache.get(4)}")

    cache.put(3, 300)
    print(f"put(3,300) 更新 -> {cache}")
    print(f"get(3) = {cache.get(3)}")
    print(f"len = {len(cache)}")
