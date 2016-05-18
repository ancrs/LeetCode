Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1


int total(int n)
{
    int sum,i,j,k;
    sum=0;
    while(n>0)
    {
        sum=sum+(n%10)*(n%10);
        n=n/10;
    }
    return sum;
}

bool isHappy(int n) {
    if(n==1)
    {
        return true;
    }
    while(n!=1)
    {
        int tmp;
        tmp=total(n);
        if(tmp == 4 || tmp == 16 || tmp == 37 || tmp == 42 || tmp == 20 || tmp == 58 || tmp == 89 || tmp == 145)
        {
            return false;
        }
        else{
            n=tmp;
        }
    }
    return true;
}