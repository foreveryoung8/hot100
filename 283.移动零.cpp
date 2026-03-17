/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
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
    void moveZeroes(vector<int>& nums) {
        int i=0;

        for (int  t = 1; t < nums.size(); t++)
        {
            if(nums[i]!=0)i++;
            if(nums[t]==0){
                continue;
            }
            else {
                if(nums[i]==0){
                    swap(nums[i],nums[t]);
                    i++;

            }
        }
  
    }
};
// @lc code=end

