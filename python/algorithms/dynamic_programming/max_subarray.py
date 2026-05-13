"""最大子数组和 (Kadane 算法)

时间复杂度: O(n) 其中 n 为数组长度
空间复杂度: O(1)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/max_subarray.cpp
"""


def max_subarray(nums: list[int]) -> int:
    if not nums:
        return 0

    max_sum = nums[0]
    curr_sum = nums[0]

    for i in range(1, len(nums)):
        if curr_sum + nums[i] < nums[i]:
            curr_sum = nums[i]
        else:
            curr_sum += nums[i]
        if curr_sum > max_sum:
            max_sum = curr_sum

    return max_sum


if __name__ == "__main__":
    test_cases: list[tuple[list[int], int]] = [
        ([-2, 1, -3, 4, -1, 2, 1, -5, 4], 6),
        ([1], 1),
        ([5, 4, -1, 7, 8], 23),
        ([-1], -1),
        ([-2, -1], -1),
    ]
    for nums, expected in test_cases:
        result = max_subarray(nums)
        print(f"max_subarray({nums}) = {result}")
        assert result == expected
