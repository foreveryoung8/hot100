/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> ans(n, 0);

        // 用一个数组当"温度 -> 最近位置"的字典
        // 比如 nextPos[75] = 5 表示温度 75 最近在第 5 天出现
        vector<int> nextPos(101, INT_MAX);

        // 从最后一天往前遍历
        // 为什么往前遍历？因为我们查询时需要右边的信息，倒序扫可以保证右边信息都准备好了
        for (int i = n - 1; i >= 0; --i) {
            int warmerIndex = INT_MAX;  // 这次要找的更高温下标，初始化为"没找到"
            
            // 枚举所有比今天温度更高的温度（比今天高1度、2度...直到100度）
            for (int t = temperatures[i] + 1; t <= 100; ++t) {
                // 在字典里查这个更高温度最近出现在哪天
                // 把所有候选温度中最近的下标保留下来
                warmerIndex = min(warmerIndex, nextPos[t]);
            }

            // 如果找到了更高温的天数，就计算间隔
            if (warmerIndex != INT_MAX) {
                ans[i] = warmerIndex - i;
            }

            // 把今天的温度也加进字典，供左边的天数查询
            nextPos[temperatures[i]] = i;
        }

        return ans;
    }
};
// @lc code=end

