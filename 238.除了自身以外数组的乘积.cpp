/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除了自身以外数组的乘积
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <array>
#include <utility>
#include <tuple>
#include <functional>
#include <numeric>
#include <cmath>
#include <climits>
#include <limits>
#include <cctype>
#include <cstring>
#include <sstream>
#include <bitset>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(nums.size(), 1);
        vector<int> qian(n, 1);      // 改为大小 n
        vector<int> hou(n, 1);       // 改为大小 n
        
        // 前缀乘积：qian[i] = nums[0]*nums[1]*...*nums[i]
        for(int i=1; i<n; i++){
            qian[i] = nums[i] * qian[i-1];
        }
        
        // 后缀乘积：hou[j] = nums[j]*nums[j+1]*...*nums[n-1]
        for(int j=n-2; j>=0; j--){
            hou[j] = nums[j] * hou[j+1];
        }
        
        // res[i] = qian[i-1] * hou[i+1]
        for(int i=0; i<n; i++){
            if(i > 0) res[i] *= qian[i-1];
            if(i < n-1) res[i] *= hou[i+1];
        }

        return res;
    }
};
// @lc code=end

