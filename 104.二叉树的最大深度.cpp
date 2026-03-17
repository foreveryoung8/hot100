// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem104.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 

    int dfs(TreeNode* node) {
        // 提示1：先想清楚空节点的深度应该返回多少。
        if (node == nullptr) {
            return 0;
        }

        // 提示2：左右子树深度分别只计算一次。
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);

        // 提示3：当前节点深度 = 左右子树较大值 + 1。
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }

    int maxDepth(TreeNode* root) {
        // 提示4：入口不需要拆成 root->left / root->right，直接从 root 开始。
        return dfs(root);
    }
};
// @lc code=end
