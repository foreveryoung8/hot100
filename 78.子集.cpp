/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> res;
    vector<int> path;

    // ===== 之前的错误尝试（保留用于对照）=====
    // 错误点：当 i == nums.size() 时还访问 nums[i] 会越界，产生随机脏值。
    // 错误示例（不要这样写）：
    // if (i == nums.size()) {
    //     res.push_back(path);
    //     path.push_back(nums[i]); // 越界访问
    //     res.push_back(path);
    //     return;
    // }
    void dfs(vector<int>& nums, int i) {
        // 到达末尾：当前 path 就是一个合法子集
        if (i == (int)nums.size() ) {
            res.push_back(path);
            return;

        }

        // 当前元素不选
        dfs(nums, i + 1);

        // 当前元素选择
        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();

        // 本题不依赖排序；这里保留排序不影响正确性。
        sort(nums.begin(), nums.end());

        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
