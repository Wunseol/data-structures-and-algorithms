"""顺序查找 (Linear Search)

时间复杂度: O(n)
空间复杂度: O(1)
对应 C++ 源码: src/searching/linear_search.cpp
"""


def linear_search(arr: list[int], target: int) -> int:
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


def sentinel_linear_search(arr: list[int], target: int) -> int:
    n = len(arr)
    if n == 0:
        return -1

    a = arr[:]
    last = a[n - 1]
    a[n - 1] = target

    i = 0
    while a[i] != target:
        i += 1

    a[n - 1] = last

    if i < n - 1 or last == target:
        return i
    return -1


if __name__ == "__main__":
    test = [64, 34, 25, 12, 22, 11, 90]
    print(f"数组: {test}")

    idx = linear_search(test, 22)
    print(f"线性查找 22: 索引 {idx}")
    assert idx == 4, "测试失败"

    idx = linear_search(test, 100)
    print(f"线性查找 100: 索引 {idx}")
    assert idx == -1, "未找到测试失败"

    idx = sentinel_linear_search(test, 22)
    print(f"哨兵查找 22: 索引 {idx}")
    assert idx == 4, "哨兵查找测试失败"

    idx = sentinel_linear_search(test, 100)
    print(f"哨兵查找 100: 索引 {idx}")
    assert idx == -1, "哨兵未找到测试失败"

    print("顺序查找测试通过 ✓")
