#include <iostream>
#include <string>
#include <vector>

std::string preprocess(const std::string& s) {
    std::string result = "#";
    for (char c : s) {
        result += c;
        result += '#';
    }
    return result;
}

std::vector<int> manacher(const std::string& s) {
    std::string t = preprocess(s);
    int n = t.length();
    std::vector<int> p(n, 0);

    int center = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (i < right) {
            int mirror = 2 * center - i;
            p[i] = std::min(right - i, p[mirror]);
        }

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }

    return p;
}

struct PalindromeResult {
    int startIndex;
    int maxLength;
    std::string palindrome;
};

PalindromeResult longestPalindrome(const std::string& s) {
    if (s.empty()) return {0, 0, ""};

    std::vector<int> p = manacher(s);
    std::string t = preprocess(s);

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    std::string palindrome = s.substr(start, maxLen);

    return {start, maxLen, palindrome};
}

void printRadiusArray(const std::string& s) {
    std::string t = preprocess(s);
    std::vector<int> p = manacher(s);

    std::cout << "预处理字符串: " << t << std::endl;
    std::cout << "半径数组 p:   [";
    for (size_t i = 0; i < p.size(); i++) {
        std::cout << p[i];
        if (i < p.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    int choice;
    std::string s;

    do {
        std::cout << "\n===== Manacher算法(最长回文子串) =====" << std::endl;
        std::cout << "1. 查找最长回文子串" << std::endl;
        std::cout << "2. 显示半径数组" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入字符串: ";
            std::cin >> s;
            auto result = longestPalindrome(s);
            std::cout << "最长回文子串: " << result.palindrome << std::endl;
            std::cout << "起始位置: " << result.startIndex << " (0-indexed)" << std::endl;
            std::cout << "长度: " << result.maxLength << std::endl;
            break;
        }
        case 2: {
            std::cout << "请输入字符串: ";
            std::cin >> s;
            printRadiusArray(s);
            break;
        }
        case 0:
            std::cout << "退出Manacher算法" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
