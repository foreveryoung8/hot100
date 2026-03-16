// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem118.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include<vector>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i+1);
            res[i][0]=1;
            
        }

        res[0][0]=1;
        if (numRows==1)
        {
            return res;
        }
        res[1][0]=1;res[1][1]=1;
        if (numRows==2)
        {
            return res;
        }

        
        
        for(int i=2;i<numRows;i++){
            
            for (int j = 1; j < i; j++)
            {
                /* code */
                res[i][j]=res[i-1][j-1]+res[i-1][j];

            }
            res[i][i]=1;
            
        }
        return res;

        
    }
};
// @lc code=end

