/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
using namespace std;


// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res;
        map<int,int> mp;
        for (int i  = 0; i < nums.size(); i++)
        {
            /* code */
            mp[nums[i]]++;
        }
        for(auto &p : mp){
            if(p.second==1){
                res=p.first;
                break;
            }
        }
        return res;
        

        
        
    }
};
// @lc code=end

