#include "search_common.h"

SearchResult fibonacciSearch(const vector<int>& arr, int target) {
    SearchResult result;
    int n = static_cast<int>(arr.size());
    if (n == 0) return result;

    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        result.comparisons++;
        if (arr[i] < target) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > target) {
            result.comparisons++;
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            result.comparisons++;
            result.found = true;
            result.index = i;
            return result;
        }
    }

    if (fib1 == 1 && offset + 1 < n) {
        result.comparisons++;
        if (arr[offset + 1] == target) {
            result.found = true;
            result.index = offset + 1;
        }
    }
    return result;
}
