Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.


bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
        int i =matrixRowSize-1; int j=0;
        int n = matrixRowSize; int m = matrixColSize;
        while(i>=0&&j<m)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]<target)
            {
                j++;
            }
            else
            {
                i--;
            }
        }
        return false;
}