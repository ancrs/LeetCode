The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.


char* countAndSay(int n) {
    char *pre = calloc(8196, sizeof(char)), *cur = calloc(8196, sizeof(char));
    int i = 1, j, k, ii, pre_len;
    pre[0] = '1';
    for (; i < n; ++i)
    {
        pre_len = strlen(pre);
        pre[pre_len] = '\n'; // add fake char in the end
        pre_len = strlen(pre);
        ii = 0;
        memset(cur, 0x00, 8196 * sizeof(char));
        for (j = 1, k = 1; j < pre_len; ++j)
            if (pre[j] == pre[j-1]) {
                ++k;
            }
            else {
                cur[ii++] = k + '0'; 
                cur[ii++] = pre[j-1];
                k = 1;
            }

        memset(pre, 0x00, 8196 * sizeof(char));
        memcpy(pre, cur, ii * sizeof(char));
    }

    return pre;
}