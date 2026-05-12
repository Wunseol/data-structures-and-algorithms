#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PermutationsSwap {
    vector<vector<int>> results;

    void backtrack(vector<int>& nums, int start) {
        if (start == (int)nums.size()) {
            results.push_back(nums);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }

public:
    vector<vector<int>> solve(vector<int> nums) {
        results.clear();
        backtrack(nums, 0);
        return results;
    }
};

class PermutationsUsed {
    vector<vector<int>> results;
    vector<int> current;
    vector<bool> used;

    void backtrack(const vector<int>& nums) {
        if ((int)current.size() == (int)nums.size()) {
            results.push_back(current);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums);
            current.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> solve(vector<int> nums) {
        results.clear();
        current.clear();
        used.assign(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return results;
    }
};

void print_permutations(const vector<vector<int>>& perms, int max_show = 20) {
    int show = min((int)perms.size(), max_show);
    for (int i = 0; i < show; i++) {
        cout << "  ";
        for (int j = 0; j < (int)perms[i].size(); j++) {
            if (j > 0) cout << " ";
            cout << perms[i][j];
        }
        cout << endl;
    }
    if ((int)perms.size() > max_show)
        cout << "... 还有 " << perms.size() - max_show << " 个排列未显示" << endl;
}

void menu() {
    cout << "\n========== 全排列 ==========" << endl;
    cout << "1. 交换法 (swap method)" << endl;
    cout << "2. used数组法 (含去重)" << endl;
    cout << "3. 性能对比" << endl;
    cout << "0. 退出" << endl;
    cout << "============================" << endl;
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
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                PermutationsSwap solver;
                auto perms = solver.solve(nums);
                cout << "排列数: " << perms.size() << endl;
                print_permutations(perms);
                break;
            }
            case 2: {
                int n;
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素 (可含重复): ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                PermutationsUsed solver;
                auto perms = solver.solve(nums);
                cout << "排列数: " << perms.size() << endl;
                print_permutations(perms);
                break;
            }
            case 3: {
                int n;
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];

                auto t1 = clock();
                PermutationsSwap s1;
                auto r1 = s1.solve(nums);
                auto t2 = clock();
                cout << "交换法: " << r1.size() << " 个排列, 耗时: "
                     << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

                t1 = clock();
                PermutationsUsed s2;
                auto r2 = s2.solve(nums);
                t2 = clock();
                cout << "used数组法: " << r2.size() << " 个排列, 耗时: "
                     << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
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
