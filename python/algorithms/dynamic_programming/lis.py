"""最长递增子序列 (Longest Increasing Subsequence)

时间复杂度:
  - lis_length: O(n log n)
  - lis_sequence: O(n^2)
空间复杂度:
  - lis_length: O(n)
  - lis_sequence: O(n)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/lis.cpp
"""

from bisect import bisect_left


def lis_length(nums: list[int]) -> int:
    if not nums:
        return 0

    tails: list[int] = []
    for num in nums:
        pos = bisect_left(tails, num)
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    return len(tails)


def lis_sequence(nums: list[int]) -> list[int]:
    n = len(nums)
    if n == 0:
        return []

    dp: list[int] = [1] * n
    parent: list[int] = [-1] * n
    max_len = 1
    max_idx = 0

    for i in range(1, n):
        for j in range(i):
            if nums[j] < nums[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                parent[i] = j
        if dp[i] > max_len:
            max_len = dp[i]
            max_idx = i

    seq: list[int] = []
    i = max_idx
    while i != -1:
        seq.append(nums[i])
        i = parent[i]
    seq.reverse()
    return seq


if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print(f"数组: {nums}")
    print(f"LIS 长度: {lis_length(nums)}")
    print(f"LIS 序列: {lis_sequence(nums)}")

    assert lis_length([10, 9, 2, 5, 3, 7, 101, 18]) == 4
    assert lis_sequence([10, 9, 2, 5, 3, 7, 101, 18]) == [2, 3, 7, 101] or \
           lis_sequence([10, 9, 2, 5, 3, 7, 101, 18]) == [2, 5, 7, 101]
    assert lis_length([0, 1, 0, 3, 2, 3]) == 4
    assert lis_length([7, 7, 7, 7]) == 1
    assert lis_length([]) == 0
    assert lis_sequence([]) == []
