Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.



int lengthOfLastWord(char* s) {
    int len=strlen(s);
    int i,count;
    if(s==NULL)
    {
        return 0;
    }
    count=0;
    for(i=len-1;i>=0;i--)
    {
        if(s[i]==' ' && count==0)
        {
            continue;
        }
        if(s[i]==' ' && count!=0)
        {
            break;
        }
        count++;;
    }
    return count;
}