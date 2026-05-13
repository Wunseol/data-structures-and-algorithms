#ifndef SEARCH_COMMON_H
#define SEARCH_COMMON_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SearchResult {
    bool found;
    int index;
    int comparisons;
    SearchResult() : found(false), index(-1), comparisons(0) {}
};

#endif
