/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int>& nums) {


        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int ans = 0;

        for (int x : st) {
            if (!st.count(x - 1)) {
                int cur = x;
                int len = 1;

                while (st.count(cur + 1)) {
                    cur++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};
// @lc code=end
