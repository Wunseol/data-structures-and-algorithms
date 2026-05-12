#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct SubarrayInfo {
    int max_sum;
    int start;
    int end;
};

SubarrayInfo max_crossing(const vector<int>& nums, int l, int m, int r) {
    int left_sum = INT_MIN, sum = 0, left_idx = m;
    for (int i = m; i >= l; i--) {
        sum += nums[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_idx = i;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    int right_idx = m + 1;
    for (int i = m + 1; i <= r; i++) {
        sum += nums[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_idx = i;
        }
    }
    return {left_sum + right_sum, left_idx, right_idx};
}

SubarrayInfo max_subarray_dc(const vector<int>& nums, int l, int r) {
    if (l == r) return {nums[l], l, r};

    int m = l + (r - l) / 2;
    auto left = max_subarray_dc(nums, l, m);
    auto right = max_subarray_dc(nums, m + 1, r);
    auto cross = max_crossing(nums, l, m, r);

    if (left.max_sum >= right.max_sum && left.max_sum >= cross.max_sum)
        return left;
    else if (right.max_sum >= left.max_sum && right.max_sum >= cross.max_sum)
        return right;
    else
        return cross;
}

SubarrayInfo kadane(const vector<int>& nums) {
    int n = nums.size();
    int max_sum = nums[0], curr_sum = nums[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < n; i++) {
        if (curr_sum + nums[i] < nums[i]) {
            curr_sum = nums[i];
            temp_start = i;
        } else {
            curr_sum += nums[i];
        }
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }
    }
    return {max_sum, start, end};
}

void print_array(const vector<int>& nums, int start, int end) {
    cout << "子数组: [";
    for (int i = start; i <= end; i++) {
        if (i > start) cout << ", ";
        cout << nums[i];
    }
    cout << "]" << endl;
}

void menu() {
    cout << "\n========== 最大子数组 (分治) ==========" << endl;
    cout << "1. 分治法 O(n log n)" << endl;
    cout << "2. Kadane算法 O(n)" << endl;
    cout << "3. 性能对比" << endl;
    cout << "0. 退出" << endl;
    cout << "=======================================" << endl;
    cout << "请选择: ";
}

int main() {
    int choice;
    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                auto res = max_subarray_dc(nums, 0, n - 1);
                cout << "最大子数组和: " << res.max_sum << endl;
                cout << "起始索引: " << res.start << ", 结束索引: " << res.end << endl;
                print_array(nums, res.start, res.end);
                break;
            }
            case 2: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                auto res = kadane(nums);
                cout << "最大子数组和: " << res.max_sum << endl;
                cout << "起始索引: " << res.start << ", 结束索引: " << res.end << endl;
                print_array(nums, res.start, res.end);
                break;
            }
            case 3: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];

                auto t1 = clock();
                auto r1 = max_subarray_dc(nums, 0, n - 1);
                auto t2 = clock();
                auto r2 = kadane(nums);
                auto t3 = clock();

                cout << "\n分治法 O(n log n): 和=" << r1.max_sum
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "Kadane O(n):       和=" << r2.max_sum
                     << "  耗时: " << double(t3 - t2) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "\n结论: Kadane算法更优, 分治法具有教学意义" << endl;
                break;
            }
            case 0:
                cout << "再见!" << endl;
                break;
            default:
                cout << "无效选择!" << endl;
        }
    } while (choice != 0);
    return 0;
}
