"""
DP 算法正确性验证
将动态规划结果与暴力法结果进行对比，验证 DP 实现的正确性
"""

from itertools import combinations, product


def fib_recursive(n: int) -> int:
    if n <= 1:
        return n
    return fib_recursive(n - 1) + fib_recursive(n - 2)


def fib_dp(n: int) -> int:
    if n <= 1:
        return n
    dp = [0] * (n + 1)
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


def lcs_brute_force(s1: str, s2: str) -> int:
    n = len(s1)
    best = 0
    for r in range(1, n + 1):
        for indices in combinations(range(n), r):
            subseq = "".join(s1[i] for i in indices)
            it = iter(s2)
            if all(c in it for c in subseq):
                best = max(best, len(subseq))
    return best


def lcs_dp(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]


def knapsack_brute_force(weights: list[int], values: list[int], capacity: int) -> int:
    n = len(weights)
    best = 0
    for r in range(1, n + 1):
        for indices in combinations(range(n), r):
            w = sum(weights[i] for i in indices)
            v = sum(values[i] for i in indices)
            if w <= capacity:
                best = max(best, v)
    return best


def knapsack_dp(weights: list[int], values: list[int], capacity: int) -> int:
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            dp[i][w] = dp[i - 1][w]
            if w >= weights[i - 1]:
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
    return dp[n][capacity]


def edit_distance_recursive(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)

    def _rec(i: int, j: int) -> int:
        if i == 0:
            return j
        if j == 0:
            return i
        if s1[i - 1] == s2[j - 1]:
            return _rec(i - 1, j - 1)
        return 1 + min(
            _rec(i - 1, j),
            _rec(i, j - 1),
            _rec(i - 1, j - 1),
        )

    return _rec(m, n)


def edit_distance_dp(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[m][n]


def verify_fibonacci():
    print("\n" + "─" * 60)
    print("Fibonacci: DP vs 递归")
    print("─" * 60)
    test_cases = [0, 1, 2, 5, 10, 15, 20]
    all_pass = True
    for n in test_cases:
        expected = fib_recursive(n)
        actual = fib_dp(n)
        passed = expected == actual
        all_pass = all_pass and passed
        status = "PASS" if passed else "FAIL"
        print(f"  fib({n:>2}): 递归={expected:<10} DP={actual:<10} [{status}]")
    return all_pass


def verify_lcs():
    print("\n" + "─" * 60)
    print("LCS: DP vs 暴力法")
    print("─" * 60)
    test_cases = [
        ("ABC", "ABC"),
        ("ABC", "DEF"),
        ("AGGTAB", "GXTXAYB"),
        ("ABCBDAB", "BDCAB"),
        ("XMJYAUZ", "MZJAWXU"),
    ]
    all_pass = True
    for s1, s2 in test_cases:
        expected = lcs_brute_force(s1, s2)
        actual = lcs_dp(s1, s2)
        passed = expected == actual
        all_pass = all_pass and passed
        status = "PASS" if passed else "FAIL"
        print(f"  LCS('{s1}', '{s2}'): 暴力={expected:<4} DP={actual:<4} [{status}]")
    return all_pass


def verify_knapsack():
    print("\n" + "─" * 60)
    print("0-1 Knapsack: DP vs 暴力法 (枚举所有子集)")
    print("─" * 60)
    test_cases = [
        ([1, 2, 3], [6, 10, 12], 5),
        ([2, 3, 4, 5], [3, 4, 5, 6], 5),
        ([1, 3, 4, 5], [1, 4, 5, 7], 7),
        ([10, 20, 30], [60, 100, 120], 50),
        ([3, 2, 2], [6, 3, 5], 5),
    ]
    all_pass = True
    for weights, values, capacity in test_cases:
        expected = knapsack_brute_force(weights, values, capacity)
        actual = knapsack_dp(weights, values, capacity)
        passed = expected == actual
        all_pass = all_pass and passed
        status = "PASS" if passed else "FAIL"
        print(
            f"  W={weights} V={values} C={capacity}: "
            f"暴力={expected:<4} DP={actual:<4} [{status}]"
        )
    return all_pass


def verify_edit_distance():
    print("\n" + "─" * 60)
    print("Edit Distance: DP vs 递归")
    print("─" * 60)
    test_cases = [
        ("", ""),
        ("", "abc"),
        ("abc", ""),
        ("kitten", "sitting"),
        ("sunday", "saturday"),
        ("abc", "abc"),
        ("a", "b"),
        ("intention", "execution"),
    ]
    all_pass = True
    for s1, s2 in test_cases:
        expected = edit_distance_recursive(s1, s2)
        actual = edit_distance_dp(s1, s2)
        passed = expected == actual
        all_pass = all_pass and passed
        status = "PASS" if passed else "FAIL"
        print(f"  edit('{s1}', '{s2}'): 递归={expected:<4} DP={actual:<4} [{status}]")
    return all_pass


def main():
    print("=" * 60)
    print("DP 算法正确性验证")
    print("将 DP 实现结果与暴力法/递归法结果逐一对比")
    print("=" * 60)

    results = {
        "Fibonacci": verify_fibonacci(),
        "LCS": verify_lcs(),
        "0-1 Knapsack": verify_knapsack(),
        "Edit Distance": verify_edit_distance(),
    }

    print("\n" + "=" * 60)
    print("总结")
    print("=" * 60)
    for name, passed in results.items():
        status = "✓ 全部通过" if passed else "✗ 存在失败"
        print(f"  {name:<20} {status}")
    print("=" * 60)


if __name__ == "__main__":
    main()
