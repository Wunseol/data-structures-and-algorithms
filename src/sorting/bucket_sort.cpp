#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<double>& bucket) {
    for (int i = 1; i < static_cast<int>(bucket.size()); i++) {
        double key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucketSort(vector<double>& arr) {
    int n = static_cast<int>(arr.size());
    if (n <= 1) return;

    vector<vector<double>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = static_cast<int>(n * arr[i]);
        if (bucketIndex >= n) bucketIndex = n - 1;
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (double val : buckets[i]) {
            arr[index++] = val;
        }
    }
}

void printArray(const vector<double>& arr) {
    for (double x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void showMenu() {
    cout << endl;
    cout << "*************桶排序**************************" << endl;
    cout << "1. 执行桶排序" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择操作: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "请输入元素个数: ";
            cin >> n;

            vector<double> arr(n);
            cout << "请输入" << n << "个[0,1)范围内的浮点数: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
                if (arr[i] < 0.0 || arr[i] >= 1.0) {
                    cout << "请输入[0,1)范围内的浮点数: ";
                    cin >> arr[i];
                }
            }

            cout << "排序前: ";
            printArray(arr);

            bucketSort(arr);

            cout << "桶排序结果: ";
            printArray(arr);

            cout << "时间复杂度: 平均O(n), 最坏O(n^2), 空间复杂度: O(n+k)" << endl;
        }
    } while (choice != 0);

    cout << "程序结束" << endl;
    return 0;
}
