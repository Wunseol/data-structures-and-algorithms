#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSortBasic(const vector<int>& arr) {
    if (arr.empty()) return {};

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    for (int x : arr) {
        count[x - minVal]++;
    }

    vector<int> output;
    output.reserve(arr.size());
    for (int i = 0; i < range; i++) {
        while (count[i]-- > 0) {
            output.push_back(i + minVal);
        }
    }
    return output;
}

vector<int> countingSortStable(const vector<int>& arr) {
    if (arr.empty()) return {};

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    for (int x : arr) {
        count[x - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    vector<int> output(arr.size());
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    return output;
}

void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void showMenu() {
    cout << endl;
    cout << "*************计数排序************************" << endl;
    cout << "1. 基本计数排序" << endl;
    cout << "2. 稳定计数排序" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择排序方式: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int n;
            cout << "请输入元素个数: ";
            cin >> n;

            vector<int> arr(n);
            cout << "请输入" << n << "个整数: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            cout << "排序前: ";
            printArray(arr);

            vector<int> sorted;
            if (choice == 1) {
                sorted = countingSortBasic(arr);
                cout << "基本计数排序结果: ";
            } else {
                sorted = countingSortStable(arr);
                cout << "稳定计数排序结果: ";
            }
            printArray(sorted);

            cout << "时间复杂度: O(n+k), 空间复杂度: O(n+k)" << endl;
        }
    } while (choice != 0);

    cout << "程序结束" << endl;
    return 0;
}
