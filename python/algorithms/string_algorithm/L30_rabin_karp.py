"""Rabin-Karp 字符串匹配算法

时间复杂度: 平均 O(n + m), 最坏 O(n*m) 其中 n 为主串长度, m 为模式串长度
空间复杂度: O(1)

对应 C++ 源码: src/string_algorithm/rabin_karp.cpp
"""

from typing import List

BASE = 256
MOD = 1000000007


def rabin_karp_search(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    if m == 0 or m > n:
        return []

    positions: List[int] = []

    h = 1
    for _ in range(m - 1):
        h = (h * BASE) % MOD

    pattern_hash = 0
    text_hash = 0
    for i in range(m):
        pattern_hash = (pattern_hash * BASE + ord(pattern[i])) % MOD
        text_hash = (text_hash * BASE + ord(text[i])) % MOD

    for i in range(n - m + 1):
        if pattern_hash == text_hash:
            match = True
            for j in range(m):
                if text[i + j] != pattern[j]:
                    match = False
                    break
            if match:
                positions.append(i)

        if i < n - m:
            text_hash = (text_hash - ord(text[i]) * h % MOD + MOD) % MOD
            text_hash = (text_hash * BASE + ord(text[i + m])) % MOD

    return positions


if __name__ == "__main__":
    text = "ABABCABCABABABD"
    pattern = "ABAB"
    result = rabin_karp_search(text, pattern)
    print(f"主串: {text}")
    print(f"模式串: {pattern}")
    print(f"匹配位置: {result}")

    assert rabin_karp_search("hello world", "world") == [6]
    assert rabin_karp_search("aaaaa", "aa") == [0, 1, 2, 3]
    assert rabin_karp_search("abc", "d") == []
    assert rabin_karp_search("GEEKS FOR GEEKS", "GEEK") == [0, 10]
