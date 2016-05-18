Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.



bool isIsomorphic(char* s, char* t) {
    if(strlen(s)!=strlen(t))
    {
        return false;
    }
    int table1[128]={0};
    int table2[128]={0};
    for(int i=0;s[i]!='\0';i++)
    {
        char a,b;
        a=s[i];
        b=t[i];
        if(table1[a]==0 && table2[b]==0)
        {
            table1[a]=b;
            table2[b]=a;
        }
        else if(table1[a]!=b)
        {
            return false;
        }
        else if(table2[b]!=a)
        {
            return false;
        }
    }
    return true;
}