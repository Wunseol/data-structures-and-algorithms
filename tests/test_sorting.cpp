#include "self_test.h"

static void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

static void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

static void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

static void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L);
    free(R);
}

static void merge_sort_impl(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_impl(arr, l, m);
        merge_sort_impl(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

static void merge_sort(int arr[], int n) {
    merge_sort_impl(arr, 0, n - 1);
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}

static void quick_sort_impl(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_impl(arr, low, pi - 1);
        quick_sort_impl(arr, pi + 1, high);
    }
}

static void quick_sort(int arr[], int n) {
    quick_sort_impl(arr, 0, n - 1);
}

static bool is_sorted(const int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1]) return false;
    return true;
}

static void test_sort(const char *name, void (*sort_fn)(int[], int)) {
    printf("  [%s]\n", name);
    int arr[] = {64, 25, 12, 22, 11, 90, 3, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_fn(arr, n);

    ASSERT_TRUE(is_sorted(arr, n));
    ASSERT_EQ(arr[0], 3);
    ASSERT_EQ(arr[1], 11);
    ASSERT_EQ(arr[2], 12);
    ASSERT_EQ(arr[n - 1], 90);
}

static void test_sort_single(const char *name, void (*sort_fn)(int[], int)) {
    printf("  [%s - single element]\n", name);
    int arr[] = {42};
    sort_fn(arr, 1);
    ASSERT_EQ(arr[0], 42);
}

static void test_sort_sorted(const char *name, void (*sort_fn)(int[], int)) {
    printf("  [%s - already sorted]\n", name);
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_fn(arr, n);
    ASSERT_TRUE(is_sorted(arr, n));
}

static void test_sort_reverse(const char *name, void (*sort_fn)(int[], int)) {
    printf("  [%s - reverse sorted]\n", name);
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_fn(arr, n);
    ASSERT_TRUE(is_sorted(arr, n));
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[n - 1], 5);
}

int main(void) {
    TEST_BEGIN("Sorting Algorithms");

    test_sort("Bubble Sort", bubble_sort);
    test_sort("Insertion Sort", insertion_sort);
    test_sort("Selection Sort", selection_sort);
    test_sort("Merge Sort", merge_sort);
    test_sort("Quick Sort", quick_sort);

    test_sort_single("Bubble Sort", bubble_sort);
    test_sort_single("Insertion Sort", insertion_sort);
    test_sort_single("Selection Sort", selection_sort);
    test_sort_single("Merge Sort", merge_sort);
    test_sort_single("Quick Sort", quick_sort);

    test_sort_sorted("Bubble Sort", bubble_sort);
    test_sort_sorted("Insertion Sort", insertion_sort);
    test_sort_sorted("Selection Sort", selection_sort);
    test_sort_sorted("Merge Sort", merge_sort);
    test_sort_sorted("Quick Sort", quick_sort);

    test_sort_reverse("Bubble Sort", bubble_sort);
    test_sort_reverse("Insertion Sort", insertion_sort);
    test_sort_reverse("Selection Sort", selection_sort);
    test_sort_reverse("Merge Sort", merge_sort);
    test_sort_reverse("Quick Sort", quick_sort);

    TEST_END();
}
