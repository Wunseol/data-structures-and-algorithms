"""插值查找 (Interpolation Search)

时间复杂度: 平均 O(log log n), 最坏 O(n)
空间复杂度: O(1)
对应 C++ 源码: src/searching/interpolation_search.cpp
"""


def interpolation_search(arr: list[int], target: int) -> int:
    low, high = 0, len(arr) - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if arr[high] == arr[low]:
            if arr[low] == target:
                return low
            return -1

        pos = low + int((target - arr[low]) / (arr[high] - arr[low]) * (high - low))

        if pos < low:
            pos = low
        if pos > high:
            pos = high

        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1


if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    print(f"数组: {arr}")

    idx = interpolation_search(arr, 70)
    print(f"插值查找 70: 索引 {idx}")
    assert idx == 6, "测试失败"

    idx = interpolation_search(arr, 10)
    print(f"插值查找 10: 索引 {idx}")
    assert idx == 0, "首元素测试失败"

    idx = interpolation_search(arr, 100)
    print(f"插值查找 100: 索引 {idx}")
    assert idx == 9, "末元素测试失败"

    idx = interpolation_search(arr, 55)
    print(f"插值查找 55: 索引 {idx}")
    assert idx == -1, "未找到测试失败"

    print("插值查找测试通过 ✓")
