Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].



void rotate(int* nums, int numsSize, int k) {
    k=k%numsSize;
    int a[numsSize];
    int j=0;
    if(k!=0)
    {
    for(int i=numsSize-k;i<numsSize;i++,j++)
    {
        a[j]=nums[i];
    }
    for(int i=numsSize-k-1;i>=0;i--)
    {
        nums[i+k]=nums[i];
    }
    for(int i=0;i<k;i++)
    {
        nums[i]=a[i];
    }
    }
}