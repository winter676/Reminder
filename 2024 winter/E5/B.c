#include<stdio.h>
#include<math.h>
long long inv(long long a, long long p);
int main()
{
    long long n,a,p,x;
    scanf("%lld",&n);
    for (int i = 0; i < n; i++ )
    {
        scanf("%lld%lld",&a,&p);
        x = inv(a,p);
        printf("%lld\n",x);
    }
}

long long inv(long long a, long long p) {
    long long ans = 1, b = p - 2;
    a = (a % p + p) % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % p;
        a = (a * a) % p;
    }
    return ans;
}