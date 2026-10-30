#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start

/*
 * 给定一个二叉树 root，返回其最大深度。
 * 二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。
 *
 * 示例：
 *      3
 *     / \
 *    9  20
 *       / \
 *      15  7
 *   -> 3
 *
 *   1
 *    \
 *     2
 *   -> 2
 *
 *   空树 -> 0
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // TODO: 你写
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};
// @lc code=end
