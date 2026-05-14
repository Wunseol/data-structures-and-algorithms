"""最长公共子序列（LCS）— 动态规划

核心操作复杂度：O(m * n)

对应 C/C++ 源码路径：src/advanced_algorithm/dynamic_programming/lcs_dp.cpp
"""
from __future__ import annotations
from typing import List


def lcs_dp(s1: str, s2: str) -> int:
    m = len(s1)
    n = len(s2)
    dp: List[List[int]] = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]


def lcs_dp_with_sequence(s1: str, s2: str) -> tuple[int, str]:
    m = len(s1)
    n = len(s2)
    dp: List[List[int]] = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    length = dp[m][n]
    seq: List[str] = []
    i, j = m, n
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            seq.append(s1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] >= dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    seq.reverse()
    return length, "".join(seq)


if __name__ == "__main__":
    test_cases: list[tuple[str, str, int]] = [
        ("ABCBDAB", "BDCAB", 4),
        ("AGGTAB", "GXTXAYB", 4),
        ("", "", 0),
        ("abc", "abc", 3),
        ("abc", "def", 0),
    ]
    for s1, s2, expected in test_cases:
        result = lcs_dp(s1, s2)
        print(f"lcs_dp('{s1}', '{s2}') = {result}")
        assert result == expected

    length, seq = lcs_dp_with_sequence("ABCBDAB", "BDCAB")
    print(f"lcs_dp_with_sequence('ABCBDAB', 'BDCAB') = ({length}, '{seq}')")
    assert length == 4
