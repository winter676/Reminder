#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int sum = 0;
    char a[1000],b[1000];
    scanf("%s",&a);
    scanf("%s",&b);
    for (int i = 0; i < strlen(a); i++ )
    {
        sum += abs(((int)a[i] - (int)b[i]));
    }
    printf("%d\n",sum);
    return 0;
}