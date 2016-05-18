Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



void quick_sort(int* nums,int l,int r)
{
    if(l<r)
    {
        int i=l,j=r;
        int tmp=nums[i];
        while(i<j)
        {
            while(i<j && nums[j]>=tmp)
            {
                j--;
            }
            if(i<j)
            {
                nums[i]=nums[j];
                i++;
            }
            while(i<j && nums[i]<=tmp)
            {
                i++;
            }
            if(i<j)
            {
                nums[j]=nums[i];
                j--;
            }
        }
        nums[i]=tmp;
        quick_sort(nums,l,i-1);
        quick_sort(nums,i+1,r);
    }
}
int threeSumClosest(int* nums, int numsSize, int target) {
    quick_sort(nums,0,numsSize-1);
    int i,j,k;
    int mindiff=INT_MAX;
    for(i=0;i<numsSize-2;i++)
    {
        int a=nums[i];
        int l=i+1;
        int r=numsSize-1;
        while(l<r)
        {
            int diff=a+nums[l]+nums[r]-target;
            if(diff==0)
            {
                return target;
            }
            if(abs(diff)<abs(mindiff))
            {
                mindiff=diff;
            }
            else
            {
                if(diff>0)
                {
                    r--;
                }
                if(diff<0)
                {
                    l++;
                }
            }
        }
    }
    return mindiff+target;
}