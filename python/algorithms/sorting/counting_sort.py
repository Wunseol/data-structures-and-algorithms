"""计数排序 (Counting Sort)

时间复杂度: O(n + k), k 为数据范围
空间复杂度: O(n + k)
稳定性: 稳定（稳定版本）
对应 C++ 源码: src/sorting/counting_sort.cpp
"""


def counting_sort(arr: list[int]) -> list[int]:
    if not arr:
        return []

    max_val = max(arr)
    min_val = min(arr)
    range_size = max_val - min_val + 1

    count = [0] * range_size
    for x in arr:
        count[x - min_val] += 1

    for i in range(1, range_size):
        count[i] += count[i - 1]

    output = [0] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i] - min_val] - 1] = arr[i]
        count[arr[i] - min_val] -= 1

    return output


if __name__ == "__main__":
    test = [4, 2, 2, 8, 3, 3, 1]
    print(f"排序前: {test}")
    result = counting_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"

    test2 = [-5, -10, 0, -3, 8, 5, -1, 10]
    result2 = counting_sort(test2)
    assert result2 == sorted(test2), "负数测试失败"
    print("计数排序测试通过 ✓")
