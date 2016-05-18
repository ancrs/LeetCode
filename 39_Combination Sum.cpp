Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 


class Solution {
public:
    void combination(int start,int sum,int size,vector<int> nums,vector<int> &path,vector<vector<int>> &result)
    {
        if(sum==0)
        {
            result.push_back(path);
            return;
        }
        else if(sum<0)
        {
            return;
        }
        for(int i=start;i<size;i++)
        {
            path.push_back(nums[i]);
            combination(i,sum-nums[i],size,nums,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int size=candidates.size();
        sort(candidates.begin(),candidates.end());
        combination(0,target,size,candidates,path,result);
        return result;
    }
};