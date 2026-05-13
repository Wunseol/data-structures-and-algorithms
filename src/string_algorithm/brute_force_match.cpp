#include <iostream>
#include <string>
#include <vector>

struct MatchResult {
    int pos;
    int comparisons;
};

std::vector<MatchResult> bruteForceMatch(const std::string& text, const std::string& pattern) {
    std::vector<MatchResult> results;
    int n = text.length();
    int m = pattern.length();
    int comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                break;
            }
            j++;
        }
        if (j == m) {
            results.push_back({i, comparisons});
        }
    }

    if (results.empty()) {
        results.push_back({-1, comparisons});
    }
    return results;
}

int main() {
    std::string text, pattern;

    std::cout << "===== 暴力字符串匹配 =====" << std::endl;
    std::cout << "请输入主串: ";
    std::cin >> text;
    std::cout << "请输入模式串: ";
    std::cin >> pattern;

    auto results = bruteForceMatch(text, pattern);

    std::cout << "\n--- 匹配结果 ---" << std::endl;
    if (results[0].pos == -1) {
        std::cout << "未找到匹配" << std::endl;
    } else {
        for (const auto& r : results) {
            std::cout << "匹配位置: " << r.pos << " (0-indexed)" << std::endl;
        }
    }
    std::cout << "总比较次数: " << results[0].comparisons << std::endl;

    return 0;
}
