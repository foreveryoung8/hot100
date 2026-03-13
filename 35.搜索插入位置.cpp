// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem35.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n=nums.size();
        if(n==0)return 0;

        
        int i=0,j=n-1;
       
        while (i<=j)
        {
            int temp=(i+j)/2;
            if(nums[temp]<target){
                i=temp+1;
            }else if (nums[temp]>target)
            {
                /* code */
                j=temp-1;
            }else{
                return temp;
            }
            
        }
        
        return i;
    }
};
// @lc code=end

