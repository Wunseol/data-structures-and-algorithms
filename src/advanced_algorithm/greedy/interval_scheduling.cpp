#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int time;
    int type;
    int id;
};

int min_meeting_rooms(vector<pair<int, int>>& intervals) {
    vector<Event> events;
    for (int i = 0; i < (int)intervals.size(); i++) {
        events.push_back({intervals[i].first, 1, i});
        events.push_back({intervals[i].second, -1, i});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time != b.time) return a.time < b.time;
        return a.type < b.type;
    });

    int rooms = 0, max_rooms = 0;
    for (auto& e : events) {
        rooms += e.type;
        max_rooms = max(max_rooms, rooms);
    }
    return max_rooms;
}

void min_meeting_rooms_detail(vector<pair<int, int>>& intervals) {
    int n = intervals.size();
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        events.push_back({intervals[i].first, 1, i});
        events.push_back({intervals[i].second, -1, i});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time != b.time) return a.time < b.time;
        return a.type < b.type;
    });

    vector<int> room_assign(n, -1);
    vector<int> free_rooms;
    int next_room = 0;
    int max_rooms = 0;

    cout << "事件处理过程:" << endl;
    for (auto& e : events) {
        if (e.type == 1) {
            int r;
            if (!free_rooms.empty()) {
                r = free_rooms.back();
                free_rooms.pop_back();
            } else {
                r = next_room++;
            }
            room_assign[e.id] = r;
            max_rooms = max(max_rooms, next_room);
            cout << "  时间" << e.time << ": 会议" << e.id + 1
                 << " 开始 -> 分配房间" << r + 1 << endl;
        } else {
            int r = room_assign[e.id];
            free_rooms.push_back(r);
            cout << "  时间" << e.time << ": 会议" << e.id + 1
                 << " 结束 -> 释放房间" << r + 1 << endl;
        }
    }

    cout << "\n最少需要房间数: " << max_rooms << endl;
    cout << "分配方案:" << endl;
    for (int i = 0; i < n; i++)
        cout << "  会议" << i + 1 << " [" << intervals[i].first
             << "," << intervals[i].second << ") -> 房间" << room_assign[i] + 1 << endl;
}

void print_timeline(vector<pair<int, int>>& intervals) {
    int min_t = intervals[0].first, max_t = intervals[0].second;
    for (auto& iv : intervals) {
        min_t = min(min_t, iv.first);
        max_t = max(max_t, iv.second);
    }

    cout << "\n时间线:" << endl;
    for (int i = 0; i < (int)intervals.size(); i++) {
        cout << "M" << i + 1 << " ";
        for (int t = min_t; t <= max_t; t++) {
            if (t >= intervals[i].first && t < intervals[i].second)
                cout << "#";
            else
                cout << "-";
        }
        cout << " [" << intervals[i].first << "," << intervals[i].second << ")" << endl;
    }
}

void menu() {
    cout << "\n========== 区间调度 (会议室II) ==========" << endl;
    cout << "1. 扫描线算法求最少房间数" << endl;
    cout << "2. 详细过程 (含房间分配)" << endl;
    cout << "3. 带时间线可视化" << endl;
    cout << "0. 退出" << endl;
    cout << "=========================================" << endl;
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
                cout << "输入会议数量: ";
                cin >> n;
                vector<pair<int, int>> intervals(n);
                cout << "输入每个会议的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++)
                    cin >> intervals[i].first >> intervals[i].second;
                cout << "最少需要房间数: " << min_meeting_rooms(intervals) << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入会议数量: ";
                cin >> n;
                vector<pair<int, int>> intervals(n);
                cout << "输入每个会议的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++)
                    cin >> intervals[i].first >> intervals[i].second;
                min_meeting_rooms_detail(intervals);
                break;
            }
            case 3: {
                int n;
                cout << "输入会议数量: ";
                cin >> n;
                vector<pair<int, int>> intervals(n);
                cout << "输入每个会议的开始和结束时间:" << endl;
                for (int i = 0; i < n; i++)
                    cin >> intervals[i].first >> intervals[i].second;
                cout << "最少需要房间数: " << min_meeting_rooms(intervals) << endl;
                print_timeline(intervals);
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
