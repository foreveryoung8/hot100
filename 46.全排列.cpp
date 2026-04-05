/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * 
 * backtrack(路径, 选择列表):
    if 满足结束条件:
        收集答案
        return

    for 选择 in 当前可选项:
        if 选择不合法:
            continue

        做选择
        backtrack(路径, 选择列表)
        撤销选择

 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            dfs(nums, used);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
// @lc code=end

