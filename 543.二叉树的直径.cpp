/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


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

    int res=0;

    int treeAdd(TreeNode* a){
        if(a==nullptr)return 0;
        int left=treeAdd(a->left); 
        int right=treeAdd(a->right); 
        res=max(res,(left+right));

        return max(left,right)+1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        treeAdd(root);
        return res;
    }
};
// @lc code=end

