Description:

Count the number of prime numbers less than a non-negative number, n.



int countPrimes(int n) {
    int count,i;
    count=0;
    int* flag=(int*)malloc(sizeof(int)*n);
    for(i=2;i<n;i++)
    {
        flag[i]=1;
    }
    for (i = 2; i * i < n; i++) {
      if (!flag[i]) continue;
      for (int j = i * i; j < n; j += i) {
         flag[j] = 0;
      }
   }
   for (int i = 2; i < n; i++) {
      if (flag[i]) count++;
   }
    return count;
}