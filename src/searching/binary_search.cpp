#include "search_common.h"

SearchResult binarySearch(const vector<int>& arr, int target) {
    SearchResult result;
    int low = 0, high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        result.comparisons++;
        if (arr[mid] == target) {
            result.found = true;
            result.index = mid;
            return result;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

SearchResult lowerBound(const vector<int>& arr, int target) {
    SearchResult result;
    int low = 0, high = static_cast<int>(arr.size());

    while (low < high) {
        int mid = low + (high - low) / 2;
        result.comparisons++;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if (low < static_cast<int>(arr.size()) && arr[low] == target) {
        result.found = true;
        result.index = low;
    }
    return result;
}

SearchResult upperBound(const vector<int>& arr, int target) {
    SearchResult result;
    int low = 0, high = static_cast<int>(arr.size());

    while (low < high) {
        int mid = low + (high - low) / 2;
        result.comparisons++;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    if (low > 0 && arr[low - 1] == target) {
        result.found = true;
        result.index = low - 1;
    }
    return result;
}

SearchResult searchRotatedArray(const vector<int>& arr, int target) {
    SearchResult result;
    int low = 0, high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        result.comparisons++;
        if (arr[mid] == target) {
            result.found = true;
            result.index = mid;
            return result;
        }

        if (arr[low] <= arr[mid]) {
            result.comparisons++;
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            result.comparisons++;
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return result;
}
