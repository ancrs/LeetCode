Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
'


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n < 1)
        {
            return 0;
        }
        int result = n+1;
        int sum = 0;
        int left = 0;
        int right = 0;

        while (right < n)
        {
            sum += nums[right];
            if (sum >= s)
            {
                while (sum >= s)
                {
                    int temp = right-left+1;
                    if (temp < result)
                    {
                        result = temp;
                    }
                    sum -= nums[left];
                    left++;
                }
            }
            right++;
        }

        if (result > n)
        {
            return 0;
        }

        return result; 
    }
};