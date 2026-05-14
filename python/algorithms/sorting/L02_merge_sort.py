"""归并排序 (Merge Sort)

时间复杂度: 平均 O(n log n), 最坏 O(n log n), 最好 O(n log n)
空间复杂度: O(n)
稳定性: 稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> MergeSort()
"""


def _merge(left: list[int], right: list[int]) -> list[int]:
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def merge_sort(arr: list[int]) -> list[int]:
    if len(arr) <= 1:
        return arr[:]
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return _merge(left, right)


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = merge_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("归并排序测试通过 ✓")
