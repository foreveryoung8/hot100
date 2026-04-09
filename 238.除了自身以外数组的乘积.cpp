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
    
        vector<int> res(nums.size(), 1);

        /*
        你的原思路可以理解成：
        1 2 3 4
        1 1 1 1   -> 先放“左边乘积”
        1 1 2 6   -> 再乘上“右边乘积”

        这里的关键不是一次性算总乘积，而是拆成两趟：
        - 第一趟：记录每个位置左边所有数的乘积
        - 第二趟：再乘上每个位置右边所有数的乘积
        */

        // TODO: 第一趟从左到右
        int prefix = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            res[i] *= prefix;
            prefix *= nums[i];
        }

        // TODO: 第二趟从右到左
        int suffix = 1;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }

        return res;
    }
};
// @lc code=end

