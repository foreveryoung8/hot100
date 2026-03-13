/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // [错误示例-1] 纯递归会重复计算，n=45 容易 Time Limit Exceeded
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // if (n == 3) return 3;
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // 提示：把问题改成“到第 i 阶有多少种走法”，用自底向上 DP。
        if (n <= 2) return n;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            // TODO: 状态转移写在这里
            // 提示1：dp[i] 只和前两个状态有关
            // 提示2：先手算 i=3,4,5，再归纳递推式
            dp[i]=dp[i-1]+dp[i-2];
        }

        // TODO: 返回最终状态
        return dp[n];
    }
};
// @lc code=end

