// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem101.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
     
    bool pair(TreeNode* a,TreeNode* b){
        if(a==nullptr&&b!=nullptr)return false;
        if(b==nullptr&&a!=nullptr)return false;
        if (a==nullptr&&b==nullptr) return true;
        if(a->val!=b->val)return false;

        return pair(a->left,b->right)&&pair(a->right,b->left);
 
        
        

    }
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr)
        {
        
            return true;
        }
        return pair(root->left,root->right);
        

    }
};
// @lc code=end

