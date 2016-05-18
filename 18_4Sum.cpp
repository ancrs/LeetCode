Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)



/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
 
 
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int** set=(int**)malloc(sizeof(int*));
    (*returnSize)=0;
    if(nums==NULL || numsSize==0)
    {
        return set;
    }
    quick_sort(nums,0,numsSize-1);
    int i,j,k;
    for(i=0;i<numsSize-3;i++)
    {
        int a=nums[i];
        for(j=i+1;j<numsSize-2;j++)
        {
            int b=nums[j];
            int l=j+1;
            int r=numsSize-1;
            while(l<r)
            {
                if(nums[l]+nums[r]+a+b<target)
                {
                l++;
                }
            else if(nums[l]+nums[r]+a+b>target)
                {
                r--;
                }
            else if(nums[l]+nums[r]+a+b==target)
            {
                for(k=0;k<(*returnSize);k++)
                {
                    if(a==set[k][0] && b==set[k][1] && nums[l]==set[k][2])
                    {
                        break;
                    }
                }
                if(k<(*returnSize))
                {
                    l++;
                    continue;
                }
                
                (*returnSize)++;
                set=(int**)realloc(set,sizeof(int*)*(*returnSize));
                set[(*returnSize)-1]=(int*)malloc(sizeof(int)*4);
                set[(*returnSize)-1][0]=a;
                set[(*returnSize)-1][1]=b;
                set[(*returnSize)-1][2]=nums[l];
                set[(*returnSize)-1][3]=nums[r];
                l++;
            }
           }
        }
    }
    return set;
}