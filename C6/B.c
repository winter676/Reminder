#include<stdio.h>
#include<math.h>
void optiBubSort(long long a[], int n);
int main()
{
    double mid;
    int n;
    long long a[3000];
    scanf("%d",&n);
    for (int i = 0; i < n; i++ )
    {
        scanf("%lld",&a[i]);
    }
    optiBubSort(a,n);
    for (int i = 0; i < n; i++ )
    {
        printf("%lld ",a[i]);
    }
    printf("\n");
    if (n % 2 == 1)
    {
        mid = (double)a[n/2];
    }
    else
    {
        mid = (a[n/2-1]+a[n/2])*1.0/2;
    }
    printf("%.1f\n",mid);
    return 0;
}

void optiBubSort(long long a[], int n)
{
    int i, j, hold, swapFlag;
    for(i=1; i<n; i++) //扫描轮数
    {
        swapFlag = 0;
        for(j=0; j<n-i; j++) //某轮扫描
        {
            if(a[j] > a[j+1])
            {
                swapFlag = 1; // flag1
                hold = a[j];
                a[j] = a[j+1];
                a[j+1] = hold;
            }
        }
        if(swapFlag == 0) // flag0
            break;
    }
}