#include<stdio.h>
#include<math.h>
int main()
{
    int n,A[2000],B[2000];
    long long sum = 0;
    while (scanf("%d",&n) != EOF)
    {
        sum = 0;
        for (int i = 0; i < n; i++ )
        {
            scanf("%d",&A[i]);
        }
        for (int i = 0; i < n; i++ )
        {
            scanf("%d",&B[i]);
        }
        for (int i = 0; i < n; i++ )
        {
            sum += (A[i]*B[n-1-i]);
        }
        printf("%lld\n",sum);
        
    }
    return 0;
}

/*void new( int A[],int B[],int n)
{
    long long sum=0;
    for (int i = 0; i < n; i++ )
    {
        sum += (A[i]*B[n-1-i]);
    }
    printf("%lld\n",sum);
    return;
}*/