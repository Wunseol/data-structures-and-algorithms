#include "search_common.h"
#include "linear_search.cpp"
#include "binary_search.cpp"
#include "interpolation_search.cpp"
#include "fibonacci_search.cpp"

void printResult(const SearchResult& result, int target) {
    if (result.found) {
        cout << "找到目标值 " << target << ", 下标: " << result.index
             << ", 比较次数: " << result.comparisons << endl;
    } else {
        cout << "未找到目标值 " << target << ", 比较次数: " << result.comparisons << endl;
    }
}

void inputArray(vector<int>& arr) {
    int n;
    cout << "请输入元素个数: ";
    cin >> n;
    arr.resize(n);
    cout << "请输入" << n << "个整数: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void inputSortedArray(vector<int>& arr) {
    int n;
    cout << "请输入元素个数: ";
    cin >> n;
    arr.resize(n);
    cout << "请输入" << n << "个已排序的整数(升序): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void showMenu() {
    cout << endl;
    cout << "*************搜索算法************************" << endl;
    cout << "1. 线性搜索" << endl;
    cout << "2. 哨兵线性搜索" << endl;
    cout << "3. 二分搜索" << endl;
    cout << "4. 下界搜索(Lower Bound)" << endl;
    cout << "5. 上界搜索(Upper Bound)" << endl;
    cout << "6. 旋转数组搜索" << endl;
    cout << "7. 插值搜索" << endl;
    cout << "8. 斐波那契搜索" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择搜索方式: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 0) break;

        int target;
        vector<int> arr;
        vector<int> arrCopy;

        switch (choice) {
            case 1: {
                inputArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = linearSearch(arr, target);
                printResult(result, target);
                cout << "时间复杂度: O(n)" << endl;
                break;
            }
            case 2: {
                inputArray(arr);
                arrCopy = arr;
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = sentinelLinearSearch(arrCopy, target);
                printResult(result, target);
                cout << "时间复杂度: O(n)" << endl;
                break;
            }
            case 3: {
                inputSortedArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = binarySearch(arr, target);
                printResult(result, target);
                cout << "时间复杂度: O(log n)" << endl;
                break;
            }
            case 4: {
                inputSortedArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = lowerBound(arr, target);
                printResult(result, target);
                if (result.found) {
                    cout << "(第一个等于目标值的元素下标)" << endl;
                }
                cout << "时间复杂度: O(log n)" << endl;
                break;
            }
            case 5: {
                inputSortedArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = upperBound(arr, target);
                printResult(result, target);
                if (result.found) {
                    cout << "(最后一个等于目标值的元素下标)" << endl;
                }
                cout << "时间复杂度: O(log n)" << endl;
                break;
            }
            case 6: {
                inputArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = searchRotatedArray(arr, target);
                printResult(result, target);
                cout << "时间复杂度: O(log n)" << endl;
                break;
            }
            case 7: {
                inputSortedArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = interpolationSearch(arr, target);
                printResult(result, target);
                cout << "时间复杂度: 平均O(log log n), 最坏O(n)" << endl;
                break;
            }
            case 8: {
                inputSortedArray(arr);
                cout << "请输入目标值: ";
                cin >> target;
                SearchResult result = fibonacciSearch(arr, target);
                printResult(result, target);
                cout << "时间复杂度: O(log n)" << endl;
                break;
            }
            default:
                cout << "无效选择，请重新输入!" << endl;
                break;
        }
    } while (choice != 0);

    cout << "程序结束" << endl;
    return 0;
}
