#include "31_lcs_dp.h"
#include <iostream>

int main() {
    std::cout << "LCS(\"ABCBDAB\", \"BDCAB\") = " << lcsDP("ABCBDAB", "BDCAB") << "\n";
    std::cout << "LCS(\"AGGTAB\", \"GXTXAYB\") = " << lcsDP("AGGTAB", "GXTXAYB") << "\n";
    return 0;
}
