#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
    int id;
};

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double closest_brute(const vector<Point>& pts, int l, int r, Point& p1, Point& p2) {
    double min_d = DBL_MAX;
    for (int i = l; i <= r; i++)
        for (int j = i + 1; j <= r; j++) {
            double d = dist(pts[i], pts[j]);
            if (d < min_d) {
                min_d = d;
                p1 = pts[i];
                p2 = pts[j];
            }
        }
    return min_d;
}

double closest_dc(vector<Point>& px, int l, int r, Point& p1, Point& p2) {
    if (r - l + 1 <= 3)
        return closest_brute(px, l, r, p1, p2);

    int m = l + (r - l) / 2;
    double mid_x = px[m].x;

    Point lp1, lp2, rp1, rp2;
    double dl = closest_dc(px, l, m, lp1, lp2);
    double dr = closest_dc(px, m + 1, r, rp1, rp2);

    double d;
    if (dl < dr) {
        d = dl; p1 = lp1; p2 = lp2;
    } else {
        d = dr; p1 = rp1; p2 = rp2;
    }

    vector<Point> strip;
    for (int i = l; i <= r; i++)
        if (abs(px[i].x - mid_x) < d)
            strip.push_back(px[i]);

    for (int i = 0; i < (int)strip.size(); i++)
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            double dd = dist(strip[i], strip[j]);
            if (dd < d) {
                d = dd;
                p1 = strip[i];
                p2 = strip[j];
            }
        }

    return d;
}

double closest_pair_dc(vector<Point> points, Point& p1, Point& p2) {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    return closest_dc(points, 0, points.size() - 1, p1, p2);
}

double closest_brute_full(const vector<Point>& points, Point& p1, Point& p2) {
    double min_d = DBL_MAX;
    int n = points.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            double d = dist(points[i], points[j]);
            if (d < min_d) {
                min_d = d;
                p1 = points[i];
                p2 = points[j];
            }
        }
    return min_d;
}

void print_point(const Point& p) {
    cout << "(" << fixed << setprecision(2) << p.x << ", " << p.y << ")";
}

void menu() {
    cout << "\n========== 最近点对 ==========" << endl;
    cout << "1. 分治法 O(n log n)" << endl;
    cout << "2. 暴力法 O(n^2)" << endl;
    cout << "3. 性能对比" << endl;
    cout << "4. 随机生成测试" << endl;
    cout << "0. 退出" << endl;
    cout << "===============================" << endl;
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
                cout << "输入点数: ";
                cin >> n;
                vector<Point> points(n);
                cout << "输入每个点的坐标 (x y):" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> points[i].x >> points[i].y;
                    points[i].id = i;
                }
                Point p1, p2;
                double d = closest_pair_dc(points, p1, p2);
                cout << "最近距离: " << fixed << setprecision(6) << d << endl;
                cout << "点对: ";
                print_point(p1);
                cout << " 和 ";
                print_point(p2);
                cout << endl;
                break;
            }
            case 2: {
                int n;
                cout << "输入点数: ";
                cin >> n;
                vector<Point> points(n);
                cout << "输入每个点的坐标 (x y):" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> points[i].x >> points[i].y;
                    points[i].id = i;
                }
                Point p1, p2;
                double d = closest_brute_full(points, p1, p2);
                cout << "最近距离: " << fixed << setprecision(6) << d << endl;
                cout << "点对: ";
                print_point(p1);
                cout << " 和 ";
                print_point(p2);
                cout << endl;
                break;
            }
            case 3: {
                int n;
                cout << "输入点数: ";
                cin >> n;
                vector<Point> points(n);
                cout << "输入每个点的坐标 (x y):" << endl;
                for (int i = 0; i < n; i++) {
                    cin >> points[i].x >> points[i].y;
                    points[i].id = i;
                }

                Point p1a, p2a, p1b, p2b;
                auto t1 = clock();
                double d1 = closest_pair_dc(points, p1a, p2a);
                auto t2 = clock();
                double d2 = closest_brute_full(points, p1b, p2b);
                auto t3 = clock();

                cout << "分治法 O(n log n): 距离=" << fixed << setprecision(6) << d1
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "暴力法 O(n^2):     距离=" << d2
                     << "  耗时: " << double(t3 - t2) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                break;
            }
            case 4: {
                int n;
                double range;
                cout << "输入随机点数: ";
                cin >> n;
                cout << "输入坐标范围 (0~range): ";
                cin >> range;
                vector<Point> points(n);
                for (int i = 0; i < n; i++) {
                    points[i].x = (double)rand() / RAND_MAX * range;
                    points[i].y = (double)rand() / RAND_MAX * range;
                    points[i].id = i;
                }

                Point p1a, p2a, p1b, p2b;
                auto t1 = clock();
                double d1 = closest_pair_dc(points, p1a, p2a);
                auto t2 = clock();
                double d2 = closest_brute_full(points, p1b, p2b);
                auto t3 = clock();

                cout << "\n分治法: 距离=" << fixed << setprecision(6) << d1
                     << "  耗时: " << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "暴力法: 距离=" << d2
                     << "  耗时: " << double(t3 - t2) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
                cout << "最近点对: ";
                print_point(p1a);
                cout << " 和 ";
                print_point(p2a);
                cout << endl;
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
