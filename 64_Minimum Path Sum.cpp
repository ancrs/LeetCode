Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.


int min(int x,int y)
{
    return x>=y?y:x;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int **sum=(int**)malloc(sizeof(int*)*gridRowSize);
    for(int i=0;i<gridRowSize;i++)
    {
        sum[i]=(int*)malloc(sizeof(int)*gridColSize);
    }
    sum[0][0]=grid[0][0];
    for(int i=1;i<gridColSize;i++)
    {
        sum[0][i]=grid[0][i]+sum[0][i-1];
    }
    for(int i=1;i<gridRowSize;i++)
    {
        sum[i][0]=grid[i][0]+sum[i-1][0];
    }
    for(int i=1;i<gridRowSize;i++)
    {
        for(int j=1;j<gridColSize;j++)
        {
            sum[i][j]=grid[i][j]+min(sum[i-1][j],sum[i][j-1]);
        }
    }
    return sum[gridRowSize-1][gridColSize-1];
}