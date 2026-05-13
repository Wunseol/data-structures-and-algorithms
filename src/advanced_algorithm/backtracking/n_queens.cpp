#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NQueens {
    int n;
    vector<int> queens;
    vector<vector<string>> solutions;

    bool is_safe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col) return false;
            if (abs(queens[i] - col) == abs(i - row)) return false;
        }
        return true;
    }

    void backtrack(int row) {
        if (row == n) {
            save_solution();
            return;
        }
        for (int col = 0; col < n; col++) {
            if (is_safe(row, col)) {
                queens[row] = col;
                backtrack(row + 1);
                queens[row] = -1;
            }
        }
    }

    void save_solution() {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            board[i][queens[i]] = 'Q';
        solutions.push_back(board);
    }

public:
    NQueens(int size) : n(size), queens(size, -1) {}

    int solve() {
        solutions.clear();
        queens.assign(n, -1);
        backtrack(0);
        return solutions.size();
    }

    void print_solutions(int max_show = 10) const {
        int show = min((int)solutions.size(), max_show);
        for (int k = 0; k < show; k++) {
            cout << "解 " << k + 1 << ":" << endl;
            for (auto& row : solutions[k])
                cout << "  " << row << endl;
            cout << endl;
        }
        if ((int)solutions.size() > max_show)
            cout << "... 还有 " << solutions.size() - max_show << " 个解未显示" << endl;
    }

    void print_positions(int max_show = 10) const {
        int show = min((int)solutions.size(), max_show);
        for (int k = 0; k < show; k++) {
            cout << "解 " << k + 1 << ": [";
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << ", ";
                cout << solutions[k][i].find('Q');
            }
            cout << "]" << endl;
        }
        if ((int)solutions.size() > max_show)
            cout << "... 还有 " << solutions.size() - max_show << " 个解未显示" << endl;
    }
};

class NQueensBitmask {
    int n;
    int count;

    void backtrack(int row, int cols, int diag1, int diag2) {
        if (row == n) {
            count++;
            return;
        }
        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
        while (available) {
            int pos = available & (-available);
            available -= pos;
            backtrack(row + 1, cols | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
        }
    }

public:
    NQueensBitmask(int size) : n(size), count(0) {}

    int solve() {
        count = 0;
        backtrack(0, 0, 0, 0);
        return count;
    }
};

void menu() {
    cout << "\n========== N皇后问题 ==========" << endl;
    cout << "1. 基本回溯 (打印棋盘)" << endl;
    cout << "2. 基本回溯 (打印列位置)" << endl;
    cout << "3. 位运算加速回溯 (仅计数)" << endl;
    cout << "4. 性能对比" << endl;
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
                cout << "输入N (建议N<=12): ";
                cin >> n;
                NQueens solver(n);
                int cnt = solver.solve();
                cout << "共 " << cnt << " 个解" << endl;
                solver.print_solutions();
                break;
            }
            case 2: {
                int n;
                cout << "输入N: ";
                cin >> n;
                NQueens solver(n);
                int cnt = solver.solve();
                cout << "共 " << cnt << " 个解" << endl;
                solver.print_positions();
                break;
            }
            case 3: {
                int n;
                cout << "输入N: ";
                cin >> n;
                NQueensBitmask solver(n);
                int cnt = solver.solve();
                cout << "共 " << cnt << " 个解" << endl;
                break;
            }
            case 4: {
                int n;
                cout << "输入N: ";
                cin >> n;

                auto t1 = clock();
                NQueens solver1(n);
                int cnt1 = solver1.solve();
                auto t2 = clock();
                cout << "基本回溯:   " << cnt1 << " 个解, 耗时: "
                     << double(t2 - t1) / CLOCKS_PER_SEC * 1000 << " ms" << endl;

                t1 = clock();
                NQueensBitmask solver2(n);
                int cnt2 = solver2.solve();
                t2 = clock();
                cout << "位运算加速: " << cnt2 << " 个解, 耗时: "
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
