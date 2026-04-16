/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 鍓?K 涓珮棰戝厓绱?
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
// 全局比较规则：按频次构建小顶堆
// 返回 true 表示 a 的优先级低于 b；这样堆顶会是频次最小的元素


class Solution {
public:
    struct MinFreqCmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 第一步：统计每个数字出现的频次
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // 第二步：维护一个大小最多为 k 的小顶堆（堆顶是当前最小频次）
        priority_queue<pair<int, int>, vector<pair<int, int>>, MinFreqCmp> pq;
        for (auto& kv : freq) {
            pq.push(kv); // kv.first 是数字，kv.second 是频次
            if ((pq.size()) > k) {
                pq.pop(); // 超过 k 时，弹出频次最小的
            }
        }

        // 第三步：取出堆中元素即为前 k 个高频元素
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        //reverse(ans.begin(), ans.end()); // 让结果更直观（高频在前）
        return ans;
    }
};
// @lc code=end
