#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int coin_change_min(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i && dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], dp[i - c] + 1);
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

void coin_change_min_with_coins(const vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, INT_MAX);
    vector<int> choice(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < n; j++)
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                    choice[i] = j;
                }

    if (dp[amount] == INT_MAX) {
        cout << "无法凑出金额 " << amount << endl;
        return;
    }
    cout << "最少硬币数: " << dp[amount] << endl;
    cout << "硬币组合: ";
    vector<int> count(n, 0);
    int a = amount;
    while (a > 0) {
        count[choice[a]]++;
        a -= coins[choice[a]];
    }
    for (int i = 0; i < n; i++)
        if (count[i] > 0)
            cout << coins[i] << "x" << count[i] << " ";
    cout << endl;
}

int coin_change_combinations(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins)
        for (int i = c; i <= amount; i++)
            dp[i] += dp[i - c];
    return dp[amount];
}

int coin_change_permutations(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= amount; i++)
        for (int c : coins)
            if (c <= i)
                dp[i] += dp[i - c];
    return dp[amount];
}

void menu() {
    cout << "\n========== 零钱兑换 ==========" << endl;
    cout << "1. 最少硬币数" << endl;
    cout << "2. 最少硬币数 (含硬币组合)" << endl;
    cout << "3. 组合数 (不同顺序算同一种)" << endl;
    cout << "4. 排列数 (不同顺序算不同种)" << endl;
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
                int n, amount;
                cout << "输入硬币种类数: ";
                cin >> n;
                vector<int> coins(n);
                cout << "输入硬币面值: ";
                for (int i = 0; i < n; i++) cin >> coins[i];
                cout << "输入目标金额: ";
                cin >> amount;
                int res = coin_change_min(coins, amount);
                if (res == -1)
                    cout << "无法凑出金额 " << amount << endl;
                else
                    cout << "最少硬币数: " << res << endl;
                break;
            }
            case 2: {
                int n, amount;
                cout << "输入硬币种类数: ";
                cin >> n;
                vector<int> coins(n);
                cout << "输入硬币面值: ";
                for (int i = 0; i < n; i++) cin >> coins[i];
                cout << "输入目标金额: ";
                cin >> amount;
                coin_change_min_with_coins(coins, amount);
                break;
            }
            case 3: {
                int n, amount;
                cout << "输入硬币种类数: ";
                cin >> n;
                vector<int> coins(n);
                cout << "输入硬币面值: ";
                for (int i = 0; i < n; i++) cin >> coins[i];
                cout << "输入目标金额: ";
                cin >> amount;
                cout << "组合数: " << coin_change_combinations(coins, amount) << endl;
                break;
            }
            case 4: {
                int n, amount;
                cout << "输入硬币种类数: ";
                cin >> n;
                vector<int> coins(n);
                cout << "输入硬币面值: ";
                for (int i = 0; i < n; i++) cin >> coins[i];
                cout << "输入目标金额: ";
                cin >> amount;
                cout << "排列数: " << coin_change_permutations(coins, amount) << endl;
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
