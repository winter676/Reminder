#include<stdio.h>
#include<stdlib.h>
#define M 993244853
long long numA(long long m, long long n);
long long f(long long n);
long long cmp(const void *a ,const void *b);

long long A[610000];

int main()
{
    long long n,output = 1,judge = 0,numUsed = 0,start = 0,num=1;
    scanf("%lld",&n);
    for (long long i = 0; i < n; i++ ){
        scanf("%lld",&A[i]);
    }
    qsort(A,n,sizeof(long long),cmp);

    while (start < n-1){
        for (int i = start ;i < n -1 && A[i+1] == A[i]; i++){
            num++;
        }
        output *= numA(num,A[start]-numUsed);
        output %= M;
        numUsed += num;
        start += num;
        num = 1;
    }

    printf("%lld\n",output);

    return 0;
}


long long cmp(const void *a ,const void *b)
{
	return *(long long*)a - *(long long *)b ;			//从小到大排序，不能写成 return a < b 这种形式
}

long long f(long long n)
{
    if ( n <= 1 )
    {
        return 1ll;
    
    }
    return ( n * f(n-1) );
}


long long numA(long long m, long long n) {
	long long res = 1;
    for (long long i = 1; i <= m; i++) {
	    res *= n;
	    n--;
        if (res >= M){
            res %= M;
        }
	}
    
    return res;
}