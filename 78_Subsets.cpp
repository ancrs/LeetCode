Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


class Solution {
public:
    void com(int start,int n,int k,int cur,vector<int>& nums,vector<int>& path,vector<vector<int>>& result)
    {
        if(cur==k)
        {
            result.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            path.push_back(nums[i-1]);
            com(i+1,n,k,cur+1,nums,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        vector<int> path;
        if(n==0)
        {
            return result;
        }
        sort(nums.begin(),nums.end());
        result.push_back(path);
        for(int i=1;i<=n;i++)
        {
            com(1,n,i,0,nums,path,result);
        }
        return result;
    }
};