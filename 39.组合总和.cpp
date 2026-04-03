// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // 收集所有满足条件的组合
    vector<vector<int>> ans;
    // 当前递归路径（正在构造的一个组合）
    vector<int> path;

    void dfs(vector<int>& candidates, int remain, int start) {
        // 命中答案：剩余值为 0，记录路径
        if (remain == 0) {
            ans.push_back(path);
            return;
        }

        // 从 start 开始，避免回头选导致重复组合
        for (int i = start; i < (int)candidates.size(); i++) {
            // 已排序，可直接剪枝
            if (candidates[i] > remain) break;

            // 选择当前数
            path.push_back(candidates[i]);
            // 可重复使用当前数，因此下一层仍传 i
            dfs(candidates, remain - candidates[i], i);
            // 回溯：撤销选择
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 初始化本轮状态
        ans.clear();
        path.clear();

        // 排序后更容易剪枝
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

/*
错误尝试（保留，便于避坑）：
1) 把关键语句写在 // 注释同一行后面，例如：
   // 回溯 path.pop_back();
   会导致语句被注释掉，逻辑失效。
2) 初始化或递归入口同理，若写在注释同一行后会不执行。
*/

/*
==================== DFS / 回溯通用模板 ====================
使用方式：按题目替换状态变量与终止条件。

class DfsTemplate {
public:
    vector<vector<int>> res; // 结果集
    vector<int> path;        // 当前路径

    // 参数可改为：index / remain / start / used 等
    void dfs(vector<int>& nums, int remain, int start) {
        // 1) 终止条件
        if (remain == 0) {
            res.push_back(path);
            return;
        }

        // 2) 剪枝（可选）
        if (remain < 0) return;

        // 3) 枚举选择
        for (int i = start; i < (int)nums.size(); i++) {
            // 常见剪枝（排序后）
            // if (nums[i] > remain) break;

            // 4) 做选择
            path.push_back(nums[i]);

            // 5) 递归下一层
            // 可重复选：dfs(nums, remain - nums[i], i);
            // 不可重复：dfs(nums, remain - nums[i], i + 1);
            dfs(nums, remain - nums[i], i);

            // 6) 撤销选择
            path.pop_back();
        }
    }
};
*/
