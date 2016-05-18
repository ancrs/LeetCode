Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.



int myAtoi(char* str) {
    long result = 0;
    int sign = 1;
    //discard the first sequence of whitespace characters.
    while(isspace(*str))
    {
        str++;
    }
    if((*str == '+') || (*str == '-'))
    {
        sign = (*str == '+') ? 1:0;
        str++;
    }
    if(!isdigit(*str))
    {
        return 0;
    }
    while(isdigit(*str) && (result <= INT_MAX))
    {
        result = result * 10 + *str - '0' + 0;
        str++;
    }
    if(result > INT_MAX)
    {
        return sign == 1 ? INT_MAX : INT_MIN;
    }
    return sign == 1 ? result : -result;
}