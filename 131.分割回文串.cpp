/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
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
    vector<vector<string>> res;
    vector<string> path;
    
    bool huiwen(const string& s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
    
    void dfs(string &s,int i){
        if(i==s.size()){
            res.push_back(path);
            return;
        }
        for(int j=1;j<s.size()-i+1;j++){

            if(!huiwen(s.substr(i,j))){
                continue;
            }

            path.push_back(s.substr(i,j));
            dfs(s,i+j);
            path.pop_back();

        }


    }

    vector<vector<string>> partition(string s) {
        res.clear();
        path.clear();
        if(s.empty())return res;
        dfs(s,0);
        return res;
    }
};
// @lc code=end

