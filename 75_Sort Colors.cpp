Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

void sortColors(int* nums, int numsSize) {
    int i=-1, j=-1, k=-1;

    for(int p = 0; p < numsSize; p++)
    {
        if(nums[p] == 0)
        {
            nums[++k]=2;
            nums[++j]=1;
            nums[++i]=0;
        }
        else if (nums[p] == 1)
        {
            nums[++k]=2;
            nums[++j]=1;

        }
        else if (nums[p] == 2)
        {
            nums[++k]=2;
        }
    }
}