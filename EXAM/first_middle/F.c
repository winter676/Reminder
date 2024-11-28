#include<stdio.h>
#include<math.h>
int main()
{
    long long n,c,k,t,m,coldTime=0,sum=0,isCold=0;
    scanf("%lld%lld%lld",&n,&c,&k);
    for (int i = 0; i < n; i++ )
    {
        scanf("%lld%lld",&t,&m);
        if (t <= coldTime && isCold)
        {
            continue;
        }
        else
        {
            isCold = 0;
            if (m >= k)
            {
                coldTime = t + c;
                isCold = 1;
            }
            sum += m;
        }
    }
    printf("%lld\n",sum);
}