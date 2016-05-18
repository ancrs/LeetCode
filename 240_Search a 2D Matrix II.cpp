Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.



bool search(int** matrix,int x,int y,int rowsize,int target)
{
    if(y<0 || x==rowsize)
    {
        return false;
    }
    if(matrix[x][y]==target)
    {
        return true;
    }
    else if(matrix[x][y]<target)
    {
        return search(matrix,x+1,y,rowsize,target);
    }
    else if(matrix[x][y]>target)
    {
        return search(matrix,x,y-1,rowsize,target);
    }
}
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return search(matrix,0,matrixColSize-1,matrixRowSize,target);
}