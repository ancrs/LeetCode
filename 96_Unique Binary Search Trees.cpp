Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3



int numTrees(int n) {
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    int* nums=(int*)malloc(sizeof(int)*(n+1));
    memset(nums,0,n+1);
    nums[0]=1;
    nums[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            nums[i]+=nums[j-1]*nums[i-j];
        }
    }
    return nums[n];
}   