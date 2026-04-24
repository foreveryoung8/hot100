/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m) {
            return ans;
        }

        // need 记录 p 中每个字符出现次数，window 记录当前滑动窗口中的字符次数
        vector<int> need(26, 0), window(26, 0);
        for (char c : p) {
            need[c - 'a']++;
        }

        // 先初始化第一个长度为 m 的窗口
        for (int i = 0; i < m; ++i) {
            window[s[i] - 'a']++;
        }
        if (window == need) {
            ans.push_back(0);
        }

        // 固定窗口向右滑动：右边进一个字符，左边出一个字符
        for (int right = m; right < n; ++right) {
            window[s[right] - 'a']++;
            window[s[right - m] - 'a']--;

            // 两个频次数组一致，说明当前窗口是 p 的一个字母异位词
            if (window == need) {
                ans.push_back(right - m + 1);
            }
        }

        return ans;
    }
};
// @lc code=end

