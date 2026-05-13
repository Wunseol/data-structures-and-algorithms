#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end, id;
};

vector<Activity> activity_selection(vector<Activity>& acts) {
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.end < b.end;
    });

    vector<Activity> selected;
    selected.push_back(acts[0]);
    int last_end = acts[0].end;

    for (int i = 1; i < (int)acts.size(); i++) {
        if (acts[i].start >= last_end) {
            selected.push_back(acts[i]);
            last_end = acts[i].end;
        }
    }
    return selected;
}

vector<Activity> activity_selection_by_start(vector<Activity>& acts) {
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        if (a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    });

    vector<Activity> selected;
    int last_end = 0;
    for (auto& act : acts) {
        if (act.start >= last_end) {
            selected.push_back(act);
            last_end = act.end;
        }
    }
    return selected;
}

void print_activities(const vector<Activity>& acts, const string& title) {
    cout << title << " (共" << acts.size() << "个活动):" << endl;
    for (auto& a : acts)
        cout << "  活动A" << a.id << ": [" << a.start << ", " << a.end << ")" << endl;
}

void print_timeline(const vector<Activity>& acts, int max_time) {
    cout << "\n时间线可视化:" << endl;
    for (auto& a : acts) {
        cout << "A" << a.id << " ";
        for (int t = 0; t <= max_time; t++) {
            if (t >= a.start && t < a.end)
                cout << "#";
            else
                cout << "-";
        }
        cout << " [" << a.start << "," << a.end << ")" << endl;
    }
}

void menu() {
    cout << "\n========== 活动选择 ==========" << endl;
    cout << "1. 贪心 (按结束时间排序)" << endl;
    cout << "2. 对比: 按开始时间排序" << endl;
    cout << "3. 带时间线可视化" << endl;
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
                int n;
                cout << "输入活动数量: ";
                cin >> n;
                vector<Activity> acts(n);
                cout << "输入每个活动的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> acts[i].start >> acts[i].end;
                    acts[i].id = i + 1;
                }
                auto selected = activity_selection(acts);
                print_activities(selected, "最优选择");
                break;
            }
            case 2: {
                int n;
                cout << "输入活动数量: ";
                cin >> n;
                vector<Activity> acts1(n), acts2(n);
                cout << "输入每个活动的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++) {
                    int s, e;
                    cin >> s >> e;
                    acts1[i] = {s, e, i + 1};
                    acts2[i] = {s, e, i + 1};
                }
                auto r1 = activity_selection(acts1);
                auto r2 = activity_selection_by_start(acts2);
                print_activities(r1, "按结束时间排序贪心 (最优)");
                print_activities(r2, "按开始时间排序贪心 (不一定最优)");
                break;
            }
            case 3: {
                int n;
                cout << "输入活动数量: ";
                cin >> n;
                vector<Activity> acts(n);
                int max_time = 0;
                cout << "输入每个活动的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> acts[i].start >> acts[i].end;
                    acts[i].id = i + 1;
                    max_time = max(max_time, acts[i].end);
                }
                auto selected = activity_selection(acts);
                print_activities(selected, "最优选择");
                print_timeline(selected, max_time);
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
