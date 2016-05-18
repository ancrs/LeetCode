Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].



/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result=(char**)malloc(sizeof(char*));
    *returnSize=0;
    int s=0,e=0;
    while(s<numsSize)
    {
        if(e+1<numsSize && nums[e+1]==nums[e]+1)
        {
            e++;
        }
        else
        {
            if(s==e)
            {
                (*returnSize)++;
                result=(char**)realloc(result,(*returnSize)*sizeof(char*));
                result[*returnSize-1]=(char*)malloc(12*sizeof(char));
                sprintf(result[*returnSize-1],"%d",nums[e]);
            }
            else if(s<e)
            {
                (*returnSize)++;
                result=(char**)realloc(result,(*returnSize)*sizeof(char*));
                result[*returnSize-1]=(char*)malloc(26*sizeof(char));
                sprintf(result[*returnSize-1],"%d->%d",nums[s],nums[e]);
            }
            s=e+1;
            e=s;
        }
    }
    return result;
}