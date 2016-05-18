Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.


int findMin(int* nums, int numsSize) {
    if(numsSize==1)
    {
        return nums[0];
    }
    int i;
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]<nums[i-1])
        {
            break;
        }
    }
    if(i==numsSize)
    return nums[0];
    else
    {
        return nums[i];
    }
}