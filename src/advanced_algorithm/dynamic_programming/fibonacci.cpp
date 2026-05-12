#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

class FibMemo {
    vector<long long> memo;
public:
    FibMemo(int n) : memo(n + 1, -1) {}

    long long solve(int n) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 1) + solve(n - 2);
    }
};

long long fib_dp(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

void multiply(long long F[2][2], long long M[2][2]) {
    long long a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    long long b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    long long c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    long long d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = a; F[0][1] = b;
    F[1][0] = c; F[1][1] = d;
}

void power(long long F[2][2], int n) {
    if (n == 0 || n == 1) return;
    long long M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

long long fib_matrix(int n) {
    if (n == 0) return 0;
    long long F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

void print_fib_sequence(int n) {
    cout << "Fibonacci序列 (0~" << n << "):" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "F(" << i << ")=" << fib_dp(i) << "  ";
        if (i % 5 == 4) cout << endl;
    }
    if (n % 5 != 4) cout << endl;
}

void menu() {
    cout << "\n========== Fibonacci 数列 ==========" << endl;
    cout << "1. 递归法 (O(2^n))" << endl;
    cout << "2. 记忆化搜索 (O(n))" << endl;
    cout << "3. DP表法 (O(n))" << endl;
    cout << "4. 矩阵快速幂 (O(log n))" << endl;
    cout << "5. 打印Fibonacci序列" << endl;
    cout << "6. 性能对比" << endl;
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
                cout << "输入n (建议n<=45): ";
                cin >> n;
                cout << "F(" << n << ") = " << fib_recursive(n) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入n: ";
                cin >> n;
                FibMemo fm(n);
                cout << "F(" << n << ") = " << fm.solve(n) << endl;
                break;
            }
            case 3: {
                int n;
                cout << "输入n: ";
                cin >> n;
                cout << "F(" << n << ") = " << fib_dp(n) << endl;
                break;
            }
            case 4: {
                int n;
                cout << "输入n: ";
                cin >> n;
                cout << "F(" << n << ") = " << fib_matrix(n) << endl;
                break;
            }
            case 5: {
                int n;
                cout << "输入n: ";
                cin >> n;
                print_fib_sequence(n);
                break;
            }
            case 6: {
                int n;
                cout << "输入n (建议n<=45): ";
                cin >> n;
                cout << "\n--- 性能对比 ---" << endl;

                auto t1 = clock();
                long long r1 = fib_recursive(n);
                auto t2 = clock();
                cout << "递归法:       F(" << n << ")=" << r1
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

                t1 = clock();
                FibMemo fm(n);
                long long r2 = fm.solve(n);
                t2 = clock();
                cout << "记忆化搜索:   F(" << n << ")=" << r2
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

                t1 = clock();
                long long r3 = fib_dp(n);
                t2 = clock();
                cout << "DP表法:       F(" << n << ")=" << r3
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

                t1 = clock();
                long long r4 = fib_matrix(n);
                t2 = clock();
                cout << "矩阵快速幂:   F(" << n << ")=" << r4
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
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
