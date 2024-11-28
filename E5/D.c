#include<stdio.h>
#include<math.h>
double PI_1 (int n);
double PI_2 (int n);
int main()
{
    int T,n;
    double pi_1,pi_2,x;
    scanf("%d",&T);
    for (int i = 0; i < T; i++ )
    {
        scanf("%d",&n);
        pi_1 = PI_1(n);
        pi_2 = PI_2(n);
        x = fabs(pi_1 - pi_2);
        printf("%.6f\n",x);
    }
}

double PI_1 (int n)
{
    int sign = 1;
    double pi=0.0;
    for (int i = 0; i <= n-1; i++ )
    {
        pi += sign*1.0/(2*i+1);
        sign = -sign;
    }
    pi *= 4;
    return pi;
}

double PI_2 (int n)
{
    double pi=0.0;
    for (int i = 0; i <= n-1; i++ )
    {
        pi += 1.0/((2*i+1) * (2*i+1));
    }
    pi = sqrt(8*pi);
    return pi;
}
