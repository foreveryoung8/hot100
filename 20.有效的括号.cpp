// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <map>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {

        int n= s.size();
        stack<char> st;
        for(int i = 0 ;i < n ;i++){

            if (s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if (st.empty())
                {
                    return false;
                }                
            }
            
           if(s[i]=='('||s[i]=='{'||s[i]=='[')
             st.push(s[i]);
            
            if(s[i]==')'){
                if (st.top()!='(')
                {
                    return false;

                }else {st.pop();}
                
            }
            if(s[i]=='}'){
                if (st.top()!='{')
                {
                    return false;

                }else {st.pop();}
                
            }
            if(s[i]==']'){
                if (st.top()!='[')
                {
                    return false;

                }else {st.pop();}
                
            }




        }
        
        return st.empty();

    }
};
// @lc code=end

