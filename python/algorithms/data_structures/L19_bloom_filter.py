"""布隆过滤器（Bloom Filter）

核心操作复杂度：
  add:      O(k)  k=哈希函数数
  contains: O(k)

对应 C/C++ 源码路径：src/hash_table/bloom_filter/
"""

from __future__ import annotations
import hashlib
import math
from typing import List


class BloomFilter:
    def __init__(self, capacity: int, error_rate: float = 0.01) -> None:
        self._size = self._optimal_size(capacity, error_rate)
        self._num_hashes = self._optimal_hashes(self._size, capacity)
        self._bits: List[bool] = [False] * self._size

    @staticmethod
    def _optimal_size(n: int, p: float) -> int:
        return max(1, int(-n * math.log(p) / (math.log(2) ** 2)))

    @staticmethod
    def _optimal_hashes(m: int, n: int) -> int:
        return max(1, int((m / n) * math.log(2)))

    def _hashes(self, item: str) -> List[int]:
        encoded = item.encode("utf-8")
        h1 = int(hashlib.md5(encoded).hexdigest(), 16)
        h2 = int(hashlib.sha1(encoded).hexdigest(), 16)
        return [(h1 + i * h2) % self._size for i in range(self._num_hashes)]

    def add(self, item: str) -> None:
        for pos in self._hashes(item):
            self._bits[pos] = True

    def contains(self, item: str) -> bool:
        return all(self._bits[pos] for pos in self._hashes(item))

    def __str__(self) -> str:
        set_count = sum(self._bits)
        return (
            f"BloomFilter(size={self._size}, "
            f"num_hashes={self._num_hashes}, "
            f"bits_set={set_count})"
        )


if __name__ == "__main__":
    bf = BloomFilter(1000, 0.01)
    print(f"初始: {bf}")

    items = ["apple", "banana", "cherry", "date", "elderberry"]
    for item in items:
        bf.add(item)
    print(f"添加后: {bf}")

    print("\n查询已添加的元素:")
    for item in items:
        print(f"  contains('{item}') = {bf.contains(item)}")

    print("\n查询未添加的元素:")
    absent = ["fig", "grape", "kiwi"]
    for item in absent:
        result = bf.contains(item)
        print(f"  contains('{item}') = {result}" + (" (误判)" if result else ""))

    print(f"\n{bf}")
