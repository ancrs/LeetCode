Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums,int i,int j)
{
    if(i!=j)
    {
        int t;
        t=nums[j];
        nums[j]=nums[i];
        nums[i]=t;
    }
}
bool next(int* nums,int i,int index)
{
    for(int k=index;k<i;k++)
    {
        if(nums[i]==nums[k])
        {
            return true;
        }
    }
    return false;
}
void dfs(int* nums,int index,int size,int** result,int* resultSize)
{
    if(index==size-1)
    {
        (*resultSize)++;
        result[(*resultSize)-1]=(int*)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++)
        {
            result[(*resultSize)-1][i]=nums[i];
        }
    }
    for(int i=index;i<size;i++)
    {
        if(next(nums,i,index))
        {
            continue;
        }
        swap(nums,i,index);
        dfs(nums,index+1,size,result,resultSize);
        swap(nums,i,index);
    }
}
 
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL)
    {
        return NULL;
    }
    int total=1;
    for(int i=0;i<numsSize;i++)
    {
        total*=i;
    }
    (*returnSize)=0;
    int** result=(int**)malloc(sizeof(int*)*10000);
    dfs(nums,0,numsSize,result,returnSize);
    return result;
}