Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


bool canJump(int* nums, int numsSize) {
    if(numsSize==0 || numsSize==1)
    {
        return true;
    }
    int maxstep=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(maxstep==0)
        {
            return false;
        }
        maxstep--;
        if(maxstep<nums[i])
        {
            maxstep=nums[i];
        }
        if(maxstep+i>=numsSize-1)
        {
            return true;
        }
    }
}    