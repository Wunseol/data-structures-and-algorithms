"""二分查找 (Binary Search)

时间复杂度: O(log n)
空间复杂度: O(1)
对应 C++ 源码: src/searching/binary_search.cpp
"""


def binary_search(arr: list[int], target: int) -> int:
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def binary_search_left(arr: list[int], target: int) -> int:
    low, high = 0, len(arr)
    while low < high:
        mid = low + (high - low) // 2
        if arr[mid] < target:
            low = mid + 1
        else:
            high = mid
    if low < len(arr) and arr[low] == target:
        return low
    return -1


def binary_search_right(arr: list[int], target: int) -> int:
    low, high = 0, len(arr)
    while low < high:
        mid = low + (high - low) // 2
        if arr[mid] <= target:
            low = mid + 1
        else:
            high = mid
    if low > 0 and arr[low - 1] == target:
        return low - 1
    return -1


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 4, 4, 5, 6, 7, 8]
    print(f"数组: {arr}")

    idx = binary_search(arr, 4)
    print(f"精确查找 4: 索引 {idx}")
    assert 3 <= idx <= 5, "精确查找测试失败"

    idx = binary_search(arr, 9)
    assert idx == -1, "未找到测试失败"

    left = binary_search_left(arr, 4)
    print(f"左边界查找 4: 索引 {left}")
    assert left == 3, "左边界查找测试失败"

    right = binary_search_right(arr, 4)
    print(f"右边界查找 4: 索引 {right}")
    assert right == 5, "右边界查找测试失败"

    assert binary_search_left(arr, 9) == -1, "左边界未找到测试失败"
    assert binary_search_right(arr, 9) == -1, "右边界未找到测试失败"

    print("二分查找测试通过 ✓")
