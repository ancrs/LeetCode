Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]



/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void print(int** matrix,int x,int y,int row,int col,int* num)
{
    if(row<=0 || col<=0)
    {
        return;
    }
    for(int i=0;i<col;i++)
    {
        matrix[x][y+i]=*num;
        (*num)++;
    }
    for(int i=1;i<row-1;i++)
    {
        matrix[x+i][y+col-1]=*num;
        (*num)++;
    }
    if(row>1)
    {
    for(int i=col-1;i>=0;i--)
    {
        matrix[row-1+x][i+y]=*num;
        (*num)++;
    }
    }
    if(col>1)
    {
    for(int i=row-2;i>=1;i--)
    {
        matrix[i+x][y]=*num;
        (*num)++;
    }
    }
    
    
    
    print(matrix,x+1,y+1,row-2,col-2,num);
}
int** generateMatrix(int n) {
    if(n==0)
    {
        return NULL;
    }
    int** result=(int*)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    {
        result[i]=(int*)malloc(sizeof(int)*n);
    }
    int num;
    num=1;
    print(result,0,0,n,n,&num);
    return result;
}