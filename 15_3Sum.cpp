Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void quick_sort(int* nums,int l,int r)
 {
     if(l<r)
     {
         int i=l,j=r;
         int x=nums[i];
         while(i<j)
         {
             while(i<j && nums[j]>=x)
             {
                 j--;
             }
             if(i<j)
             {
                 nums[i]=nums[j];
                 i++;
             }
             while(i<j && nums[i]<=x)
             {
                 i++;
             }
             if(i<j)
             {
                 nums[j]=nums[i];
                 j--;
             }
         }
         nums[i]=x;
         quick_sort(nums,l,i-1);
         quick_sort(nums,i+1,r);
     }
 }
 
int** threeSum(int* nums, int numsSize, int* returnSize) {
    int** set=(int**)malloc(sizeof(int*));
    quick_sort(nums,0,numsSize-1);
    *returnSize=0;
    if(nums==NULL || numsSize==0)
    {
        return set;
    }
    int i,j,k;
    for(i=0;i<numsSize-2 && nums[i]<=0;i++)
    {
        int target=nums[i];
        int l=i+1;
        int r=numsSize-1;
        while(l<r)
        {
            if(nums[l]+nums[r]+target<0)
            {
                l++;
            }
            else if(nums[l]+nums[r]+target>0)
            {
                r--;
            }
            else if(nums[l]+nums[r]+target==0)
            {
                for(k=0;k<(*returnSize);k++)
                {
                    if(target==set[k][0] && nums[l]==set[k][1])
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
                set[(*returnSize)-1]=(int*)malloc(sizeof(int)*3);
                set[(*returnSize)-1][0]=target;
                set[(*returnSize)-1][1]=nums[l];
                set[(*returnSize)-1][2]=nums[r];
                l++;
            }
        }
    }
    return set;
}