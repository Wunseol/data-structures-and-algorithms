#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob_basic(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    return dp[n - 1];
}

int rob_basic_optimized(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

void rob_basic_with_path(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) { cout << "金额: 0" << endl; return; }
    if (n == 1) { cout << "金额: " << nums[0] << endl; cout << "抢劫: 房屋0" << endl; return; }
    vector<int> dp(n);
    vector<bool> take(n, false);
    dp[0] = nums[0]; take[0] = true;
    dp[1] = max(nums[0], nums[1]); take[1] = (nums[1] > nums[0]);
    for (int i = 2; i < n; i++) {
        if (dp[i - 1] > dp[i - 2] + nums[i]) {
            dp[i] = dp[i - 1];
            take[i] = false;
        } else {
            dp[i] = dp[i - 2] + nums[i];
            take[i] = true;
        }
    }
    cout << "最大金额: " << dp[n - 1] << endl;
    cout << "抢劫的房屋: ";
    vector<int> houses;
    for (int i = n - 1; i >= 0;) {
        if (take[i]) {
            houses.push_back(i);
            i -= 2;
        } else {
            i -= 1;
        }
    }
    reverse(houses.begin(), houses.end());
    for (int i = 0; i < (int)houses.size(); i++) {
        if (i > 0) cout << ", ";
        cout << "房屋" << houses[i] << "(金额" << nums[houses[i]] << ")";
    }
    cout << endl;
}

int rob_circular(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    auto rob_range = [](const vector<int>& arr, int l, int r) -> int {
        int prev2 = arr[l];
        int prev1 = max(arr[l], arr[l + 1]);
        for (int i = l + 2; i <= r; i++) {
            int curr = max(prev1, prev2 + arr[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    };

    return max(rob_range(nums, 0, n - 2), rob_range(nums, 1, n - 1));
}

void menu() {
    cout << "\n========== 打家劫舍 ==========" << endl;
    cout << "1. 基本DP (线性排列)" << endl;
    cout << "2. 空间优化DP" << endl;
    cout << "3. 基本DP (含抢劫路径)" << endl;
    cout << "4. 环形排列 (首尾相邻)" << endl;
    cout << "0. 退出" << endl;
    cout << "==============================" << endl;
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
                cout << "输入房屋数量: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入每间房屋的金额: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "最大金额: " << rob_basic(nums) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入房屋数量: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入每间房屋的金额: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "最大金额: " << rob_basic_optimized(nums) << endl;
                break;
            }
            case 3: {
                int n;
                cout << "输入房屋数量: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入每间房屋的金额: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                rob_basic_with_path(nums);
                break;
            }
            case 4: {
                int n;
                cout << "输入房屋数量: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入每间房屋的金额: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "最大金额: " << rob_circular(nums) << endl;
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
