#include "search_common.h"

SearchResult interpolationSearch(const vector<int>& arr, int target) {
    SearchResult result;
    int low = 0, high = static_cast<int>(arr.size()) - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        result.comparisons++;
        if (arr[high] == arr[low]) {
            if (arr[low] == target) {
                result.found = true;
                result.index = low;
            }
            return result;
        }

        int pos = low + static_cast<int>(
            (static_cast<double>(target - arr[low]) / (arr[high] - arr[low])) * (high - low)
        );

        if (pos < low) pos = low;
        if (pos > high) pos = high;

        result.comparisons++;
        if (arr[pos] == target) {
            result.found = true;
            result.index = pos;
            return result;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return result;
}
