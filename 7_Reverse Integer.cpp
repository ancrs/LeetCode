Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321



cint reverse(int x) {
    bool negtive = false;

    if(x < 0)
    {
        negtive = true;
        x = -x;
    }

    int result = 0, MAX_DIV_TEN = INT_MAX / 10;
    int tmp;

    while(x)
    {
        if( MAX_DIV_TEN < result)
        {
            return 0;
        }
        result *= 10;
        tmp = x % 10;
        if( INT_MAX - tmp < result)
        {
            return 0;
        }       
        result += tmp;
        x /= 10;
    }

    if(negtive)
    {
        result = -result;
    }    
    return result;
}