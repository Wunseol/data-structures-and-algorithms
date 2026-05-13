"""Manacher 算法 (最长回文子串)

时间复杂度: O(n) 其中 n 为字符串长度
空间复杂度: O(n)

对应 C++ 源码: src/string_algorithm/manacher.cpp
"""


def _preprocess(s: str) -> str:
    result = "#"
    for ch in s:
        result += ch + "#"
    return result


def manacher(s: str) -> str:
    if not s:
        return ""

    t = _preprocess(s)
    n = len(t)
    p: list[int] = [0] * n

    center = 0
    right = 0

    for i in range(n):
        if i < right:
            mirror = 2 * center - i
            p[i] = min(right - i, p[mirror])

        while i - p[i] - 1 >= 0 and i + p[i] + 1 < n and t[i - p[i] - 1] == t[i + p[i] + 1]:
            p[i] += 1

        if i + p[i] > right:
            center = i
            right = i + p[i]

    max_len = 0
    center_index = 0
    for i in range(n):
        if p[i] > max_len:
            max_len = p[i]
            center_index = i

    start = (center_index - max_len) // 2
    return s[start:start + max_len]


if __name__ == "__main__":
    test_cases = ["babad", "cbbd", "a", "ac", "racecar", "abacdfgdcaba"]
    for s in test_cases:
        result = manacher(s)
        print(f"字符串: {s} -> 最长回文子串: {result}")

    assert manacher("babad") in ("bab", "aba")
    assert manacher("cbbd") == "bb"
    assert manacher("a") == "a"
    assert manacher("racecar") == "racecar"
    assert manacher("") == ""
