// 1. Two Sum —— 样例：include 解法文件 + 自己写 main
#include <iostream>
#include <vector>

#include "1.two-sum.cpp"

int main() {
    Solution s;
    std::vector<int> nums{2, 7, 11, 15};
    auto ans = s.twoSum(nums, 9);
    std::cout << ans[0] << " " << ans[1] << "  (expect: 0 1 或 1 0，顺序无要求)\n";
    return 0;
}
