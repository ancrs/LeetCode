Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]



class Solution {
public:
    void exec(int start,string s,vector<vector<int>> dp,vector<vector<string>> &result,vector<string> &path)
    {
        if(start==s.length())
        {
            result.push_back(path);
            return;
        }
        for(int i=1;i<=s.length()-start;i++)
        {
            if(dp[start][start+i-1]==1)
            {
                path.push_back(s.substr(start,i));
                exec(start+i,s,dp,result,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len=s.length();
        vector<vector<int>> dp(len,vector<int>(len));
        vector<vector<string>> result;
        vector<string> path;
        if(len==0)
        {
            return result;
        }
        for(int i=0;i<len;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
        }
    }
    for(int k=2;k<len;k++)
    {
        for(int i=0;i<len-k;i++)
        {
            int j=i+k;
            if(dp[i+1][j-1] && s[i]==s[j])
            {
                dp[i][j]=1;
            }
        }
        
    }
    exec(0,s,dp,result,path);
    return result;
    }
};  