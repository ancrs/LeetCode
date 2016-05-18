Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]


class Solution {
public:
    void combination(int start,int sum,int cur,int k,vector<vector<int>> &result,vector<int> &path)
    {
        if(sum<0)
        {
            return;
        }
        else if(cur==k)
        {
            if(sum==0)
            {
               result.push_back(path);
            }
            return;
        }
        for(int i=start;i<=9;i++)
        {
            path.push_back(i);
            combination(i+1,sum-i,cur+1,k,result,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        combination(1,n,0,k,result,path);
        return result;
    }
};