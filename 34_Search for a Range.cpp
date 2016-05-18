Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findfirst(int* nums,int left,int right,int target)
{
    int start=left;
    int end=right;
    
    int flag=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(nums[mid]>=target)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        if(nums[mid]==target)
        {
            flag=mid;
        }
    }
    return flag;
}

int findend(int* nums,int left,int right,int target)
{
    int start=left;
    int end=right;
    
    int flag=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(nums[mid]<=target)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        if(nums[mid]==target)
        {
            flag=mid;
        }
    }
    return flag;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* set=(int*)malloc(sizeof(int)*2);
    (*returnSize)=2;
    set[0]=findfirst(nums,0,numsSize-1,target);
    set[1]=findend(nums,0,numsSize-1,target);
    return set;
}