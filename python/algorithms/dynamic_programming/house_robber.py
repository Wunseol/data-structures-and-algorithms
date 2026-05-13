"""打家劫舍 (House Robber)

时间复杂度: O(n) 其中 n 为房屋数量
空间复杂度: O(1)

对应 C++ 源码: src/advanced_algorithm/dynamic_programming/house_robber.cpp
"""


def rob(nums: list[int]) -> int:
    n = len(nums)
    if n == 0:
        return 0
    if n == 1:
        return nums[0]

    prev2 = nums[0]
    prev1 = max(nums[0], nums[1])
    for i in range(2, n):
        curr = max(prev1, prev2 + nums[i])
        prev2 = prev1
        prev1 = curr
    return prev1


if __name__ == "__main__":
    test_cases: list[tuple[list[int], int]] = [
        ([1, 2, 3, 1], 4),
        ([2, 7, 9, 3, 1], 12),
        ([2, 1, 1, 2], 4),
        ([], 0),
        ([5], 5),
        ([1, 2], 2),
    ]
    for nums, expected in test_cases:
        result = rob(nums)
        print(f"rob({nums}) = {result}")
        assert result == expected
