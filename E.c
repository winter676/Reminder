#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    unsigned long long n, am=0, bm=0;
    char a[100]={'\0'}, b[100]={'\0'}, ans[64]={'\0'};
    scanf("%llu", &n);
    getchar();
    for (int i=0;i<n;i++)
    {
        scanf("%c", &a[i]);
    }
    getchar();
    for (int i=0;i<n;i++)
    {
        scanf("%c", &b[i]);
    }
    for (int i=0;i<n;i++)
    {
        am=(am*2)+(a[i]-'0');
        bm=(bm*2)+(b[i]-'0');//二进制
    }

    while ((am!=(am^bm))||(bm!=0))
    {
        unsigned long long temp;
        temp=am;
        am=(am^bm);
        bm=((temp&bm)<<1);
    }
    for (int i=0;am!=0;i++)
    {
        ans[i]=((am%2)+2)%2+'0';
        am=am/2;
    }
    int p=0;
    while ((ans[63-p]!='1')&&(63-p>0))
    p++;
    if(p!=63){
    for (int i=63-p;i>=0;i--)
    {
        printf("%c", ans[i]);
    }
    }
    else if(p==63)
    {
        printf("0");
    }
    return 0;
}