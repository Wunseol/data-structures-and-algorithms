#include "30_z_algorithm.h"
#include <iostream>

int main() {
    std::string text = "AABAACAADAABAABA";
    std::string pattern = "AABA";
    auto matches = zSearch(text, pattern);
    std::cout << "Z-array: ";
    auto z = zFunction(pattern + "$" + text);
    for (int v : z) std::cout << v << " ";
    std::cout << "\nMatches at: ";
    for (int pos : matches) std::cout << pos << " ";
    std::cout << "\n";
    return 0;
}
