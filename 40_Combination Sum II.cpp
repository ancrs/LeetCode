Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

class Solution {
public:
    void combination(int start,int sum,int size,vector<int> nums,vector<int> &path,vector<vector<int>> &result)
    {
        if(sum==0)
        {
            vector<vector<int>>::iterator it=result.end();
            it=find(result.begin(),result.end(),path);
            if(it!=result.end())
            {
                return;
            }
            else
            {
                result.push_back(path);
                return;
            }
        }
        else if(sum<0)
        {
            return;
        }
        for(int i=start;i<size;i++)
        {
            path.push_back(nums[i]);
            combination(i+1,sum-nums[i],size,nums,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int size=candidates.size();
        sort(candidates.begin(),candidates.end());
        combination(0,target,size,candidates,path,result);
        return result;
    }
};