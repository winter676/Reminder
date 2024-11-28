#include<stdio.h>
#include<math.h>
long long C(long long a,long long b);
int main()
{
    int p,q,t,n,m;
    long long num;
    scanf("%d%d%d",&p,&q,&t);
    for (int i = 0; i < t; i++ )
    {
        scanf("%d%d",&n,&m);
        num = 0;
        for (int j = 0; j <= p - m; j++ )
        {
            num += (C(m+j,p)*C(n-m-j,q));
        }
        printf("%lld\n",num);

    }
}

long long C(long long a,long long b)
{
    if (a == 0 || a == b)
    {
        return 1;
    }
    if (a < 0 || b < 0 || a > b) 
    {
        return 0;
    }
    if (a <= b && b >= 0)
    {
        return C(a,b-1) + C(a-1,b-1); 
    }
}