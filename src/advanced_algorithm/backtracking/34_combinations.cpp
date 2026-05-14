#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Combinations {
    vector<vector<int>> results;
    vector<int> current;

    void backtrack(int n, int k, int start) {
        if ((int)current.size() == k) {
            results.push_back(current);
            return;
        }
        for (int i = start; i <= n - (k - (int)current.size()) + 1; i++) {
            current.push_back(i);
            backtrack(n, k, i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> solve(int n, int k) {
        results.clear();
        current.clear();
        backtrack(n, k, 1);
        return results;
    }
};

class CombinationsWithRepetition {
    vector<vector<int>> results;
    vector<int> current;

    void backtrack(int n, int k, int start) {
        if ((int)current.size() == k) {
            results.push_back(current);
            return;
        }
        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(n, k, i);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> solve(int n, int k) {
        results.clear();
        current.clear();
        backtrack(n, k, 1);
        return results;
    }
};

class CombinationsFromArray {
    vector<vector<int>> results;
    vector<int> current;

    void backtrack(const vector<int>& arr, int k, int start) {
        if ((int)current.size() == k) {
            results.push_back(current);
            return;
        }
        for (int i = start; i < (int)arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1]) continue;
            current.push_back(arr[i]);
            backtrack(arr, k, i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> solve(vector<int> arr, int k) {
        results.clear();
        current.clear();
        sort(arr.begin(), arr.end());
        backtrack(arr, k, 0);
        return results;
    }
};

void print_combinations(const vector<vector<int>>& combs, int max_show = 30) {
    int show = min((int)combs.size(), max_show);
    for (int i = 0; i < show; i++) {
        cout << "  {";
        for (int j = 0; j < (int)combs[i].size(); j++) {
            if (j > 0) cout << ", ";
            cout << combs[i][j];
        }
        cout << "}" << endl;
    }
    if ((int)combs.size() > max_show)
        cout << "... 还有 " << combs.size() - max_show << " 个组合未显示" << endl;
}

void menu() {
    cout << "\n========== 组合 ==========" << endl;
    cout << "1. C(n,k) 从1~n中选k个" << endl;
    cout << "2. 可重复组合" << endl;
    cout << "3. 从数组中选k个 (含去重)" << endl;
    cout << "0. 退出" << endl;
    cout << "==========================" << endl;
    cout << "请选择: ";
}

int main() {
    int choice;
    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1: {
                int n, k;
                cout << "输入n: ";
                cin >> n;
                cout << "输入k: ";
                cin >> k;
                Combinations solver;
                auto combs = solver.solve(n, k);
                cout << "C(" << n << "," << k << ") = " << combs.size() << endl;
                print_combinations(combs);
                break;
            }
            case 2: {
                int n, k;
                cout << "输入n: ";
                cin >> n;
                cout << "输入k (可重复选取): ";
                cin >> k;
                CombinationsWithRepetition solver;
                auto combs = solver.solve(n, k);
                cout << "可重复组合数: " << combs.size() << endl;
                print_combinations(combs);
                break;
            }
            case 3: {
                int n, k;
                cout << "输入数组长度: ";
                cin >> n;
                vector<int> arr(n);
                cout << "输入数组元素 (可含重复): ";
                for (int i = 0; i < n; i++) cin >> arr[i];
                cout << "输入k: ";
                cin >> k;
                CombinationsFromArray solver;
                auto combs = solver.solve(arr, k);
                cout << "组合数: " << combs.size() << endl;
                print_combinations(combs);
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
