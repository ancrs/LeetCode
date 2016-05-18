Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?


uint32_t reverseBits(uint32_t n) {
    if(n==0)
    {
        return 0;
    }
    int a[32]={0};
    int i,j,k;
    for(i=0;i<32 && n>0;i++)
    {
            a[i]=n%2;
            n=n/2;
    }
    uint32_t m;
    m=0;
    for(i=0;i<32;i++)
    {
        if(a[i]!=0)
        {
            k=i;
            break;
        }
    }
    for(j=k;j<31;j++)
    {
        m=m+a[j];
        m=m*2;
    }
    m=m+a[j];
    return m;
}