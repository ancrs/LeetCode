Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]'


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) {
    if(!columnSizes) return 0;
    if(!returnSize||numRows==0) return 0;
    int **returnArray=(int **)malloc(numRows*sizeof(int *));
    int *columnSizesArray=malloc(sizeof(int)*numRows);

    *returnSize=0;
    int i=0;
    int j=0;
    for(i=0;i<numRows;i++){
           returnArray[i]=(int *)malloc(sizeof(int)*(i+1));
          //columnSizes[i]=(int *)malloc(sizeof(int)*(1));
          columnSizesArray[i]=i+1;
            for(j=0;j<i+1;j++)
            {
                if(j==0) 
                {
                    returnArray[i][j]=1;
                }else if(j==i)
                {
                    returnArray[i][j]=1;
                }else{
                    returnArray[i][j]=returnArray[i-1][j]+returnArray[i-1][j-1];
                }

            }
            (*returnSize)++;
            //columnSizes[i][0]=(int)(sizeof(returnArray[i]));
        }
    *columnSizes=columnSizesArray;
    return returnArray;
}