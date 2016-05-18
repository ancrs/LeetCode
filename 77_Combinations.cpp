Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


class Solution {
public:
    void com(int start,int cur,int n,int k,vector<vector<int>> &res,vector<int> &path)
    {
        if(cur==k)
        {
            res.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            path.push_back(i);
            com(i+1,cur+1,n,k,res,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        if(n<k || n==0 || k==0)
        {
            return result;
        }
        com(1,0,n,k,result,path);
        return result;
    }
};