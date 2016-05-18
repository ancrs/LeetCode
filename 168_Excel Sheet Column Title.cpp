Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 


    char* convertToTitle(int n) {
    char *res = (char *)calloc(8, sizeof(char));
    int i = 6;
    while(n){
        res[i--] = (char)((n-1) % 26) + 'A';
        n = (n - 1) / 26;
    }
    return res+i+1;
}