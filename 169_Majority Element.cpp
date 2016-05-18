Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.



int majorityElement(int* nums, int numsSize) {
    int i,j,sum=0;
    j=nums[0];
    for(i=0;i<numsSize;i++)
    {
        if(sum==0)
        {
            j=nums[i];
        }
        if(j==nums[i])
        {
            sum++;
        }
        else
        {
            sum--;
        }
    }
    return j;
}