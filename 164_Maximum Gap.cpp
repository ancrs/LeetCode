Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return 0;
        }
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<len;i++)
        {
            if(nums[i]-nums[i-1]>ans)
            {
                ans=nums[i]-nums[i-1];
            }
        }
        return ans;
    }
};