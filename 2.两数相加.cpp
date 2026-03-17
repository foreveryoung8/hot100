/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int v=0;
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        curr=res;

        while (l1 != nullptr || l2 != nullptr)
        {
            /* code */       
            
            if(l1!=nullptr){
                v+=l1->val;
                l1=l1->next;
            }
            if (l2!=nullptr)
            {
                /* code */
                v+=l2->val;
                l2=l2->next;
            }
            
            ListNode* temp=new ListNode(v%10);
            v=v/10;
            curr->next=temp;
            curr=temp;

        }
        if(v){
            ListNode* temp=new ListNode(v%10);
            curr->next=temp;
            curr=temp;
        }
        return res->next;
        
        
    }
};
// @lc code=end

