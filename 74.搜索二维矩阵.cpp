/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false; 

        int m = matrix.size();
        int n = matrix[0].size();


        // matrix = [
        //   [1, 3, 5],
        //   [10, 11, 16],
        //   [23, 30, 34]
        // ]
        // target = 8

        int row = -1;
        if (matrix[0][0] > target || matrix[m - 1][n - 1] < target) return false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i][n - 1]) {
                row = i;
                break;
            }
        }
        if (row == -1) return false; 

        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target) {
                i = mid + 1;
            }
            if (matrix[row][mid] > target) {
                j = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
