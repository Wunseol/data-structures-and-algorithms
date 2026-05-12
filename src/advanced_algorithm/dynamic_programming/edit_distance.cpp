#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance_2d(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    return dp[m][n];
}

int edit_distance_optimized(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    if (m < n) return edit_distance_optimized(s2, s1);

    vector<int> prev(n + 1), curr(n + 1);
    for (int j = 0; j <= n; j++) prev[j] = j;

    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
        }
        swap(prev, curr);
    }
    return prev[n];
}

void edit_distance_with_ops(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    vector<vector<int>> op(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) { dp[i][0] = i; op[i][0] = 1; }
    for (int j = 0; j <= n; j++) { dp[0][j] = j; op[0][j] = 2; }
    op[0][0] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                op[i][j] = 0;
            } else {
                int del = dp[i - 1][j];
                int ins = dp[i][j - 1];
                int rep = dp[i - 1][j - 1];
                if (del <= ins && del <= rep) {
                    dp[i][j] = del + 1; op[i][j] = 1;
                } else if (ins <= del && ins <= rep) {
                    dp[i][j] = ins + 1; op[i][j] = 2;
                } else {
                    dp[i][j] = rep + 1; op[i][j] = 3;
                }
            }
        }

    cout << "±à¼­¾àÀë: " << dp[m][n] << endl;

    vector<string> ops;
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (op[i][j] == 0) {
            ops.push_back("±£³Ö '" + string(1, s1[i - 1]) + "'");
            i--; j--;
        } else if (op[i][j] == 1) {
            ops.push_back("É¾³ý '" + string(1, s1[i - 1]) + "' (Î»ÖÃ" + to_string(i - 1) + ")");
            i--;
        } else if (op[i][j] == 2) {
            ops.push_back("²åÈë '" + string(1, s2[j - 1]) + "' (Î»ÖÃ" + to_string(j - 1) + ")");
            j--;
        } else {
            ops.push_back("Ìæ»» '" + string(1, s1[i - 1]) + "' -> '" + string(1, s2[j - 1]) + "'");
            i--; j--;
        }
    }
    reverse(ops.begin(), ops.end());
    cout << "²Ù×÷²½Öè:" << endl;
    for (auto& s : ops)
        cout << "  " << s << endl;
}

void print_dp_table(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }

    cout << "\nDP±í:" << endl;
    cout << "      ";
    for (int j = 0; j <= n; j++)
        cout << (j == 0 ? '#' : s2[j - 1]) << "\t";
    cout << endl;
    for (int i = 0; i <= m; i++) {
        cout << (i == 0 ? '#' : s1[i - 1]) << "  ";
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }
}

void menu() {
    cout << "\n========== ±à¼­¾àÀë ==========" << endl;
    cout << "1. 2D DP" << endl;
    cout << "2. ¿Õ¼äÓÅ»¯ DP O(min(m,n))" << endl;
    cout << "3. ´òÓ¡²Ù×÷²½Öè" << endl;
    cout << "4. ´òÓ¡DP±í" << endl;
    cout << "0. ÍË³ö" << endl;
    cout << "===============================" << endl;
    cout << "ÇëÑ¡Ôñ: ";
}

int main() {
    int choice;
    do {
        menu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                string s1, s2;
                cout << "ÊäÈë×Ö·û´®1: ";
                getline(cin, s1);
                cout << "ÊäÈë×Ö·û´®2: ";
                getline(cin, s2);
                cout << "±à¼­¾àÀë: " << edit_distance_2d(s1, s2) << endl;
                break;
            }
            case 2: {
                string s1, s2;
                cout << "ÊäÈë×Ö·û´®1: ";
                getline(cin, s1);
                cout << "ÊäÈë×Ö·û´®2: ";
                getline(cin, s2);
                cout << "±à¼­¾àÀë: " << edit_distance_optimized(s1, s2) << endl;
                break;
            }
            case 3: {
                string s1, s2;
                cout << "ÊäÈë×Ö·û´®1: ";
                getline(cin, s1);
                cout << "ÊäÈë×Ö·û´®2: ";
                getline(cin, s2);
                edit_distance_with_ops(s1, s2);
                break;
            }
            case 4: {
                string s1, s2;
                cout << "ÊäÈë×Ö·û´®1: ";
                getline(cin, s1);
                cout << "ÊäÈë×Ö·û´®2: ";
                getline(cin, s2);
                print_dp_table(s1, s2);
                break;
            }
            case 0:
                cout << "ÔÙ¼û!" << endl;
                break;
            default:
                cout << "ÎÞÐ§Ñ¡Ôñ!" << endl;
        }
    } while (choice != 0);
    return 0;
}
