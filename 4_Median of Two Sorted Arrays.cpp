There are two sorted arrays nums1 and nums2 of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).


double findKth(int *a, int m, int *b, int n, int k)
{
    //always assume that m is equal or smaller than n
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return a[0]>b[0]?b[0]:a[0];
    //divide k into two parts
    int pa = (k/2)>m?m:(k/2);
    int pb = k - pa;
    if (a[pa - 1] < b[pb - 1])
        return findKth(a + pa, m - pa, b, n, k - pa);
    else if (a[pa - 1] > b[pb - 1])
        return findKth(a, m, b + pb, n - pb, k - pb);
    else
        return a[pa - 1];
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total=nums1Size+nums2Size;
    if((nums1Size+nums2Size)%2==1)
    {
        return findKth(nums1,nums1Size,nums2,nums2Size,total/2+1);
    }
    else
    {
        return (findKth(nums1,nums1Size,nums2,nums2Size,total/2)+findKth(nums1,nums1Size,nums2,nums2Size,total/2+1))/2;
    }
}