Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


class Solution {
public:
    vector <string> ans;

    void para(int i,int open,int n,string s)
    {
        if(open < 0)    return;
        if(i==n)
        {
            if(open==0)
                ans.push_back(s);
            return;
        }
        para(i+1,open+1,n,s+"(");   
        para(i+1,open-1,n,s+")");
    }

    vector<string> generateParenthesis(int n) {

        string s = "";
        para(0,0,2*n,s);
        return ans;
    }
};