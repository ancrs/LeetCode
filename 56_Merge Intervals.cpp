Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quick_sort(struct Interval* intervals,int left,int right)
{
    int i=left;
    int j=right;
    struct Interval tmp=intervals[i];
    if(left<right)
    {
        while(i<j)
        {
            while(i<j && intervals[j].start>=tmp.start)
            {
                j--;
            }
            if(i<j)
            {
                intervals[i]=intervals[j];
                i++;
            }
            while(i<j && intervals[i].start<=tmp.start)
            {
                i++;
            }
            if(i<j)
            {
                intervals[j]=intervals[i];
                j--;
            }
        }
        intervals[i]=tmp;
        quick_sort(intervals,left,i-1);
        quick_sort(intervals,i+1,right);
    }
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if(intervalsSize==0 || intervalsSize==1)
    {
        *returnSize=intervalsSize;
        return intervals;
    }
    quick_sort(intervals,0,intervalsSize-1);
    *returnSize=0;
    int start=intervals[0].start;
    int end=intervals[0].end;
    for(int i=1;i<intervalsSize;i++)
    {
        if(intervals[i].start>=start && intervals[i].start<=end)
        {
            end=end>intervals[i].end?end:intervals[i].end;
        }
        else
        {
            (*returnSize)++;
            intervals[(*returnSize)-1].start=start;
            intervals[(*returnSize)-1].end=end;
            start=intervals[i].start;
            end=intervals[i].end;
        }
    }
    (*returnSize)++;
    intervals[(*returnSize)-1].start=start;
    intervals[(*returnSize)-1].end=end;
    return intervals;
}