#include "03_search_common.h"

SearchResult linearSearch(const vector<int>& arr, int target) {
    SearchResult result;
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        result.comparisons++;
        if (arr[i] == target) {
            result.found = true;
            result.index = i;
            return result;
        }
    }
    return result;
}

SearchResult sentinelLinearSearch(vector<int>& arr, int target) {
    SearchResult result;
    int n = static_cast<int>(arr.size());
    if (n == 0) return result;

    int last = arr[n - 1];
    arr[n - 1] = target;

    int i = 0;
    while (arr[i] != target) {
        result.comparisons++;
        i++;
    }
    result.comparisons++;

    arr[n - 1] = last;

    if (i < n - 1 || arr[n - 1] == target) {
        result.found = true;
        result.index = i;
        if (i == n - 1 && last != target) {
            result.comparisons++;
        }
    }
    return result;
}
