Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.


bool isAnagram(char* s, char* t) {
    int i;
    int count[26]={0};
    while(*s != '\0')
    {
        count[*s - 'a']++;
        s++;
    }
    while(*t != '\0')
    {
        count[*t - 'a']--;
        t++;
    }
    for(i=0;i<26 && count[i]==0;i++)
    {}
    return i==26;
}