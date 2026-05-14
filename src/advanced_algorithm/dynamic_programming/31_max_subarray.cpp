#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct SubarrayResult {
    int max_sum;
    int start;
    int end;
};

SubarrayResult kadane(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {0, -1, -1};

    int max_sum = nums[0];
    int curr_sum = nums[0];
    int start = 0, end = 0;
    int temp_start = 0;

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

SubarrayResult kadane_allow_empty(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {0, -1, -1};

    int max_sum = 0;
    int curr_sum = 0;
    int start = 0, end = -1;
    int temp_start = 0;

    for (int i = 0; i < n; i++) {
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

int max_subarray_circular(const vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for (int x : nums) total += x;

    int max_sum = nums[0], curr_max = nums[0];
    int min_sum = nums[0], curr_min = nums[0];

    for (int i = 1; i < n; i++) {
        curr_max = max(nums[i], curr_max + nums[i]);
        max_sum = max(max_sum, curr_max);
        curr_min = min(nums[i], curr_min + nums[i]);
        min_sum = min(min_sum, curr_min);
    }

    if (max_sum < 0) return max_sum;
    return max(max_sum, total - min_sum);
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
    cout << "\n========== 最大子数组和 ==========" << endl;
    cout << "1. Kadane算法 (不允许空子数组)" << endl;
    cout << "2. Kadane算法 (允许空子数组)" << endl;
    cout << "3. 环形数组最大子数组和" << endl;
    cout << "0. 退出" << endl;
    cout << "==================================" << endl;
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
                auto res = kadane(nums);
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
                auto res = kadane_allow_empty(nums);
                if (res.end == -1) {
                    cout << "最大子数组和: 0 (空子数组)" << endl;
                } else {
                    cout << "最大子数组和: " << res.max_sum << endl;
                    cout << "起始索引: " << res.start << ", 结束索引: " << res.end << endl;
                    print_array(nums, res.start, res.end);
                }
                break;
            }
            case 3: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "环形数组最大子数组和: " << max_subarray_circular(nums) << endl;
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
