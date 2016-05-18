A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.



int numDecodings(char* s) {
    int n=strlen(s);
    int* nums=(int*)malloc(sizeof(int)*(n+1));
    memset(nums,0,n+1);
    nums[0]=1;
    if(n==0)
    {
        return 0;
    }
    if(s[0]=='0')
    {
        nums[1]=0;
    }
    else{
        nums[1]=1;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]!='0')
        {
            nums[i+1]+=nums[i];
        }
        if(s[i-1]!='0' && ((s[i-1]-'0')*10+(s[i]-'0'))<=26)
        {
            nums[i+1]+=nums[i-1];
        }
        
    }
    return nums[n];
}