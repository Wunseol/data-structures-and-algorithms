#include <iostream>
#include <vector>

using namespace std;

int climb_stairs_basic(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

void climb_stairs_basic_with_path(int n) {
    if (n <= 0) return;
    vector<int> dp(n + 1);
    vector<vector<vector<int>>> paths(n + 1);
    dp[0] = 1;
    paths[0].push_back({});
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        if (i >= 1 && dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
            for (auto& p : paths[i - 1]) {
                auto np = p;
                np.push_back(1);
                paths[i].push_back(np);
            }
        }
        if (i >= 2 && dp[i - 2] > 0) {
            dp[i] += dp[i - 2];
            for (auto& p : paths[i - 2]) {
                auto np = p;
                np.push_back(2);
                paths[i].push_back(np);
            }
        }
    }
    cout << "方法总数: " << dp[n] << endl;
    cout << "所有路径:" << endl;
    for (auto& p : paths[n]) {
        cout << "  ";
        for (int i = 0; i < (int)p.size(); i++) {
            if (i > 0) cout << "->";
            cout << p[i];
        }
        cout << endl;
    }
}

int climb_stairs_optimized(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int climb_stairs_k_steps(int n, int k) {
    if (n == 0) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++)
            dp[i] += dp[i - j];
    return dp[n];
}

int climb_stairs_min_cost(vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];
    int prev2 = cost[0], prev1 = cost[0] + cost[1];
    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

void menu() {
    cout << "\n========== 爬楼梯问题 ==========" << endl;
    cout << "1. 基本DP (O(n)空间)" << endl;
    cout << "2. 空间优化DP (O(1)空间)" << endl;
    cout << "3. 打印所有路径" << endl;
    cout << "4. K步爬楼梯" << endl;
    cout << "5. 最小花费爬楼梯" << endl;
    cout << "0. 退出" << endl;
    cout << "================================" << endl;
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
                cout << "输入台阶数n: ";
                cin >> n;
                cout << "方法数: " << climb_stairs_basic(n) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入台阶数n: ";
                cin >> n;
                cout << "方法数: " << climb_stairs_optimized(n) << endl;
                break;
            }
            case 3: {
                int n;
                cout << "输入台阶数n (建议n<=15): ";
                cin >> n;
                climb_stairs_basic_with_path(n);
                break;
            }
            case 4: {
                int n, k;
                cout << "输入台阶数n: ";
                cin >> n;
                cout << "输入最大步数k: ";
                cin >> k;
                cout << "方法数: " << climb_stairs_k_steps(n, k) << endl;
                break;
            }
            case 5: {
                int n;
                cout << "输入台阶数n: ";
                cin >> n;
                vector<int> cost(n);
                cout << "输入每阶的花费: ";
                for (int i = 0; i < n; i++) cin >> cost[i];
                cout << "最小花费: " << climb_stairs_min_cost(cost) << endl;
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
