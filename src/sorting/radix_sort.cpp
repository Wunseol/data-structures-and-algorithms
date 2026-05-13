#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSortByDigit(vector<int>& arr, int exp) {
    int n = static_cast<int>(arr.size());
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void showMenu() {
    cout << endl;
    cout << "*************基数排序(LSD)*******************" << endl;
    cout << "1. 执行基数排序" << endl;
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

            vector<int> arr(n);
            cout << "请输入" << n << "个非负整数: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
                if (arr[i] < 0) {
                    cout << "基数排序仅支持非负整数，请重新输入: ";
                    cin >> arr[i];
                }
            }

            cout << "排序前: ";
            printArray(arr);

            radixSort(arr);

            cout << "基数排序结果: ";
            printArray(arr);

            int maxVal = *max_element(arr.begin(), arr.end());
            int d = 0;
            while (maxVal > 0) { maxVal /= 10; d++; }
            cout << "时间复杂度: O(d*(n+k)) = O(" << d << "*(n+10)), 空间复杂度: O(n+k)" << endl;
        }
    } while (choice != 0);

    cout << "程序结束" << endl;
    return 0;
}
