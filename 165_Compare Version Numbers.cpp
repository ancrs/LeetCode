Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37


int compareVersion(char* version1, char* version2) {
    int num1=0, num2=0;

    while(1)
    {
        num1=0;
        num2=0;
        while(version1[0]!='.' && version1[0]!='\0')
        {
            num1=num1*10+version1[0]-'0';
            version1++;
        }
        while(version2[0]!='.' && version2[0]!='\0')
        {
            num2=num2*10+version2[0]-'0';
            version2++;
        }
        if(version1[0]=='.') version1++;
        if(version2[0]=='.') version2++;

        if(num1>num2) return 1;
        else if(num2>num1) return -1;
        else if(version1[0]=='\0' && version2[0]=='\0')
        return 0;
    }
}