// 15. 自动生成的测试骨架 —— tools/newtest 15
// 需要你补的只有「填输入」那几行；调用的方法名/类型都是从这个文件里抄出来的。
#include <iostream>
#include <string>
#include <vector>

#include "15.3-sum.cpp"

// ---- 打印辅助（返回类型不支持时请手改） ----
static void show(const std::vector<int> &v) {
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
}
static void show(const std::vector<std::string> &v) {
    for (const auto &s : v) std::cout << s << ' ';
    std::cout << '\n';
}
static void show(const std::vector<std::vector<int>> &v) {
    for (const auto &row : v) { show(row); }
}
template <class T> void show(const T &x) { std::cout << x << '\n'; }

int main() {
    Solution s;
    vector<int> nums{};   // TODO: 填输入

    auto ans = s.threeSum(nums);
    show(ans);
    return 0;
}
