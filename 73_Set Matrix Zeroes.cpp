Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.


void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    bool firstrow=false;
    bool firstcol=false;
    for(int i=0;i<matrixColSize;i++)
    {
        if(matrix[0][i]==0)
        {
            firstrow=true;
            break;
        }
    }
    for(int i=0;i<matrixRowSize;i++)
    {
        if(matrix[i][0]==0)
        {
            firstcol=true;
            break;
        }
    }
    for(int i=1;i<matrixRowSize;i++)
    {
        for(int j=1;j<matrixColSize;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
    }
    for(int i=1;i<matrixColSize;i++)
    {
        if(matrix[0][i]==0)
        {
            for(int j=1;j<matrixRowSize;j++)
            {
                matrix[j][i]=0;
            }
        }
    }
    for(int i=1;i<matrixRowSize;i++)
    {
        if(matrix[i][0]==0)
        {
            for(int j=1;j<matrixColSize;j++)
            {
                matrix[i][j]=0;
            }
        }
    }
    if(firstrow==true)
    {
        for(int i=0;i<matrixColSize;i++)
        {
            matrix[0][i]=0;
        }
    }
    if(firstcol==true)
    {
        for(int i=0;i<matrixRowSize;i++)
        {
            matrix[i][0]=0;
        }
    }
}