Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.


class Solution {
public:
     int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool findPath(vector<vector<char> > &board, string& word, vector<vector<bool> >& used, int curX, int curY, int curIdx)
    {
        int n = board.size();
        int m = board[curX].size();
        if(curIdx == word.size()) return true;
        for(int k = 0; k < 4; ++k)
        {
            int newX = curX+dir[k][0];
            int newY = curY+dir[k][1];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && used[newX][newY] == false && board[newX][newY] == word[curIdx])
            {
                used[newX][newY] = true;
                if(findPath(board, word, used, newX, newY, curIdx+1)) return true;
                used[newX][newY] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        
        vector<vector<bool> > used(n, vector<bool>(n, false));
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    used[i][j] = true;
                    if(findPath(board, word, used, i, j, 1)) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
};