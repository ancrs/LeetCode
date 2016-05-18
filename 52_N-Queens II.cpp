Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.



class Solution {
public:
    void dfs(vector<int> &pos,int index,int n,int &sum)
    {
        if(index==n)
        {
            sum++;
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
                dfs(pos,index+1,n,sum);
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> pos(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            pos[i]=i;
        }
        dfs(pos,0,n,sum);
        return sum;
    }
};