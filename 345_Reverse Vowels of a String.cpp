Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".


class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowels;
        string result;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='u' ||s[i]=='i' ||s[i]=='A' || s[i]=='O' || s[i]=='E' || s[i]=='U' ||s[i]=='I')
            {
                vowels.push(s[i]);
            }
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='u' ||s[i]=='i' ||s[i]=='A' || s[i]=='O' || s[i]=='E' || s[i]=='U' ||s[i]=='I')
            {
                char tmp;
                tmp=vowels.top();
                vowels.pop();
                result+=tmp;
            }
            else
            {
                result+=s[i];
            }
        }
        return result;
    }
};