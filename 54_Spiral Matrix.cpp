Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void print(int** matrix,int x,int y,int row,int col,int* result,int* num)
{
    if(row<=0 || col<=0)
    {
        return;
    }
    for(int i=0;i<col;i++)
    {
        result[(*num)]=matrix[x][y+i];
        (*num)++;
    }
    for(int i=1;i<row-1;i++)
    {
        result[(*num)]=matrix[x+i][y+col-1];
        (*num)++;
    }
    if(row>1)
    {
    for(int i=col-1;i>=0;i--)
    {
        result[(*num)]=matrix[row-1+x][i+y];
        (*num)++;
    }
    }
    if(col>1)
    {
    for(int i=row-2;i>=1;i--)
    {
        result[(*num)]=matrix[i+x][y];
        (*num)++;
    }
    }
    print(matrix,x+1,y+1,row-2,col-2,result,num);
}
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    
    if(matrixRowSize==0 && matrixColSize==0)
    {
        return NULL;
    }
    int* result=(int*)malloc(sizeof(int)*matrixRowSize*matrixColSize);
    int num=0;
    print(matrix,0,0,matrixRowSize,matrixColSize,result,&num);
}