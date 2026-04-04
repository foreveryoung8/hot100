/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <vector>
#include <string>
using namespace std;


// @lc code=start
class Solution {
public:
    /*
     * 你之前的错误尝试（保留）：
     * string temp;
     * void dfs(vector<vector<char>>& board, string word,int i){}
     * bool exist(vector<vector<char>>& board, string word) {
     *     dfs(board, word, 0);
     *     return temp == word;
     * }
     *
     * 问题：temp 是“全局路径”，但 DFS 有很多分支。
     * 某个分支走错后，temp 很难和其他分支正确隔离，状态会串。
     */

    int m = 0, n = 0;
    int dir[5] = {-1, 0, 1, 0, -1};

    // 含义：从 (r,c) 出发，是否能匹配 word[k..]
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int k) {
        if (board[r][c] != word[k]) return false;
        if (k == (int)word.size() - 1) return true;

        // 状态进入：标记当前格子已使用
        char saved = board[r][c];
        board[r][c] = '#';

        for (int d = 0; d < 4; ++d) {
            int nr = r + dir[d];
            int nc = c + dir[d + 1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue; // 越界
            if (dfs(board, word, nr, nc, k + 1)) {
                board[r][c] = saved; // 提前成功也要先恢复现场
                return true;
            }

        }

        // 状态退出：恢复现场（回溯核心）
        board[r][c] = saved;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = (int)board.size();
        if (m == 0) return false;
        n = (int)board[0].size();
        if (word.empty()) return true;

        // 枚举每个起点：只有起点字符对得上才值得进入 DFS
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != word[0]) continue;
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end
