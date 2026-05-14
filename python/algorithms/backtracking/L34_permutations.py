"""
全排列 (Permutations)
时间复杂度: O(n * n!)
空间复杂度: O(n) (递归栈 + 当前排列)
对应 C++ 源码: src/advanced_algorithm/backtracking/permutations.cpp
"""

from __future__ import annotations


def permute(nums: list[int]) -> list[list[int]]:
    results: list[list[int]] = []

    def backtrack(start: int) -> None:
        if start == len(nums):
            results.append(nums[:])
            return
        for i in range(start, len(nums)):
            nums[start], nums[i] = nums[i], nums[start]
            backtrack(start + 1)
            nums[start], nums[i] = nums[i], nums[start]

    backtrack(0)
    return results


if __name__ == "__main__":
    nums = [1, 2, 3]
    result = permute(nums)
    print(f"排列数: {len(result)}")
    for p in result:
        print(f"  {p}")
