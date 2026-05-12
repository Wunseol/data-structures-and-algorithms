#include <iostream>
#include <string>
#include <vector>
#include <cstring>

const int ALPHABET_SIZE = 256;

std::vector<int> buildBadCharTable(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> badChar(ALPHABET_SIZE, -1);

    for (int i = 0; i < m; i++) {
        badChar[(unsigned char)pattern[i]] = i;
    }

    return badChar;
}

std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n) return positions;

    std::vector<int> badChar = buildBadCharTable(pattern);

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            positions.push_back(s);
            int shift = (s + m < n) ? m - badChar[(unsigned char)text[s + m]] : 1;
            s += (shift > 0) ? shift : 1;
        } else {
            int shift = j - badChar[(unsigned char)text[s + j]];
            s += (shift > 0) ? shift : 1;
        }
    }

    return positions;
}

int main() {
    int choice;
    std::string text, pattern;

    do {
        std::cout << "\n===== Boyer-Moore算法(简化版) =====" << std::endl;
        std::cout << "1. 构建坏字符表" << std::endl;
        std::cout << "2. 搜索模式串" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto badChar = buildBadCharTable(pattern);
            std::cout << "坏字符表(仅显示模式串中出现的字符):" << std::endl;
            bool used[ALPHABET_SIZE] = {};
            for (char c : pattern) {
                int idx = (unsigned char)c;
                if (!used[idx]) {
                    used[idx] = true;
                    if (c >= 32 && c <= 126)
                        std::cout << "  '" << c << "' -> " << badChar[idx] << std::endl;
                    else
                        std::cout << "  (0x" << std::hex << idx << std::dec << ") -> " << badChar[idx] << std::endl;
                }
            }
            break;
        }
        case 2: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto positions = boyerMooreSearch(text, pattern);
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
            std::cout << "退出Boyer-Moore算法" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
