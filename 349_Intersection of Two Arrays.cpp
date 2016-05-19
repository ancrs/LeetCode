Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> m(nums1.begin(), nums1.end());
        for(int i=0;i<nums2.size();i++)
        {
            if(m.count(nums2[i]))
            {
                result.push_back(nums2[i]);
                m.erase(nums2[i]);
            }
        }
        return result;
    }
};