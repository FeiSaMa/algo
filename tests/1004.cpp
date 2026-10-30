// 1004. Max Consecutive Ones III —— 带循环的题，适合练断点/日志点
#include <iostream>
#include <vector>

#include "1004.max-consecutive-ones-iii.cpp"

int main() {
    Solution s;

    // LeetCode 官方样例 1
    std::vector<int> a{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    std::cout << "case1 = " << s.longestOnes(a, 2) << "  (expect: 6)\n";

    std::vector<int> b{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    std::cout << "case2 = " << s.longestOnes(b, 3) << "  (expect: 10)\n";
    return 0;
}
