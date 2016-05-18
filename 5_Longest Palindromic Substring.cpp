Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.



char* longestPalindrome(char* s) {
    int state[1000][1000]={0};
    int i,j,k;
    int length=strlen(s);
    int max=0;
    int flag=0;
    for(i=0;i<length;i++)
    {
        state[i][i]=1;
        max=1;
    }
    for(i=0;i<length-1;i++)
    {
        if(s[i]==s[i+1])
        {
            state[i][i+1]=1;
            flag=i;
            max=2;
        }
    }
    for(k=2;k<length;k++)
    {
        for(i=0;i<length-k;i++)
        {
            j=i+k;
            if(state[i+1][j-1] && s[i]==s[j])
            {
                state[i][j]=1;
                max=j-i+1;
                flag=i;
            }
        }
        
    }
    char* sub=(char*)malloc(sizeof(char)*(max+1));
    memcpy(sub,s+flag,max);
    sub[max]='\0';
    return sub;
    
}