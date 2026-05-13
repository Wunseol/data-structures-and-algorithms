"""
区间调度问题 / 会议室 II (Interval Scheduling / Meeting Rooms II)
时间复杂度: O(n log n) (排序) + O(n) (扫描) = O(n log n)
空间复杂度: O(n) (事件列表)
对应 C++ 源码: src/advanced_algorithm/greedy/interval_scheduling.cpp
"""

from __future__ import annotations


def interval_scheduling(intervals: list[tuple[int, int]]) -> int:
    events: list[tuple[int, int]] = []
    for start, end in intervals:
        events.append((start, 1))
        events.append((end, -1))
    events.sort(key=lambda e: (e[0], e[1]))
    rooms = 0
    max_rooms = 0
    for _, event_type in events:
        rooms += event_type
        max_rooms = max(max_rooms, rooms)
    return max_rooms


if __name__ == "__main__":
    intervals = [(0, 30), (5, 10), (15, 20)]
    result = interval_scheduling(intervals)
    print(f"最少需要会议室数: {result}")
    intervals2 = [(1, 3), (2, 4), (3, 5)]
    result2 = interval_scheduling(intervals2)
    print(f"最少需要会议室数: {result2}")
