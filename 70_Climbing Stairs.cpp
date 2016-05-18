You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



int climbStairs(int n) {
    int i,a1,a2,ans;
    if(n<=0)
    {
        return 1;
    }
    if(n==1)
    {
        return 1;
    }
    if(n==2)
    {
        return 2;
    }
    a1=1;
    a2=2;
    for(i=3;i<=n;i++)
    {
        ans=a1+a2;
        a1=a2;
        a2=ans;
    }
    return ans;
}