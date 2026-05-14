#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct LCSResult {
    int length;
    std::string lcs;
};

LCSResult longestCommonSubsequence(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return {dp[m][n], lcs};
}

void printDPTable(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << "    ";
    for (int j = 0; j < n; j++) {
        std::cout << s2[j] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i <= m; i++) {
        if (i == 0)
            std::cout << "  ";
        else
            std::cout << s1[i - 1] << " ";
        for (int j = 0; j <= n; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int choice;
    std::string s1, s2;

    do {
        std::cout << "\n===== 最长公共子序列(LCS) =====" << std::endl;
        std::cout << "1. 计算LCS" << std::endl;
        std::cout << "2. 显示DP表" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入字符串1: ";
            std::cin >> s1;
            std::cout << "请输入字符串2: ";
            std::cin >> s2;
            auto result = longestCommonSubsequence(s1, s2);
            std::cout << "LCS长度: " << result.length << std::endl;
            std::cout << "LCS内容: " << result.lcs << std::endl;
            break;
        }
        case 2: {
            std::cout << "请输入字符串1: ";
            std::cin >> s1;
            std::cout << "请输入字符串2: ";
            std::cin >> s2;
            printDPTable(s1, s2);
            break;
        }
        case 0:
            std::cout << "退出LCS" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
