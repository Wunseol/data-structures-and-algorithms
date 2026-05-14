"""
最大子数组问题 - 分治法 (Maximum Subarray - Divide and Conquer)
时间复杂度: O(n log n)
空间复杂度: O(log n) (递归栈)
对应 C++ 源码: src/advanced_algorithm/divide_and_conquer/max_subarray_dc.cpp
"""

from __future__ import annotations


def max_subarray_dc(nums: list[int]) -> int:
    def cross_sum(left: int, mid: int, right: int) -> int:
        left_sum = float("-inf")
        s = 0
        for i in range(mid, left - 1, -1):
            s += nums[i]
            if s > left_sum:
                left_sum = s
        right_sum = float("-inf")
        s = 0
        for i in range(mid + 1, right + 1):
            s += nums[i]
            if s > right_sum:
                right_sum = s
        return left_sum + right_sum

    def dc(left: int, right: int) -> int:
        if left == right:
            return nums[left]
        mid = left + (right - left) // 2
        l_max = dc(left, mid)
        r_max = dc(mid + 1, right)
        c_max = cross_sum(left, mid, right)
        return max(l_max, r_max, c_max)

    return dc(0, len(nums) - 1)


if __name__ == "__main__":
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    result = max_subarray_dc(nums)
    print(f"最大子数组和: {result}")
