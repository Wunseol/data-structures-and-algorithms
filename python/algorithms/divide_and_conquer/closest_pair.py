"""
最近点对问题 (Closest Pair of Points)
时间复杂度: O(n log n)
空间复杂度: O(n) (排序 + 递归)
对应 C++ 源码: src/advanced_algorithm/divide_and_conquer/closest_pair.cpp
"""

from __future__ import annotations

import math


def closest_pair(points: list[tuple[float, float]]) -> float:
    sorted_points = sorted(points, key=lambda p: p[0])

    def dist(p1: tuple[float, float], p2: tuple[float, float]) -> float:
        return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

    def brute(pts: list[tuple[float, float]]) -> float:
        min_d = float("inf")
        for i in range(len(pts)):
            for j in range(i + 1, len(pts)):
                d = dist(pts[i], pts[j])
                if d < min_d:
                    min_d = d
        return min_d

    def dc(pts: list[tuple[float, float]], left: int, right: int) -> float:
        if right - left + 1 <= 3:
            return brute(pts[left : right + 1])
        mid = left + (right - left) // 2
        mid_x = pts[mid][0]
        dl = dc(pts, left, mid)
        dr = dc(pts, mid + 1, right)
        d = min(dl, dr)
        strip: list[tuple[float, float]] = []
        for i in range(left, right + 1):
            if abs(pts[i][0] - mid_x) < d:
                strip.append(pts[i])
        strip.sort(key=lambda p: p[1])
        for i in range(len(strip)):
            for j in range(i + 1, len(strip)):
                if strip[j][1] - strip[i][1] >= d:
                    break
                dd = dist(strip[i], strip[j])
                if dd < d:
                    d = dd
        return d

    return dc(sorted_points, 0, len(sorted_points) - 1)


if __name__ == "__main__":
    points = [(2.0, 3.0), (12.0, 30.0), (40.0, 50.0), (5.0, 1.0), (12.0, 10.0), (3.0, 4.0)]
    result = closest_pair(points)
    print(f"最近点对距离: {result:.6f}")
