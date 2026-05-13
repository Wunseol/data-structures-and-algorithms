#include <iostream>
#include <string>
#include <vector>

const long long BASE = 256;
const long long MOD = 1000000007;

std::vector<int> rabinKarpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m > n || m == 0) return positions;

    long long h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * BASE) % MOD;
    }

    long long patternHash = 0;
    long long textHash = 0;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * BASE + pattern[i]) % MOD;
        textHash = (textHash * BASE + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                positions.push_back(i);
            }
        }

        if (i < n - m) {
            textHash = (textHash - text[i] * h % MOD + MOD) % MOD;
            textHash = (textHash * BASE + text[i + m]) % MOD;
        }
    }

    return positions;
}

int main() {
    int choice;
    std::string text, pattern;

    do {
        std::cout << "\n===== Rabin-Karp算法 =====" << std::endl;
        std::cout << "1. 搜索模式串" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto positions = rabinKarpSearch(text, pattern);
            if (positions.empty()) {
                std::cout << "未找到匹配" << std::endl;
            } else {
                std::cout << "匹配位置(0-indexed): ";
                for (size_t i = 0; i < positions.size(); i++) {
                    std::cout << positions[i];
                    if (i < positions.size() - 1) std::cout << ", ";
                }
                std::cout << std::endl;
                std::cout << "共找到 " << positions.size() << " 处匹配" << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "退出Rabin-Karp算法" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
