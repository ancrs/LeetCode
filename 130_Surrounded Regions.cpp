Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X



//从上下左右四个边界出发找‘O’，联通的都不能被替换
void bfs(char** board,int x,int y,int rowsize,int colsize)
{
    
        board[x][y]='1';
        if(x>1 && board[x-1][y]=='O') bfs(board,x-1,y,rowsize,colsize);
        if(x<rowsize-1 && board[x+1][y]=='O') bfs(board,x+1,y,rowsize,colsize);
        if(y>1 && board[x][y-1]=='O') bfs(board,x,y-1,rowsize,colsize);
        if(y<colsize-1 && board[x][y+1]=='O') bfs(board,x,y+1,rowsize,colsize);
}
void solve(char** board, int boardRowSize, int boardColSize) {
    if(boardRowSize<=2)
    {
        return;
    }
    if(boardColSize<=2)
    {
        return;
    }
    //上
    for(int i=0;i<boardColSize;i++)
    {
        if(board[0][i]=='O')
        {
            bfs(board,0,i,boardRowSize,boardColSize);
        }
    }
    //下
    for(int i=0;i<boardColSize;i++)
    {
        if(board[boardRowSize-1][i]=='O')
        {
            bfs(board,boardRowSize-1,i,boardRowSize,boardColSize);
        }
    }
    //左
    for(int i=1;i<boardRowSize-1;i++)
    {
        if(board[i][0]=='O')
        {
            bfs(board,i,0,boardRowSize,boardColSize);
        }
    }
    //右
    for(int i=1;i<boardRowSize-1;i++)
    {
        if(board[i][boardColSize-1]=='O')
        {
            bfs(board,i,boardColSize-1,boardRowSize,boardColSize);
        }
    }
    for(int i=0;i<boardRowSize;i++)
    {
        for(int j=0;j<boardColSize;j++)
        {
            if(board[i][j]=='1')
            {
                board[i][j]='O';
            }
            else if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
}