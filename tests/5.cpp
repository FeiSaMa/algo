// 5. 自动生成的测试骨架 —— tools/newtest 5
// 需要你补的只有「填输入」那几行；调用的方法名/类型都是从这个文件里抄出来的。
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>



#include "5.longest-palindromic-substring.cpp"

// ---- 打印辅助（返回类型不支持时请手改） ----
[[maybe_unused]] static void show(const std::vector<int> &v) {
    for (int x : v) std::cout << x << ' ';
    std::cout << '\n';
}
[[maybe_unused]] static void show(const std::vector<std::string> &v) {
    for (const auto &s : v) std::cout << s << ' ';
    std::cout << '\n';
}
[[maybe_unused]] static void show(const std::vector<std::vector<int>> &v) {
    for (const auto &row : v) { show(row); }
}
template <class T> void show(const T &x) { std::cout << x << '\n'; }

int main() {
    using namespace std;
    Solution s;

    // 覆盖：偶数中心 / 单字符 / 无长回文 / 全相同 / 空串 / 奇数中心
    vector<string> cases = {"babad", "cbbd", "a", "ac", "aaaa", "", "abcba"};
    for (const auto &input : cases) {
        string ce = s.longestPalindrome(input);      // 中心扩展（推荐解）
        string dp = s.longestPalindromeDP(input);    // 区间 DP（对照）
        bool same = ce.size() == dp.size();
        cout << (same ? "OK  " : "DIFF") << " \"" << input << "\""
             << "  CE=\"" << ce << "\"  DP=\"" << dp << "\""
             << "  len=" << ce.size() << '\n';
    }
    return 0;
}
