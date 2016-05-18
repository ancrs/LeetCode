Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].



/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums,int i,int j)
{
    if(i!=j)
    {
        int t=nums[j];
        nums[j]=nums[i];
        nums[i]=t;
    }
    return ;
}
void dfs(int* nums,int index,int size,int** result,int* returnSize)
{
    if(index==size-1)
    {
        (*returnSize)++;
        for(int i=0;i<size;i++)
        {
            result[(*returnSize)-1][i]=nums[i];
        }
        return;
    }
    for(int i=index;i<size;i++)
    {
        swap(nums,i,index);
        dfs(nums,index+1,size,result,returnSize);
        swap(nums,i,index);
    }
}
 
int** permute(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL)
    {
        return NULL;
    }
    int total=1;
    for(int i=1;i<=numsSize;i++)
    {
        total*=i;
    }
    int** result=(int**)malloc(sizeof(int*)*total);
    for(int i=0;i<total;i++)
    {
        result[i]=(int*)malloc(sizeof(int)*numsSize);
    }
    (*returnSize)=0;
    dfs(nums,0,numsSize,result,returnSize);
    return result;
}