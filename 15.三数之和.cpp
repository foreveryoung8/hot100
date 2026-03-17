// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
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
// Previous attempt (buggy; kept for reference):
// - No size guard before accessing nums[0..2] -> debug crash on small input.
// - Early return for [0,0,0] can drop other valid triples.
// - Missing duplicate skipping for left/right pointers.


// Current attempt (keeps hints instead of full solution).
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Hints:
        // 1) Guard size < 3 to avoid out-of-bounds (your debug crash).
        // 2) The [0,0,0] early return is incorrect if other triples exist.
        // 3) To avoid duplicates, skip equal values for i/l/r after sorting.
        if (nums.size() < 3) {
            return {};
        }

        vector<vector<int>> res;
        vector<int> temp;


        int count = static_cast<int>(nums.size());
        sort(nums.begin(), nums.end());

        for (int i = 0; i < count - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = count - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    res.push_back(temp);
                    temp.clear();
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;

                }

            }
        }
        return res;
    }
};
// @lc code=end

