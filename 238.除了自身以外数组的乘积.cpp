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
        vector<int> res(n, 1);
        vector<int> qian(n, 1);      // qian[i] = nums[0]*...*nums[i-1] (左边不包括i)
        vector<int> hou(n, 1);       // hou[i] = nums[i+1]*...*nums[n-1] (右边不包括i)
        
        // 左边前缀乘积
        for(int i=1; i<n; i++){
            qian[i] = qian[i-1] * nums[i-1];
        }
        
        // 右边后缀乘积
        for(int j=n-2; j>=0; j--){
            hou[j] = hou[j+1] * nums[j+1];
        }
        
        // 结果 = 左乘积 * 右乘积
        for(int i=0; i<n; i++){
            res[i] = qian[i] * hou[i];
        }

        return res;
    }
};
// @lc code=end

