// 104. 自动生成的测试骨架 —— tools/newtest 104
// 需要你补的只有「填输入」那几行；调用的方法名/类型都是从这个文件里抄出来的。
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>


#include "structs.h"
#include "104.maximum-depth-of-binary-tree.cpp"

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
    Solution s;
    TreeNode * root{make_tree({3, 9, 20, std::nullopt, std::nullopt, 15, 7})};   // TODO: 填输入

    auto ans = s.maxDepth(root);
    show(ans);
    return 0;
}
