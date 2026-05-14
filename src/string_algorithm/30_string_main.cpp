#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

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
            if (text[i + j] != pattern[j]) break;
            j++;
        }
        if (j == m) results.push_back({i, comparisons});
    }

    if (results.empty()) results.push_back({-1, comparisons});
    return results;
}

std::vector<int> computeNext(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> next(m, 0);
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++; j++;
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
            i++; j++;
            nextval[i] = (pattern[i] != pattern[j]) ? j : nextval[j];
        } else {
            j = nextval[j];
        }
    }
    return nextval;
}

int kmpSearch(const std::string& text, const std::string& pattern) {
    auto next = computeNextval(pattern);
    int n = text.length(), m = pattern.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) { i++; j++; }
        else j = next[j];
    }
    return (j == m) ? i - m : -1;
}

const long long RK_BASE = 256;
const long long RK_MOD = 1000000007;

std::vector<int> rabinKarpSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;
    int n = text.length(), m = pattern.length();
    if (m > n || m == 0) return positions;

    long long h = 1;
    for (int i = 0; i < m - 1; i++) h = (h * RK_BASE) % RK_MOD;

    long long ph = 0, th = 0;
    for (int i = 0; i < m; i++) {
        ph = (ph * RK_BASE + pattern[i]) % RK_MOD;
        th = (th * RK_BASE + text[i]) % RK_MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (ph == th) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) { match = false; break; }
            }
            if (match) positions.push_back(i);
        }
        if (i < n - m) {
            th = (th - text[i] * h % RK_MOD + RK_MOD) % RK_MOD;
            th = (th * RK_BASE + text[i + m]) % RK_MOD;
        }
    }
    return positions;
}

const int BM_ALPHA = 256;

std::vector<int> buildBadCharTable(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> badChar(BM_ALPHA, -1);
    for (int i = 0; i < m; i++) badChar[(unsigned char)pattern[i]] = i;
    return badChar;
}

std::vector<int> boyerMooreSearch(const std::string& text, const std::string& pattern) {
    std::vector<int> positions;
    int n = text.length(), m = pattern.length();
    if (m == 0 || m > n) return positions;

    auto badChar = buildBadCharTable(pattern);
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) j--;
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

struct LCSResult {
    int length;
    std::string lcs;
};

LCSResult longestCommonSubsequence(const std::string& s1, const std::string& s2) {
    int m = s1.length(), n = s2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = (s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);

    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) { lcs = s1[i - 1] + lcs; i--; j--; }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    return {dp[m][n], lcs};
}

std::string manacherPreprocess(const std::string& s) {
    std::string r = "#";
    for (char c : s) { r += c; r += '#'; }
    return r;
}

struct PalindromeResult {
    int startIndex;
    int maxLength;
    std::string palindrome;
};

PalindromeResult longestPalindrome(const std::string& s) {
    if (s.empty()) return {0, 0, ""};
    std::string t = manacherPreprocess(s);
    int n = t.length();
    std::vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (i < right) p[i] = std::min(right - i, p[2 * center - i]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
    }
    int maxLen = 0, ci = 0;
    for (int i = 0; i < n; i++) if (p[i] > maxLen) { maxLen = p[i]; ci = i; }
    int start = (ci - maxLen) / 2;
    return {start, maxLen, s.substr(start, maxLen)};
}

void printPositions(const std::vector<int>& positions) {
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
}

int main() {
    int choice;
    std::string text, pattern, s1, s2;

    do {
        std::cout << "\n========== 字符串算法 ==========" << std::endl;
        std::cout << "1. 暴力匹配" << std::endl;
        std::cout << "2. KMP匹配" << std::endl;
        std::cout << "3. Rabin-Karp匹配" << std::endl;
        std::cout << "4. Boyer-Moore匹配" << std::endl;
        std::cout << "5. 最长公共子序列(LCS)" << std::endl;
        std::cout << "6. 最长回文子串(Manacher)" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto results = bruteForceMatch(text, pattern);
            if (results[0].pos == -1) std::cout << "未找到匹配" << std::endl;
            else for (const auto& r : results) std::cout << "匹配位置: " << r.pos << std::endl;
            std::cout << "总比较次数: " << results[0].comparisons << std::endl;
            break;
        }
        case 2: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto next = computeNext(pattern);
            auto nextval = computeNextval(pattern);
            std::cout << "next数组:   [";
            for (size_t i = 0; i < next.size(); i++) { std::cout << next[i]; if (i < next.size() - 1) std::cout << ", "; }
            std::cout << "]" << std::endl;
            std::cout << "nextval数组: [";
            for (size_t i = 0; i < nextval.size(); i++) { std::cout << nextval[i]; if (i < nextval.size() - 1) std::cout << ", "; }
            std::cout << "]" << std::endl;
            int pos = kmpSearch(text, pattern);
            if (pos != -1) std::cout << "匹配位置: " << pos << " (0-indexed)" << std::endl;
            else std::cout << "未找到匹配" << std::endl;
            break;
        }
        case 3: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto positions = rabinKarpSearch(text, pattern);
            printPositions(positions);
            break;
        }
        case 4: {
            std::cout << "请输入主串: ";
            std::cin >> text;
            std::cout << "请输入模式串: ";
            std::cin >> pattern;
            auto positions = boyerMooreSearch(text, pattern);
            printPositions(positions);
            break;
        }
        case 5: {
            std::cout << "请输入字符串1: ";
            std::cin >> s1;
            std::cout << "请输入字符串2: ";
            std::cin >> s2;
            auto result = longestCommonSubsequence(s1, s2);
            std::cout << "LCS长度: " << result.length << std::endl;
            std::cout << "LCS内容: " << result.lcs << std::endl;
            break;
        }
        case 6: {
            std::cout << "请输入字符串: ";
            std::cin >> text;
            auto result = longestPalindrome(text);
            std::cout << "最长回文子串: " << result.palindrome << std::endl;
            std::cout << "起始位置: " << result.startIndex << " (0-indexed)" << std::endl;
            std::cout << "长度: " << result.maxLength << std::endl;
            break;
        }
        case 0:
            std::cout << "退出字符串算法" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
