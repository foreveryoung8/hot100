/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
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


class Solution {
public:
        int findMin(vector<int>& nums) {
            int i = 0, j = nums.size() - 1;
            while (i < j) {
                int mid = (i + j) / 2;
                if (nums[mid] > nums[j]) {
                    i = mid + 1;  // 最小值在右边
                } else if (nums[mid] < nums[j]) {
                    j = mid;      // 最小值在左边（包含mid）
                } 
            }
            return nums[i];
        }
};
// @lc code=end

