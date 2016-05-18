Given an array of integers, every element appears twice except for one. Find that single one.



int singleNumber(int* nums, int numsSize) {
    if(nums==NULL || numsSize==0)
    {
        return 0;
    }
    int single=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        single=single^nums[i];
    }
    return single;
}