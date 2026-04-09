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
            // 原来：while (i < j) {
            // 如果强行改成 <=，要加上 i == j 的处理
            while (i <= j) {
                int mid = i + (j - i) / 2;
                if (nums[mid] > nums[j]) {
                    i = mid + 1;
                } else if (nums[mid] < nums[j]) {
                    j = mid;
                } else {
                    break; // 这里通常只会在 i == j 时出现
                }
            }
            return nums[i];

        }
};
// @lc code=end

