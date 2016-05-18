Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


class Solution {
public:
    void com(int start,int n,int k,int cur,vector<int>& nums,vector<int>& path,vector<vector<int>>& result)
    {
        if(cur==k)
        {
            vector<vector<int>>::iterator it=result.end();
            it=find(result.begin(),result.end(),path);
            if(it<result.end())
            {
                return;
            }
            else{
                result.push_back(path);
                return;
            }
        }
        for(int i=start;i<=n;i++)
        {
            path.push_back(nums[i-1]);
            com(i+1,n,k,cur+1,nums,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        int n=nums.size();
        result.push_back(path);
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++)
        {
            com(1,n,i,0,nums,path,result);
        }
        return result;
    }
};