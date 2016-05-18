Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.


void merge(int* nums1, int m, int* nums2, int n) {
    int id1,id2;
    id1=m-1;
    id2=n-1;
    while(id1>=0 && id2>=0)
    {
        if(nums1[id1]<nums2[id2])
        {
            nums1[id1+id2+1]=nums2[id2];
            id2--;
        }
        else
        {
            nums1[id1+id2+1]=nums1[id1];
            id1--;
        }
    }
    while(id2>=0)
    {
        nums1[id2]=nums2[id2];
        id2--;
    }
}