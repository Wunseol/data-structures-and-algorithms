#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>
#include <tuple>

std::vector<int> bellmanFord(int n, const std::vector<std::tuple<int,int,int>>& edges, int source);

#endif
