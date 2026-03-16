// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem108.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* build(vector<int>& nums, int left, int right){
        if (left>right)
        {
            return nullptr;
        }
        int mid=(left+right)/2;
        TreeNode *temp=new TreeNode(nums[mid]);
        temp->left=build(nums,left,mid-1);
        temp->right=build(nums,mid+1,right);
        return temp;
        

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
  
        if(nums.size()==0)return nullptr;
        return build(nums,0,nums.size()-1);
        
    }
};
// @lc code=end

