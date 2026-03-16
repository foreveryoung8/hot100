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
    // [错误示例-1]
    // 这里的 depth++ 传入递归时，用到的是自增前的旧值，不是下一层深度。
    //
    // [错误示例-2]
    // 左右子树被重复递归调用了多次，既低效，也让结果更难判断。
    //
    // int isbetter(TreeNode* left,TreeNode* right,int depth){
    //     if (left==nullptr&&right==nullptr)
    //     {
    //         return depth;
    //     }
    //
    //     if (left==nullptr&&right!=nullptr)
    //     {
    //         return isbetter(right->left,right->right,depth++);
    //     }
    //     if (right==nullptr&&left!=nullptr)
    //     {
    //         return isbetter(left->left,left->right,depth++);
    //     }
    //
    //     return isbetter(right->left,right->right,depth++)>isbetter(left->left,left->right,depth++)?isbetter(right->left,right->right,depth++):isbetter(left->left,left->right,depth++);
    // }

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
