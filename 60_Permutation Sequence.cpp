The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.


char* getPermutation(int n, int k) {
    char* result=(char*)malloc(sizeof(char)*(n+1));
    int* num=(int*)malloc(sizeof(int)*n);
    int count=1;
    for(int i=0;i<n;i++)
    {
        num[i]=i+1;
        count*=(i+1);
    }
    k--;
    for(int i=0;i<n;i++)
    {
        count=count/(n-i);
        int selected;
        selected=k/count;
        result[i]='0'+num[selected];
        for(int j=selected;j<n-i-1;j++)
        {
            num[j]=num[j+1];
        }
        k=k%count;
    }
    result[n]='\0';
    return result;
}