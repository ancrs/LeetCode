Implement pow(x, n).



double myPow(double x, int n) {
    if(n==0)
        	return 1.0;
	if(n<0)
		return 1.0 / pow(x,-n);
	double ans = 1.0 ;
	for(;n>0;x*=x,n>>=1)
	{
		if(n&1>0)
			ans *= x;
	}
	return ans;
}