"""编辑距离 (Edit Distance / Levenshtein Distance)

时间复杂度: O(m*n) 其中 m, n 分别为两个字符串的长度
空间复杂度: O(m*n)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/edit_distance.cpp
"""


def edit_distance(word1: str, word2: str) -> int:
    m = len(word1)
    n = len(word2)
    dp: list[list[int]] = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

    return dp[m][n]


if __name__ == "__main__":
    test_cases: list[tuple[str, str, int]] = [
        ("horse", "ros", 3),
        ("intention", "execution", 5),
        ("", "", 0),
        ("abc", "abc", 0),
        ("abc", "", 3),
        ("kitten", "sitting", 3),
    ]
    for w1, w2, expected in test_cases:
        result = edit_distance(w1, w2)
        print(f"edit_distance('{w1}', '{w2}') = {result}")
        assert result == expected
