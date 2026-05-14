"""Boyer-Moore 字符串匹配算法 (简化版，坏字符规则)

时间复杂度: 最坏 O(n*m), 平均 O(n/m) 其中 n 为主串长度, m 为模式串长度
空间复杂度: O(k) 其中 k 为字符集大小

对应 C++ 源码: src/string_algorithm/boyer_moore.cpp
"""

from typing import List

ALPHABET_SIZE = 256


def _build_bad_char_table(pattern: str) -> List[int]:
    bad_char = [-1] * ALPHABET_SIZE
    for i, ch in enumerate(pattern):
        bad_char[ord(ch)] = i
    return bad_char


def boyer_moore_search(text: str, pattern: str) -> List[int]:
    n = len(text)
    m = len(pattern)
    if m == 0 or m > n:
        return []

    bad_char = _build_bad_char_table(pattern)
    positions: List[int] = []

    s = 0
    while s <= n - m:
        j = m - 1

        while j >= 0 and pattern[j] == text[s + j]:
            j -= 1

        if j < 0:
            positions.append(s)
            shift = m - bad_char[ord(text[s + m])] if s + m < n else 1
            s += shift if shift > 0 else 1
        else:
            shift = j - bad_char[ord(text[s + j])]
            s += shift if shift > 0 else 1

    return positions


if __name__ == "__main__":
    text = "ABABCABCABABABD"
    pattern = "ABAB"
    result = boyer_moore_search(text, pattern)
    print(f"主串: {text}")
    print(f"模式串: {pattern}")
    print(f"匹配位置: {result}")

    assert boyer_moore_search("hello world", "world") == [6]
    assert boyer_moore_search("aaaaa", "aa") == [0, 1, 2, 3]
    assert boyer_moore_search("abc", "d") == []
    assert boyer_moore_search("ABCABCABC", "ABC") == [0, 3, 6]
