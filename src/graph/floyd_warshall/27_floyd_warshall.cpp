#include "27_floyd_warshall.h"
#include <algorithm>

std::vector<std::vector<int>> floydWarshall(int n, const std::vector<std::vector<int>>& dist) {
    std::vector<std::vector<int>> d = dist;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][k] < INT_MAX && d[k][j] < INT_MAX) {
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    return d;
}
