You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?



void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int** image=(int**)malloc(sizeof(int*)*matrixRowSize);
    for(int i=0;i<matrixRowSize;i++)
    {
        image[i]=(int*)malloc(sizeof(int)*matrixColSize);
    }
    for(int i=0;i<matrixRowSize;i++)
    {
        for(int j=0;j<matrixColSize;j++)
        {
            image[i][j]=matrix[i][j];
        }
    }
    for(int i=0;i<matrixRowSize;i++)
    {
        for(int j=0;j<matrixColSize;j++)
        {
            matrix[i][j]=image[matrixColSize-j-1][i];
        }
    }
}