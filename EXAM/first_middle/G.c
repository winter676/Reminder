#include<stdio.h>
int main()
{
    long long L,R,num,temp;
    long long times[10] = {},maxTimes=0,maxnum;
    scanf("%lld%lld",&L,&R);
    //统计每个数出现次数 
    for (long long i = L; i <= R; i++ )
    {
        temp = i;
        while(temp != 0)
        {
            num = temp % 10;
            times[num]++;
            temp /= 10;
        }
    }
    //统计最大数目
    for (long long i = 0; i < 10; i++)
    {
        if (maxTimes < times[i])
        {
            maxTimes = times[i];
            maxnum = i;
        }
    }

    for (long long i = maxTimes; i > 0; i--)
    {
        for (int j = 0; j < 10; j++ )
        {
            if (times[j] >= i)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("- - - - - - - - - -\n");
    printf("0 1 2 3 4 5 6 7 8 9\n");
    printf("MAXNUM=%lld\n",maxnum);
    return 0;
}