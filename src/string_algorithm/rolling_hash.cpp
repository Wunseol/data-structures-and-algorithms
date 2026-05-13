#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

const long long BASE = 256;
const long long MOD = 1000000007;

class RollingHash {
private:
    long long hash;
    long long power;
    int windowSize;

public:
    RollingHash() : hash(0), power(1), windowSize(0) {}

    long long computeHash(const std::string& s) {
        int n = s.length();
        hash = 0;
        power = 1;
        windowSize = n;

        for (int i = 0; i < n; i++) {
            hash = (hash * BASE + s[i]) % MOD;
            if (i < n - 1) {
                power = (power * BASE) % MOD;
            }
        }
        return hash;
    }

    long long roll(char outChar, char inChar) {
        hash = (hash - outChar * power % MOD + MOD) % MOD;
        hash = (hash * BASE + inChar) % MOD;
        return hash;
    }

    long long getHash() const { return hash; }

    int getWindowSize() const { return windowSize; }
};

std::vector<std::pair<int, int>> findCollisions(const std::string& text, int windowSize) {
    std::vector<std::pair<int, int>> collisions;
    int n = text.length();

    if (windowSize > n || windowSize <= 0) return collisions;

    RollingHash rh;
    std::unordered_map<long long, std::vector<int>> hashMap;

    long long h = rh.computeHash(text.substr(0, windowSize));
    hashMap[h].push_back(0);

    for (int i = 1; i <= n - windowSize; i++) {
        h = rh.roll(text[i - 1], text[i + windowSize - 1]);
        hashMap[h].push_back(i);
    }

    for (const auto& entry : hashMap) {
        const auto& positions = entry.second;
        if (positions.size() > 1) {
            for (size_t i = 0; i < positions.size(); i++) {
                for (size_t j = i + 1; j < positions.size(); j++) {
                    collisions.push_back({positions[i], positions[j]});
                }
            }
        }
    }

    return collisions;
}

int main() {
    int choice;
    std::string text;
    RollingHash rh;

    do {
        std::cout << "\n===== 滚动哈希 =====" << std::endl;
        std::cout << "1. 计算字符串哈希值" << std::endl;
        std::cout << "2. 滚动哈希演示(滑动窗口)" << std::endl;
        std::cout << "3. 查找相同哈希的子串(碰撞检测)" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "请选择: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "请输入字符串: ";
            std::cin >> text;
            long long h = rh.computeHash(text);
            std::cout << "哈希值: " << h << std::endl;
            break;
        }
        case 2: {
            int windowSize;
            std::cout << "请输入文本: ";
            std::cin >> text;
            std::cout << "请输入窗口大小: ";
            std::cin >> windowSize;

            if (windowSize > (int)text.length()) {
                std::cout << "窗口大小超过文本长度" << std::endl;
                break;
            }

            long long h = rh.computeHash(text.substr(0, windowSize));
            std::cout << "窗口[0, " << windowSize - 1 << "] \"" << text.substr(0, windowSize)
                      << "\" 哈希值: " << h << std::endl;

            for (int i = 1; i <= (int)text.length() - windowSize; i++) {
                h = rh.roll(text[i - 1], text[i + windowSize - 1]);
                std::cout << "窗口[" << i << ", " << i + windowSize - 1 << "] \""
                          << text.substr(i, windowSize) << "\" 哈希值: " << h << std::endl;
            }
            break;
        }
        case 3: {
            int windowSize;
            std::cout << "请输入文本: ";
            std::cin >> text;
            std::cout << "请输入窗口大小: ";
            std::cin >> windowSize;

            auto collisions = findCollisions(text, windowSize);
            if (collisions.empty()) {
                std::cout << "未发现哈希碰撞" << std::endl;
            } else {
                std::cout << "发现 " << collisions.size() << " 组哈希碰撞:" << std::endl;
                for (const auto& c : collisions) {
                    std::string s1 = text.substr(c.first, windowSize);
                    std::string s2 = text.substr(c.second, windowSize);
                    std::cout << "  位置" << c.first << " \"" << s1 << "\" 与 位置"
                              << c.second << " \"" << s2 << "\"";
                    if (s1 == s2)
                        std::cout << " [完全相同]";
                    else
                        std::cout << " [哈希碰撞!]";
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 0:
            std::cout << "退出滚动哈希" << std::endl;
            break;
        default:
            std::cout << "无效选择" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
