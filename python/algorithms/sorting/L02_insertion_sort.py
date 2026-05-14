"""直接插入排序 (Insertion Sort)

时间复杂度: 平均 O(n²), 最坏 O(n²), 最好 O(n)
空间复杂度: O(1)
稳定性: 稳定
对应 C++ 源码: src/sorting/sequential_list_sorting.cpp -> InsertSort()
"""


def insertion_sort(arr: list[int]) -> list[int]:
    a = arr[:]
    n = len(a)
    for i in range(1, n):
        if a[i] < a[i - 1]:
            temp = a[i]
            j = i - 1
            while j >= 0 and a[j] > temp:
                a[j + 1] = a[j]
                j -= 1
            a[j + 1] = temp
    return a


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"排序前: {test}")
    result = insertion_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("直接插入排序测试通过 ✓")
