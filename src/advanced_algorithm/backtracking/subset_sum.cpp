#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SubsetSum {
    vector<vector<int>> results;
    vector<int> current;

    void backtrack(const vector<int>& nums, int target, int start, int curr_sum) {
        if (curr_sum == target) {
            results.push_back(current);
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            if (curr_sum + nums[i] > target) break;
            if (i > start && nums[i] == nums[i - 1]) continue;
            current.push_back(nums[i]);
            backtrack(nums, target, i + 1, curr_sum + nums[i]);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> solve(vector<int> nums, int target) {
        results.clear();
        current.clear();
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, 0);
        return results;
    }
};

class SubsetSumAll {
    vector<vector<int>> results;
    vector<int> current;

    void backtrack(const vector<int>& nums, int target, int start, int curr_sum) {
        if (curr_sum == target) {
            results.push_back(current);
        }
        if (start >= (int)nums.size()) return;
        for (int i = start; i < (int)nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, target, i + 1, curr_sum + nums[i]);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> solve(const vector<int>& nums, int target) {
        results.clear();
        current.clear();
        backtrack(nums, target, 0, 0);
        return results;
    }
};

class SubsetSumCount {
    int count;

    void backtrack(const vector<int>& nums, int target, int start, int curr_sum) {
        if (curr_sum == target) {
            count++;
            return;
        }
        for (int i = start; i < (int)nums.size(); i++) {
            if (curr_sum + nums[i] > target) break;
            backtrack(nums, target, i + 1, curr_sum + nums[i]);
        }
    }

public:
    int solve(vector<int> nums, int target) {
        count = 0;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, 0);
        return count;
    }
};

void print_subsets(const vector<vector<int>>& subsets, int max_show = 30) {
    int show = min((int)subsets.size(), max_show);
    for (int i = 0; i < show; i++) {
        cout << "  {";
        for (int j = 0; j < (int)subsets[i].size(); j++) {
            if (j > 0) cout << ", ";
            cout << subsets[i][j];
        }
        cout << "}" << endl;
    }
    if ((int)subsets.size() > max_show)
        cout << "... 还有 " << subsets.size() - max_show << " 个子集未显示" << endl;
}

void menu() {
    cout << "\n========== 子集和 ==========" << endl;
    cout << "1. 找所有子集 (排序+剪枝+去重)" << endl;
    cout << "2. 找所有子集 (无剪枝, 含重复)" << endl;
    cout << "3. 仅计数" << endl;
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
                int n, target;
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "输入目标和: ";
                cin >> target;
                SubsetSum solver;
                auto subsets = solver.solve(nums, target);
                cout << "子集数: " << subsets.size() << endl;
                print_subsets(subsets);
                break;
            }
            case 2: {
                int n, target;
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "输入目标和: ";
                cin >> target;
                SubsetSumAll solver;
                auto subsets = solver.solve(nums, target);
                cout << "子集数: " << subsets.size() << endl;
                print_subsets(subsets);
                break;
            }
            case 3: {
                int n, target;
                cout << "输入元素个数: ";
                cin >> n;
                vector<int> nums(n);
                cout << "输入元素: ";
                for (int i = 0; i < n; i++) cin >> nums[i];
                cout << "输入目标和: ";
                cin >> target;
                SubsetSumCount solver;
                cout << "子集数: " << solver.solve(nums, target) << endl;
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
