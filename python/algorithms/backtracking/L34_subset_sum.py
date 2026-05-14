"""
子集和问题 (Subset Sum Problem)
时间复杂度: O(2^n) (最坏情况)
空间复杂度: O(n) (递归栈 + 当前子集)
对应 C++ 源码: src/advanced_algorithm/backtracking/subset_sum.cpp
"""

from __future__ import annotations


def subset_sum(nums: list[int], target: int) -> list[list[int]]:
    results: list[list[int]] = []
    current: list[int] = []
    sorted_nums = sorted(nums)

    def backtrack(start: int, curr_sum: int) -> None:
        if curr_sum == target:
            results.append(current[:])
            return
        for i in range(start, len(sorted_nums)):
            if curr_sum + sorted_nums[i] > target:
                break
            if i > start and sorted_nums[i] == sorted_nums[i - 1]:
                continue
            current.append(sorted_nums[i])
            backtrack(i + 1, curr_sum + sorted_nums[i])
            current.pop()

    backtrack(0, 0)
    return results


if __name__ == "__main__":
    nums = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    result = subset_sum(nums, target)
    print(f"目标和 {target} 的子集数: {len(result)}")
    for s in result:
        print(f"  {s}")
