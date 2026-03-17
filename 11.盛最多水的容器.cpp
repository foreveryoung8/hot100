// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem11.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int>& height) {
        int res=0,i=0;
        int j=height.size()-1;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         res=max(res,min(height[i],height[j])*(j-i));

        //     }
        // }
        while (i<j)
        {
            /* code */
            res=max(res,min(height[i],height[j])*(j-i));
            if(i<j&&height[i]>=height[j]){
                j--;
                continue;
            }
            if(i<j&&height[i]<height[j]){
                i++;
                continue;
            }
        }
        
        return res;

        
    }
};
// @lc code=end

