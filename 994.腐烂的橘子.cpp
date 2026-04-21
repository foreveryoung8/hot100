/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 鑵愮儌鐨勬瀛?
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
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // 这是你要试的“全图遍历 + 逐轮扩散”版本。
        // 每一轮都扫一遍整个网格，找出这一轮会变烂的新橘子，再统一更新。
        // 思路直观，但如果轮数很多，整体可能会超时。
        while (true) {
            vector<pair<int, int>> willRot;

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] != 2) continue;
                    for (auto& d : dirs) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        if (grid[ni][nj] == 1) {
                            willRot.push_back({ni, nj});
                        }
                    }
                }
            }

            if (willRot.empty()) break;

            for (auto& p : willRot) {
                grid[p.first][p.second] = 2;
            }
            ++minutes;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};
// @lc code=end
