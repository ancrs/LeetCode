Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* sum=(int*)malloc(sizeof(int)*(digitsSize+1));
    int k=1;
    for(int i=digitsSize-1;i>=0;i--)
    {
        sum[i+1]=(digits[i]+k)%10;
        k=(digits[i]+k)/10;
    }
    if(sum[1]==0)
    {
        sum[0]=1;
        *returnSize=digitsSize+1;
        return sum;
    }
    else
    {
        *returnSize=digitsSize;
        return sum+1;
    }
}