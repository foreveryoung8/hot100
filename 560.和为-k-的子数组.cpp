/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
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

    int subarraySum(vector<int>& nums, int k) {      
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int j=i;
            int temp=0;
            
            while (j<n)
            {
                temp+=nums[j++];
                if(temp==k)ans++;
            }

        }
        return ans;
            


    }
};
// @lc code=end

