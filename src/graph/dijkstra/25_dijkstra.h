#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <utility>

std::vector<int> dijkstra(int n, const std::vector<std::vector<std::pair<int,int>>>& adj, int source);

#endif
