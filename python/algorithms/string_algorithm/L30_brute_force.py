"""暴力字符串匹配 (Brute Force String Matching)

时间复杂度: O(n*m) 其中 n 为主串长度, m 为模式串长度
空间复杂度: O(1)

对应 C++ 源码: src/string_algorithm/brute_force_match.cpp
"""

from typing import List


def brute_force_search(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    if m == 0 or m > n:
        return []

    positions: List[int] = []
    for i in range(n - m + 1):
        j = 0
        while j < m and text[i + j] == pattern[j]:
            j += 1
        if j == m:
            positions.append(i)
    return positions


if __name__ == "__main__":
    text = "ABABCABCABABABD"
    pattern = "ABAB"
    result = brute_force_search(text, pattern)
    print(f"主串: {text}")
    print(f"模式串: {pattern}")
    print(f"匹配位置: {result}")

    assert brute_force_search("hello world", "world") == [6]
    assert brute_force_search("aaaaa", "aa") == [0, 1, 2, 3]
    assert brute_force_search("abc", "d") == []
    assert brute_force_search("abc", "") == []
