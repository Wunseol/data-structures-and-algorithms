#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_complete_2d(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= wt[i - 1])
                dp[i][w] = max(dp[i][w], dp[i][w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[n][W];
}

int knapsack_complete_1d(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = wt[i]; w <= W; w++)
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

void knapsack_complete_with_count(int W, const vector<int>& wt, const vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    vector<vector<int>> count(n, vector<int>(W + 1, 0));

    for (int i = 0; i < n; i++)
        for (int w = wt[i]; w <= W; w++) {
            if (dp[w - wt[i]] + val[i] > dp[w]) {
                dp[w] = dp[w - wt[i]] + val[i];
                count[i][w] = count[i][w - wt[i]] + 1;
            }
        }

    cout << "最大价值: " << dp[W] << endl;
    cout << "物品选择方案:" << endl;
    int w = W;
    for (int i = n - 1; i >= 0; i--) {
        if (count[i][w] > 0) {
            cout << "  物品" << i + 1 << "(w=" << wt[i] << ",v=" << val[i]
                 << ") x" << count[i][w] << endl;
        }
    }
}

void print_dp_table(int W, int n, const vector<int>& wt, const vector<int>& val) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= wt[i - 1])
                dp[i][w] = max(dp[i][w], dp[i][w - wt[i - 1]] + val[i - 1]);
        }

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
    cout << "\n========== 完全背包问题 ==========" << endl;
    cout << "1. 2D DP" << endl;
    cout << "2. 1D 空间优化 DP" << endl;
    cout << "3. 打印选择方案" << endl;
    cout << "4. 打印DP表" << endl;
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
                cout << "输入物品种类n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每种物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每种物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                cout << "最大价值: " << knapsack_complete_2d(W, wt, val) << endl;
                break;
            }
            case 2: {
                int n, W;
                cout << "输入物品种类n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每种物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每种物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                cout << "最大价值: " << knapsack_complete_1d(W, wt, val) << endl;
                break;
            }
            case 3: {
                int n, W;
                cout << "输入物品种类n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每种物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每种物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                knapsack_complete_with_count(W, wt, val);
                break;
            }
            case 4: {
                int n, W;
                cout << "输入物品种类n: ";
                cin >> n;
                cout << "输入背包容量W: ";
                cin >> W;
                vector<int> wt(n), val(n);
                cout << "输入每种物品的重量: ";
                for (int i = 0; i < n; i++) cin >> wt[i];
                cout << "输入每种物品的价值: ";
                for (int i = 0; i < n; i++) cin >> val[i];
                print_dp_table(W, n, wt, val);
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
