#pragma once
// LeetCode 链表 / 二叉树节点的标准定义。
// 有些解法文件只把定义写在注释里（或干脆没写），测试文件 include 本文件补上类型。
// 如果某个解法文件里已经写了非注释版的同名声明的，会冲突 —— 那时删掉这里对应的 struct。

#include <cstddef>
#include <initializer_list>
#include <optional>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---- 构造辅助：省掉手撸 new 的样板 ----
inline ListNode *make_list(std::initializer_list<int> vals) {
    ListNode dummy;
    ListNode *cur = &dummy;
    for (int v : vals) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy.next;
}

// LeetCode 层序表示：{3, 9, 20, nullopt, nullopt, 15, 7}
inline TreeNode *make_tree(std::vector<std::optional<int>> vals) {
    if (vals.empty() || !vals[0]) return nullptr;
    TreeNode *root = new TreeNode(*vals[0]);
    std::vector<TreeNode *> q{root};
    size_t i = 1, head = 0;
    while (head < q.size() && i < vals.size()) {
        TreeNode *node = q[head++];
        if (i < vals.size() && vals[i]) {
            node->left = new TreeNode(*vals[i]);
            q.push_back(node->left);
        }
        ++i;
        if (i < vals.size() && vals[i]) {
            node->right = new TreeNode(*vals[i]);
            q.push_back(node->right);
        }
        ++i;
    }
    return root;
}
