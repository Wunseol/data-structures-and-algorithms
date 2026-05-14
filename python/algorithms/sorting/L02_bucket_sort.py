"""桶排序 (Bucket Sort)

时间复杂度: 平均 O(n), 最坏 O(n²)
空间复杂度: O(n + k)
稳定性: 稳定（桶内使用插入排序时）
对应 C++ 源码: src/sorting/bucket_sort.cpp
"""


def _insertion_sort(arr: list[float]) -> list[float]:
    a = arr[:]
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
    return a


def bucket_sort(arr: list[float]) -> list[float]:
    n = len(arr)
    if n <= 1:
        return arr[:]

    buckets: list[list[float]] = [[] for _ in range(n)]

    for x in arr:
        bucket_index = int(n * x)
        if bucket_index >= n:
            bucket_index = n - 1
        buckets[bucket_index].append(x)

    for i in range(n):
        buckets[i] = _insertion_sort(buckets[i])

    result: list[float] = []
    for bucket in buckets:
        result.extend(bucket)

    return result


if __name__ == "__main__":
    test = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
    print(f"排序前: {test}")
    result = bucket_sort(test)
    print(f"排序后: {result}")
    assert result == sorted(test), "测试失败"
    print("桶排序测试通过 ✓")
