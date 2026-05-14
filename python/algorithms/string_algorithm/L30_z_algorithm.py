"""Z 算法（扩展 KMP）

核心操作复杂度：
  z_function: O(n)
  z_search:   O(n + m)

对应 C/C++ 源码路径：src/string_algorithm/z_algorithm.cpp
"""
from __future__ import annotations
from typing import List


def z_function(s: str) -> List[int]:
    n = len(s)
    z: List[int] = [0] * n
    z[0] = n
    l = 0
    r = 0
    for i in range(1, n):
        if i < r:
            z[i] = min(r - i, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] > r:
            l = i
            r = i + z[i]
    return z


def z_search(text: str, pattern: str) -> List[int]:
    if not pattern:
        return []
    combined = pattern + "$" + text
    z = z_function(combined)
    m = len(pattern)
    matches: List[int] = []
    for i in range(m + 1, len(z)):
        if z[i] == m:
            matches.append(i - m - 1)
    return matches


if __name__ == "__main__":
    text = "AABAACAADAABAABA"
    pattern = "AABA"
    z = z_function(pattern + "$" + text)
    print(f"Z-array: {z}")
    matches = z_search(text, pattern)
    print(f"Matches at: {matches}")

    assert z_search("hello world", "world") == [6]
    assert z_search("aaaaa", "aa") == [0, 1, 2, 3]
    assert z_search("abc", "d") == []
    assert z_search("AABAACAADAABAABA", "AABA") == [0, 9, 12]
