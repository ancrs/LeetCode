Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.




int rob(int* nums, int numsSize) {
    if(numsSize==0)
    {
        return 0;
    }
    if(numsSize==1)
    {
        return nums[0];
    }
    if(numsSize==2)
    {
        return nums[0]>nums[1]?nums[0]:nums[1];
    }
    int* dp=(int*)malloc(sizeof(int)*numsSize);
    memset(dp,0,numsSize);
    dp[0]=nums[0];
    for(int i=1;i<numsSize-1;i++)
    {
        if(i==1)
        {
            dp[i]=dp[i-1];
        }
        else{
            dp[i]=(dp[i-1]>(dp[i-2]+nums[i])?dp[i-1]:(dp[i-2]+nums[i]));
        }
    }
    int ans=dp[numsSize-2];
    dp[1]=nums[1];
    for(int i=2;i<numsSize;i++)
    {
        if(i==2)
        {
            dp[i]=nums[i]>nums[i-1]?nums[i]:nums[i-1];
        }
        else{
            dp[i]=(dp[i-1]>(dp[i-2]+nums[i])?dp[i-1]:(dp[i-2]+nums[i]));
        }
    }
    return ans>dp[numsSize-1]?ans:dp[numsSize-1];
}