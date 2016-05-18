Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int total=1;
    int num=0;
    int flag=0;
    *returnSize=numsSize;
    if(numsSize==0 || numsSize==1)
    {
        return nums;
    }
    
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            flag=i;
            num++;
            continue;
        }
        total*=nums[i];
    }
    if(num>=2)
    {
        memset(nums,0,4*numsSize);
    }
    else if(num==1)
    {
        for(int i=0;i<numsSize;i++)
        {
            if(flag==i)
            {
                nums[i]=total;
                continue;
            }
            nums[i]=0;
        }
    }
    else{
        for(int i=0;i<numsSize;i++)
        {
            nums[i]=total/nums[i];
        }
    }
    return nums;
}