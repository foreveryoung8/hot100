/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: 排序后的字符串；value: 同组原字符串列表
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());

            // 关键点：groups[key] 在 key 不存在时会自动创建空 vector
            // 所以不需要先判断“是否已存在”
            groups[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(groups.size());
        for (auto& entry : groups) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
// @lc code=end

