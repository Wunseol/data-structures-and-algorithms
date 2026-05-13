"""
活动选择问题 (Activity Selection Problem)
时间复杂度: O(n log n) (排序) + O(n) (选择) = O(n log n)
空间复杂度: O(n) (存储选中活动)
对应 C++ 源码: src/advanced_algorithm/greedy/activity_selection.cpp
"""

from __future__ import annotations


def activity_selection(activities: list[tuple[int, int]]) -> list[tuple[int, int]]:
    sorted_acts = sorted(activities, key=lambda a: a[1])
    selected: list[tuple[int, int]] = [sorted_acts[0]]
    last_end = sorted_acts[0][1]
    for i in range(1, len(sorted_acts)):
        if sorted_acts[i][0] >= last_end:
            selected.append(sorted_acts[i])
            last_end = sorted_acts[i][1]
    return selected


if __name__ == "__main__":
    activities = [(1, 4), (3, 5), (0, 6), (5, 7), (3, 9), (5, 9), (6, 10), (8, 11), (8, 12), (2, 14), (12, 16)]
    result = activity_selection(activities)
    print(f"选中活动数: {len(result)}")
    print(f"选中活动: {result}")
