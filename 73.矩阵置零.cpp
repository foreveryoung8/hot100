/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
    
    void setZeroes(vector<vector<int>>& matrix) {
        // 旧思路：边扫描边修改，会把自己制造出来的 0 再次当成原始 0。
        // 这会导致连锁扩散，所以要先记录，再统一修改。
        if (matrix.empty() || matrix[0].empty()) return;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool> row(n, false);
        vector<bool> col(m, false);

        // 第 1 遍：只记录哪些行 / 列需要清零
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // 第 2 遍：统一修改
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
// @lc code=end

