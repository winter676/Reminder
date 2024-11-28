// 基本结构
#include<stdio.h>
#include<math.h>
int main()
{
    long long n,maxTimes,temp;
    int Three[1000];
    while(scanf("%lld",&n) != EOF)
    {
        temp = n;
        maxTimes = 0;
        while (temp >= 3)
        {
            Three[maxTimes] = temp % 3;
            maxTimes ++;
            temp /= 3;
        }
        Three[maxTimes] = temp;
        printf("%lld = ",n);
        for (int i = 0; i <= maxTimes; i++ )
        {
            if (Three[i] != 0 && Three[i] != 1)
            {
                printf("%d*3^%d",Three[i],i);
            }
            if (Three[i] == 1)
            {
                printf("3^%d",i);
            }
            if (i != maxTimes && Three[i] != 0)
            {
                printf(" + ");
            }
        }
        printf("\n");

    }
    return 0;
}