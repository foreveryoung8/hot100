/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 错误代码保留：
        // if(intervals.size()==1)return intervals;
        // int i=0;
        // vector<int> temp;
        // while (i<intervals.size()-1)
        // {
        //     if (intervals[i][1]>=intervals[i+1][0]&&
        //         intervals[i][0]<=intervals[i+1][0])
        //     {
        //         temp.push_back(intervals[i][0]);
        //         temp.push_back(max(intervals[i][1],intervals[i+1][1]));
        //         intervals.erase(intervals.begin() + i, intervals.begin() + i + 1); // 错误1：删除单个元素应该只传一个参数
        //         intervals.insert(intervals.begin() +i,temp);  // 错误2：频繁 erase+insert 导致 TLE，时间复杂度 O(n²)
        //         temp.clear();
        //         // 错误3：没有排序，相邻区间不一定能合并
        //         // 错误4：合并后应该保持 i 不变，继续检查能否与下一个合并
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return intervals;

        if(intervals.size()==1)return intervals;

        // 关键：先排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        int i=0;
        vector<int> temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);

        while (i<intervals.size()-1)
        {
            if (temp[1]>=intervals[i+1][0])
            {
                temp[1] = max(temp[1],intervals[i+1][1]);
            }
            else{
                result.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i+1][0]);
                temp.push_back(intervals[i+1][1]);
            }
            i++;
        }
        result.push_back(temp);
        return result;
    }
};
// @lc code=end

