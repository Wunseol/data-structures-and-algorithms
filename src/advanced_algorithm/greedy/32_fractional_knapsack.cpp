#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    double weight, value;
    double ratio;
};

double fractional_knapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double total_value = 0.0;
    double remaining = W;

    cout << "选择过程:" << endl;
    for (auto& item : items) {
        if (remaining <= 0) break;
        double take = min(item.weight, remaining);
        double take_value = take * item.ratio;
        remaining -= take;
        total_value += take_value;

        cout << "  物品" << item.id << ": 取" << fixed << setprecision(1)
             << take << "/" << item.weight
             << " (单价=" << setprecision(2) << item.ratio
             << ", 价值=" << setprecision(2) << take_value << ")" << endl;
    }
    return total_value;
}

double fractional_knapsack_01(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double total_value = 0.0;
    double remaining = W;

    cout << "0-1背包贪心 (非最优,仅作对比):" << endl;
    for (auto& item : items) {
        if (remaining <= 0) break;
        if (item.weight <= remaining) {
            remaining -= item.weight;
            total_value += item.value;
            cout << "  物品" << item.id << ": 全部取入" << endl;
        }
    }
    return total_value;
}

void menu() {
    cout << "\n========== 分数背包 ==========" << endl;
    cout << "1. 分数背包 (贪心, 可分割)" << endl;
    cout << "2. 对比: 0-1背包贪心 (不可分割)" << endl;
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
                int n, W;
                cout << "输入物品数量: ";
                cin >> n;
                cout << "输入背包容量: ";
                cin >> W;
                vector<Item> items(n);
                cout << "输入每个物品的重量和价值:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> items[i].weight >> items[i].value;
                    items[i].id = i + 1;
                    items[i].ratio = items[i].value / items[i].weight;
                }
                cout << "\n物品单价:" << endl;
                for (auto& item : items)
                    cout << "  物品" << item.id << ": 重量=" << item.weight
                         << ", 价值=" << item.value
                         << ", 单价=" << fixed << setprecision(2) << item.ratio << endl;
                cout << endl;
                double max_val = fractional_knapsack(W, items);
                cout << "\n最大价值: " << fixed << setprecision(2) << max_val << endl;
                break;
            }
            case 2: {
                int n, W;
                cout << "输入物品数量: ";
                cin >> n;
                cout << "输入背包容量: ";
                cin >> W;
                vector<Item> items1(n), items2(n);
                cout << "输入每个物品的重量和价值:" << endl;
                for (int i = 0; i < n; i++) {
                    double w, v;
                    cin >> w >> v;
                    items1[i] = {i + 1, w, v, v / w};
                    items2[i] = {i + 1, w, v, v / w};
                }
                cout << endl;
                double val_frac = fractional_knapsack(W, items1);
                cout << "\n分数背包最大价值: " << fixed << setprecision(2) << val_frac << endl;
                cout << endl;
                double val_01 = fractional_knapsack_01(W, items2);
                cout << "\n0-1背包贪心价值: " << fixed << setprecision(2) << val_01 << endl;
                cout << "\n结论: 分数背包贪心可获最优解, 0-1背包贪心不一定最优" << endl;
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
