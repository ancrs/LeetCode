Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.




#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)>(Y)?(Y):(X))
int maxProduct(int* nums, int numsSize) {
    int curmax=nums[0];
    int curmin=nums[0];
    int ans=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        int max=curmax;
        curmax=MAX(MAX(nums[i],nums[i]*curmax),nums[i]*curmin);
        curmin=MIN(MIN(nums[i],max*nums[i]),nums[i]*curmin);
        ans=MAX(ans,curmax);
    }
    return ans;
}