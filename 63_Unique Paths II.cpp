Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.



int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int num[101][101];
    int flag=1;
    for(int i=0;i<obstacleGridColSize;i++)
    {
        if(obstacleGrid[0][i]==1)
        {
            flag=0;
        }
        num[0][i]=flag;
    }
    flag=1;
    for(int i=0;i<obstacleGridRowSize;i++)
    {
        if(obstacleGrid[i][0]==1)
        {
            flag=0;
        }
        num[i][0]=flag;
    }
    for(int i=1;i<obstacleGridRowSize;i++)
    {
        for(int j=1;j<obstacleGridColSize;j++)
        {
            if(obstacleGrid[i][j]==1)
            {
                num[i][j]=0;
            }
            else{
                num[i][j]=num[i][j-1]+num[i-1][j];
            }
        }
    }
    return num[obstacleGridRowSize-1][obstacleGridColSize-1];
}