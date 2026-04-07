/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=0;
        for (int  i = 0; i < nums.size(); i++)
        {
            if(nums[i]==0){zero++;}
                else if(nums[i]==1){one++;}
                    else if(nums[i]==2){ two++;}
        }
        
        for (int m = 0; m < zero; m++)
        {
            nums[m]=0;
        }
        for (int m=zero; m < one+zero ; m++)
        {
            nums[m]=1;
        }
        for (int m=one+zero ; m < nums.size(); m++)
        {
            nums[m]=2;
        }
        
    }
};
// @lc code=end

