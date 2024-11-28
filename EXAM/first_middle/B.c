#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ )
    {
        long long num,a,class,y,year,judge = 1;
        scanf("%lld",&num);
        a = num % 1000;
        num /= 1000;
        class = num % 10;
        num /= 10;
        y = num % 100;
        num /= 100;
        year = num;
        if (a == 0)
        {
            printf("Invalid\n");
            continue;
        }
        if (class == 0)
        {
            printf("Invalid\n");
            continue;
        }
        if (y == 0 || y > 43)
        {
            printf("Invalid\n");
            continue;
        }
        if (year < 19 || year > 24)
        {
            printf("Invalid\n");
            continue;
        }
        printf("Valid\n");
    }
}