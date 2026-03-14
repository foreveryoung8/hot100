/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            for (int j = i+1; j < n; j++)
            {
                /* code */
                if (prices[i]>=prices[j])
                {
                    /* code */
                    break;
                }
                if ((prices[j]-prices[i])>res)
                {
                    /* code */
                    res=(prices[j]-prices[i]);
                }
                
                
            }
            
        }

        return res;
    }
};
// @lc code=end

