The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
'
//pos[i]表示第i个皇后在第i行第pos[i]列
class Solution {
public:
    void swap(vector<int> &pos,int i,int j)
    {
        if(i!=j)
        {
            int tmp=pos[i];
            pos[i]=pos[j];
            pos[j]=tmp;
        }
    }
    void dfs(vector<int> &pos,int index,int n,vector<string> result,vector<vector<string>> &solution)
    {
        if(index==n)
        {
            for(int i=0;i<n;i++)
            {
                result[i][pos[i]]='Q';
            }
            solution.push_back(result);
            return;
        }
        int i;
        for(i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<index;j++)
            {
                if(i==pos[j] || abs(i-pos[j])==index-j)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                pos[index]=i;
                dfs(pos,index+1,n,result,solution);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<string> result;
        string str;
        vector<int> pos(n);
        for(int i=0;i<n;i++)
        {
            str+='.';
        }
        for(int i=0;i<n;i++)
        {
            result.push_back(str);
        }
        for(int i=0;i<n;i++)
        {
            pos[i]=i;
        }
        dfs(pos,0,n,result,solution);
        return solution;
    }
};

