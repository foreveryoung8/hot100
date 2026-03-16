/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr)return false;
        vector<int> a,b;
        
        
        while (head!=nullptr)
        {
            /* code */
            a.push_back(head->val);
            b.push_back(head->val);
            head=head->next;

        }
       
        reverse(a.begin(),a.end());

        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])return false;

        }
        return true;

    }
};
// @lc code=end

