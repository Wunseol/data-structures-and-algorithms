"""KMP 字符串匹配算法 (Knuth-Morris-Pratt)

时间复杂度: O(n + m) 其中 n 为主串长度, m 为模式串长度
空间复杂度: O(m)

对应 C++ 源码: src/string_algorithm/kmp.cpp
"""

from typing import List


def compute_next(pattern: str) -> List[int]:
    m = len(pattern)
    next_arr: List[int] = [-1] * (m + 1)
    i = 0
    j = -1

    while i < m:
        if j == -1 or pattern[i] == pattern[j]:
            i += 1
            j += 1
            next_arr[i] = j
        else:
            j = next_arr[j]
    return next_arr


def kmp_search(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    if m == 0 or m > n:
        return []

    next_arr = compute_next(pattern)
    positions: List[int] = []
    i = 0
    j = 0

    while i < n:
        if j == -1 or text[i] == pattern[j]:
            i += 1
            j += 1
        else:
            j = next_arr[j]

        if j == m:
            positions.append(i - m)
            j = next_arr[m]

    return positions


if __name__ == "__main__":
    text = "ABABCABCABABABD"
    pattern = "ABAB"
    result = kmp_search(text, pattern)
    print(f"主串: {text}")
    print(f"模式串: {pattern}")
    print(f"next 数组: {compute_next(pattern)}")
    print(f"匹配位置: {result}")

    assert kmp_search("hello world", "world") == [6]
    assert kmp_search("aaaaa", "aa") == [0, 1, 2, 3]
    assert kmp_search("abc", "d") == []
    assert kmp_search("ABABABAB", "ABAB") == [0, 2, 4]
