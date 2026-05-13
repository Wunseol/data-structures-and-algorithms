#include "self_test.h"

static int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}

static int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

static void test_linear_search(void) {
    printf("  [Linear Search]\n");

    int arr[] = {5, 3, 8, 1, 9, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    ASSERT_EQ(linear_search(arr, n, 5), 0);
    ASSERT_EQ(linear_search(arr, n, 2), 6);
    ASSERT_EQ(linear_search(arr, n, 8), 2);
    ASSERT_EQ(linear_search(arr, n, 99), -1);

    int single[] = {42};
    ASSERT_EQ(linear_search(single, 1, 42), 0);
    ASSERT_EQ(linear_search(single, 1, 0), -1);

    int empty_n = 0;
    ASSERT_EQ(linear_search(arr, empty_n, 5), -1);
}

static void test_binary_search(void) {
    printf("  [Binary Search]\n");

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    ASSERT_EQ(binary_search(arr, n, 1), 0);
    ASSERT_EQ(binary_search(arr, n, 19), 9);
    ASSERT_EQ(binary_search(arr, n, 11), 5);
    ASSERT_EQ(binary_search(arr, n, 7), 3);
    ASSERT_EQ(binary_search(arr, n, 0), -1);
    ASSERT_EQ(binary_search(arr, n, 20), -1);
    ASSERT_EQ(binary_search(arr, n, 6), -1);

    int single[] = {42};
    ASSERT_EQ(binary_search(single, 1, 42), 0);
    ASSERT_EQ(binary_search(single, 1, 0), -1);

    int two[] = {10, 20};
    ASSERT_EQ(binary_search(two, 2, 10), 0);
    ASSERT_EQ(binary_search(two, 2, 20), 1);
    ASSERT_EQ(binary_search(two, 2, 15), -1);
}

static void test_binary_search_even_odd(void) {
    printf("  [Binary Search - even/odd length]\n");

    int odd[] = {2, 4, 6, 8, 10};
    ASSERT_EQ(binary_search(odd, 5, 6), 2);
    ASSERT_EQ(binary_search(odd, 5, 2), 0);
    ASSERT_EQ(binary_search(odd, 5, 10), 4);
    ASSERT_EQ(binary_search(odd, 5, 5), -1);

    int even[] = {1, 3, 5, 7};
    ASSERT_EQ(binary_search(even, 4, 1), 0);
    ASSERT_EQ(binary_search(even, 4, 7), 3);
    ASSERT_EQ(binary_search(even, 4, 4), -1);
}

int main(void) {
    TEST_BEGIN("Searching Algorithms");

    test_linear_search();
    test_binary_search();
    test_binary_search_even_odd();

    TEST_END();
}
