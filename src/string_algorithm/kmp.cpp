#include <iostream>
#include <string>
#include <vector>

std::vector<int> computeNext(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> next(m, 0);
    next[0] = -1;
    int i = 0, j = -1;

    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next;
}

std::vector<int> computeNextval(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> nextval(m, 0);
    nextval[0] = -1;
    int i = 0, j = -1;

    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            if (pattern[i] != pattern[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }
    return nextval;
}

int kmpSearch(const std::string& text, const std::string& pattern, const std::vector<int>& nextArr) {
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = nextArr[j];
        }
    }

    if (j == m) {
        return i - m;
    }
    return -1;
}

void printArray(const std::string& label, const std::vector<int>& arr) {
    std::cout << label << ": [";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    int choice;
    std::string text, pattern;

    do {
        std::cout << "\n===== KMP算法 =====" << std::endl;
        std::cout << "1. 计算next数组" << std::endl;
        std::cout << "2. 计算nextval数组" << std::endl;
        std::cout << "3. KMP搜索(使用next)" << std::endl;
        std::cout << "4. KMP搜索(使用nextval)" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto next = computeNext(pattern);
            printArray("next", next);
            break;
        }
        case 2: {
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto nextval = computeNextval(pattern);
            printArray("nextval", nextval);
            break;
        }
        case 3: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto next = computeNext(pattern);
            printArray("next", next);
            int pos = kmpSearch(text, pattern, next);
            if (pos != -1)
                std::cout << "匹配位置: " << pos << " (0-indexed)" << std::endl;
            else
                std::cout << "未找到匹配" << std::endl;
            break;
        }
        case 4: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto nextval = computeNextval(pattern);
            printArray("nextval", nextval);
            int pos = kmpSearch(text, pattern, nextval);
            if (pos != -1)
                std::cout << "匹配位置: " << pos << " (0-indexed)" << std::endl;
            else
                std::cout << "未找到匹配" << std::endl;
            break;
        }
        case 0:
            std::cout << "退出KMP算法" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
