Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.

int lengthOfLongestSubstring(char* s) {
    int maxLen = 0;
    int pre = -1;
    int hash[128];
    memset(hash, -1, sizeof(hash));

    int i,c;
    for(i=0; c=s[i]; i++)
    {
        if(pre < hash[c] && hash[c]!=-1)
            pre = hash[c];
        maxLen = maxLen>(i-pre)? maxLen : (i-pre);

        hash[c] = i;
    }

    return maxLen;
}