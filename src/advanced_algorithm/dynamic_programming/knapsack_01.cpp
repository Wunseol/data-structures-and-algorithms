#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_01_2d(int W, const vector<int>& wt, const vector<int>& val, vector<int>& selected) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= wt[i - 1])
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
        }
    }

    selected.clear();
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i - 1);
            w -= wt[i - 1];
        }
    }
    reverse(selected.begin(), selected.end());
    return dp[n][W];
}

int knapsack_01_1d(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--)
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

void print_dp_table(int W, int n, const vector<vector<int>>& dp) {
    cout << "\nDP表:" << endl;
    cout << "     ";
    for (int w = 0; w <= W; w++)
        cout << w << "\t";
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << "i=" << i << "  ";
        for (int w = 0; w <= W; w++)
            cout << dp[i][w] << "\t";
        cout << endl;
    }
}

void menu() {
    cout << "\n========== 0-1 背包问题 ==========" << endl;
    cout << "1. 2D DP (打印选中物品)" << endl;
    cout << "2. 1D 空间优化 DP" << endl;
    cout << "3. 打印DP表" << endl;
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
                int n, W;
                cout << "输入物品数量n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每个物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每个物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                vector<int> selected;
                int max_val = knapsack_01_2d(W, wt, val, selected);
                cout << "最大价值: " << max_val << endl;
                cout << "选中物品: ";
                int total_w = 0;
                for (int i = 0; i < (int)selected.size(); i++) {
                    int idx = selected[i];
                    if (i > 0) cout << ", ";
                    cout << "物品" << idx + 1 << "(w=" << wt[idx] << ",v=" << val[idx] << ")";
                    total_w += wt[idx];
                }
                cout << endl;
                cout << "总重量: " << total_w << "/" << W << endl;
                break;
            }
            case 2: {
                int n, W;
                cout << "输入物品数量n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每个物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每个物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                cout << "最大价值: " << knapsack_01_1d(W, wt, val) << endl;
                break;
            }
            case 3: {
                int n, W;
                cout << "输入物品数量n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每个物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每个物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];

                vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
                for (int i = 1; i <= n; i++)
                    for (int w = 0; w <= W; w++) {
                        dp[i][w] = dp[i - 1][w];
                        if (w >= wt[i - 1])
                            dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
                    }
                print_dp_table(W, n, dp);
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
