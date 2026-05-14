"""最长公共子序列 (Longest Common Subsequence)

时间复杂度: O(m*n) 其中 m, n 分别为两个字符串的长度
空间复杂度: O(m*n)

对应 C++ 源码: src/string_algorithm/lcs.cpp
"""


def lcs_length(s1: str, s2: str) -> int:
    m = len(s1)
    n = len(s2)
    dp: list[list[int]] = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]


def lcs_string(s1: str, s2: str) -> str:
    m = len(s1)
    n = len(s2)
    dp: list[list[int]] = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    result: list[str] = []
    i, j = m, n
    while i > 0 and j > 0:
        if s1[i - 1] == s2[j - 1]:
            result.append(s1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1

    return "".join(reversed(result))


if __name__ == "__main__":
    s1 = "ABCBDAB"
    s2 = "BDCABA"
    print(f"字符串1: {s1}")
    print(f"字符串2: {s2}")
    print(f"LCS 长度: {lcs_length(s1, s2)}")
    print(f"LCS 内容: {lcs_string(s1, s2)}")

    assert lcs_length("ABCBDAB", "BDCABA") == 4
    assert lcs_string("ABCBDAB", "BDCABA") in ("BCBA", "BDAB", "BCAB")
    assert lcs_length("abc", "abc") == 3
    assert lcs_string("abc", "abc") == "abc"
    assert lcs_length("abc", "def") == 0
    assert lcs_string("abc", "def") == ""
