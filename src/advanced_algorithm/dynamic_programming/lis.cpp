#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis_dp(const vector<int>& nums, vector<int>& seq) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    int max_len = 1, max_idx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            max_idx = i;
        }
    }

    seq.clear();
    for (int i = max_idx; i != -1; i = parent[i])
        seq.push_back(nums[i]);
    reverse(seq.begin(), seq.end());
    return max_len;
}

int lis_binary(const vector<int>& nums, vector<int>& seq) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> tails;
    vector<int> tail_indices;
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
        int pos = it - tails.begin();
        if (it == tails.end()) {
            tails.push_back(nums[i]);
            tail_indices.push_back(i);
        } else {
            *it = nums[i];
            tail_indices[pos] = i;
        }
        if (pos > 0)
            parent[i] = tail_indices[pos - 1];
    }

    int len = tails.size();
    seq.clear();
    for (int i = tail_indices[len - 1]; i != -1; i = parent[i])
        seq.push_back(nums[i]);
    reverse(seq.begin(), seq.end());
    return len;
}

int count_lis(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);
    int max_len = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        max_len = max(max_len, dp[i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] == max_len)
            total += cnt[i];
    return total;
}

void menu() {
    cout << "\n========== 最长递增子序列 ==========" << endl;
    cout << "1. O(n^2) DP方法" << endl;
    cout << "2. O(n log n) 二分搜索方法" << endl;
    cout << "3. 统计LIS个数" << endl;
    cout << "4. 性能对比" << endl;
    cout << "0. 退出" << endl;
    cout << "====================================" << endl;
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
                vector<int> seq;
                int len = lis_dp(nums, seq);
                cout << "LIS长度: " << len << endl;
                cout << "LIS序列: ";
                for (int i = 0; i < len; i++) {
                    if (i > 0) cout << " ";
                    cout << seq[i];
                }
                cout << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                vector<int> seq;
                int len = lis_binary(nums, seq);
                cout << "LIS长度: " << len << endl;
                cout << "LIS序列: ";
                for (int i = 0; i < len; i++) {
                    if (i > 0) cout << " ";
                    cout << seq[i];
                }
                cout << endl;
                break;
            }
            case 3: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "LIS个数: " << count_lis(nums) << endl;
                break;
            }
            case 4: {
                int n;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入数组元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];

                vector<int> seq1, seq2;
                auto t1 = clock();
                int len1 = lis_dp(nums, seq1);
                auto t2 = clock();
                int len2 = lis_binary(nums, seq2);
                auto t3 = clock();

                cout << "O(n^2) DP:      长度=" << len1
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "O(n log n) 二分: 长度=" << len2
                     << "  耗时: " << double(t3 - t2) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
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
