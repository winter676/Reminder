#include<stdio.h>

#define MOD 998244353
long long fib[1000000];
int main()
{
    long long a,b,t,n,A,B ,temp;
    scanf("%lld%lld",&a,&b);
    A = a % MOD;
    B = b % MOD;
    fib[0] = (a + b) % MOD;
    for (int i = 1; i < 1000000; i++ )
    {
        temp = A;
        A = (A + B) % MOD;
        B = temp;
        fib[i] = (A + B) % MOD;
    }

    scanf("%lld",&t);
    for (int i = 0; i < t ; i++ )
    {
        scanf("%lld",&n);
        printf("%lld\n",fib[n-1]);
    }
    return 0;
}
