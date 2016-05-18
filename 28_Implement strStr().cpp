Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


int strStr(char* haystack, char* needle) {
    int lena,lenb;
    lena=strlen(haystack);
    lenb=strlen(needle);
    int i;
    if((lena==0 && lenb==0) || lenb==0 || haystack==needle)
    {
        return 0;
    }
    for(i=0;i<=lena-lenb;i++)
    {
        if(haystack[i]==needle[0])
        {
            if(strncmp(haystack+i,needle,lenb)==0)
            {
                return i;
            }
        }
    }
    return -1;
}