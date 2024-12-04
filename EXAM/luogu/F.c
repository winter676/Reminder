#include<stdio.h>
#include<stdlib.h>
#define M 993244853 ;

long long f(long long n);
int cmp(const void *a ,const void *b);
long long comb_num(long long m, long long n);

long long A[610000];
int main()
{
    long long n,output = 0,start = 0,finish = 0;
    scanf("%lld",&n);
    for (long long i = 0; i < n; i++ ){
        scanf("%lld",&A[i]);
    }
    qsort(A,n,sizeof(long long),cmp);
    while (finish < n){
        while(A[finish] == A[finish+1]){
            finish++;
        }
        output += f(finish-start+1);
        output %= M;
        finish++;
        start = finish;
    }
    printf("%lld\n",output);
}


long long comb_num(long long m, long long n)
{
    if (n == 0 || m == n)
    {
        return 1ll;
    }
    if ( m < n )
    {
        return 0ll;
    }
    if ( n == 1 )
    {
        return m;
    }
    return comb_num(m-1, n) + comb_num(m-1, n-1);
}

int cmp(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b ;			//从小到大排序，不能写成 return a < b 这种形式
}

long long f(long long n)
{
    if ( n <= 1 )
    {
        return 1ll;
    
    }
    return ( n * f(n-1) );
}