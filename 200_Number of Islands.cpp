Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3



void dfs(char** grid,int x,int y,int rowsize,int colsize)
{
    if(x<0 || x==rowsize || y<0 || y==colsize)
    {
        return;
    }
    if(grid[x][y]=='1')
    {
        grid[x][y]='2';
        dfs(grid,x+1,y,rowsize,colsize);
        dfs(grid,x-1,y,rowsize,colsize);
        dfs(grid,x,y+1,rowsize,colsize);
        dfs(grid,x,y-1,rowsize,colsize);
    }
}
int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int sum=0;
    for(int i=0;i<gridRowSize;i++)
    {
        for(int j=0;j<gridColSize;j++)
        {
            if(grid[i][j]=='1')
            {
                sum++;
                dfs(grid,i,j,gridRowSize,gridColSize);
                
            }
        }
    }
    return sum;
}