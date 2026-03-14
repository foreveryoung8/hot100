/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        map<ListNode*,int> mp;
        while (head!=nullptr)
        {
            if(mp[head]==0)mp[head]++;
            else if(mp[head]==1)return true;
            head=head->next;
        }

        return false;
        
    }
};
// @lc code=end

