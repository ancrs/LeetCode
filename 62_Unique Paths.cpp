A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


int uniquePaths(int m, int n) {
    int num[101]={0};
    for(int i=0;i<n;i++)
    {
        num[i]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            num[j]=num[j]+num[j-1];
        }
    }
    return num[n-1];
}