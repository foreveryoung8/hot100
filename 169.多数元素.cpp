/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
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
    int majorityElement(vector<int>& nums) {
        map<int ,int >mp;
        int res;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;

        }
        int mid=(nums.size()+1)/2;
        for(auto &p:mp){
            if(p.second>=mid){
                res=p.first;
                break;
            };
        }
        return res;


    }
};
// @lc code=end

