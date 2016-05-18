Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)


int max(int a,int b)
{
    return a>b?a:b;
}
int jump(int* nums, int numsSize) {
    int step=0;
    int maxpath=0;
    int cur=0;
    for(int i=0;i<numsSize;i++)
    {
        if(cur<i)
        {
            step++;
            cur=maxpath;
        }
        maxpath=max(maxpath,nums[i]+i);
    }
    return step;
}