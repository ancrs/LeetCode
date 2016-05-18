Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1




class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0,swapindex = 0;
        for (int i = 1; i < nums.size(); i++)
            if  (nums[i - 1] < nums[i])
                index = i;
        if (index > 0){
            int i = nums.size() - 1;
            while (i > (index - 1) && nums[index-1] >= nums[i]) i--;
            swap(nums[index - 1],nums[i]);
        }
        sort(nums.begin() + index,nums.end());
    }
};