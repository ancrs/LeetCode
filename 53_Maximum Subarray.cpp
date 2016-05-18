Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.



int max(int x,int y)
{
    return x>y?x:y;
}
int maxSubArray(int* nums, int numsSize) {
    int nstart=nums[numsSize-1];
    int nall=nums[numsSize-1];
    for(int i=numsSize-2;i>=0;i--)
    {
        nstart=max(nums[i],nums[i]+nstart);
        nall=max(nstart,nall);
    }
    return nall;
}