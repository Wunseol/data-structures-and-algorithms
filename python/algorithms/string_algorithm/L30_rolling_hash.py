"""滚动哈希（Rolling Hash）

核心操作复杂度：
  compute_hash: O(n)
  append:       O(1)
  skip:         O(1)
  slide:        O(1)

对应 C/C++ 源码路径：src/string_algorithm/rolling_hash.cpp
"""

from __future__ import annotations


class RollingHash:
    def __init__(self, base: int = 256, mod: int = 1000000007) -> None:
        self._base = base
        self._mod = mod
        self._hash = 0
        self._power = 1
        self._window_size = 0

    def compute_hash(self, s: str) -> int:
        self._hash = 0
        self._power = 1
        self._window_size = len(s)
        for i, ch in enumerate(s):
            self._hash = (self._hash * self._base + ord(ch)) % self._mod
            if i < len(s) - 1:
                self._power = (self._power * self._base) % self._mod
        return self._hash

    def append(self, char: str) -> None:
        self._hash = (self._hash * self._base + ord(char)) % self._mod
        if self._window_size > 0:
            self._power = (self._power * self._base) % self._mod
        self._window_size += 1

    def skip(self, char: str) -> None:
        self._hash = (self._hash - ord(char) * self._power % self._mod + self._mod) % self._mod
        self._window_size -= 1
        if self._window_size > 0:
            self._power = self._power * pow(self._base, self._mod - 2, self._mod) % self._mod
        else:
            self._power = 1

    def slide(self, old_char: str, new_char: str) -> None:
        self._hash = (self._hash - ord(old_char) * self._power % self._mod + self._mod) % self._mod
        self._hash = (self._hash * self._base + ord(new_char)) % self._mod

    @property
    def hash_value(self) -> int:
        return self._hash

    @property
    def window_size(self) -> int:
        return self._window_size


if __name__ == "__main__":
    rh = RollingHash()

    h = rh.compute_hash("hello")
    print(f"\"hello\" 的哈希值: {h}")

    rh2 = RollingHash()
    for ch in "hello":
        rh2.append(ch)
    print(f"逐字符 append 构建的哈希值: {rh2.hash_value}")
    assert rh.hash_value == rh2.hash_value

    rh3 = RollingHash()
    rh3.compute_hash("abc")
    print(f"\"abc\" 的哈希值: {rh3.hash_value}")
    rh3.slide("a", "d")
    print(f"slide('a','d') 后哈希值: {rh3.hash_value}")
    rh3_direct = RollingHash()
    rh3_direct.compute_hash("bcd")
    print(f"\"bcd\" 直接计算的哈希值: {rh3_direct.hash_value}")
    assert rh3.hash_value == rh3_direct.hash_value

    rh4 = RollingHash()
    rh4.compute_hash("abcd")
    print(f"\"abcd\" 的哈希值: {rh4.hash_value}")
    rh4.skip("a")
    print(f"skip('a') 后哈希值: {rh4.hash_value}")
    rh4_skip_direct = RollingHash()
    rh4_skip_direct.compute_hash("bcd")
    print(f"\"bcd\" 直接计算的哈希值: {rh4_skip_direct.hash_value}")
    assert rh4.hash_value == rh4_skip_direct.hash_value

    print("\n所有测试通过！")
