Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

int firstMissingPositive(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++)
    {
        while(nums[i]!=i+1 && nums[i]>0 && nums[i]<numsSize+1 && nums[i]!=nums[nums[i]-1])
        {
            int tmp=nums[i];
            nums[i]=nums[tmp-1];
            nums[tmp-1]=tmp;
        }
    }
    for(int i=0;i<numsSize;i++)
    {
        if(i+1!=nums[i])
        {
            return i+1;
        }
    }
    return numsSize+1;
}