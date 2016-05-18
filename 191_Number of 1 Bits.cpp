Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.



int hammingWeight(uint32_t n) {
    int i,num;
    int a[32]={0};
    for(i=0;i<32 && n>0;i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    num=0;
    for(i=0;i<32;i++)
    {
        if(a[i]==1)
        {
            num++;
        }
    }
    return num;
}