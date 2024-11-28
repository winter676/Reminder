#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long m;
    scanf("%llu",&m);
    int judge[100],num = 0,x[100]={},new_x[100];
    for (int i = 0; i < 64; i++ )
    {
        judge[i] = ((m>>i)&1);
        x[i] = judge[i];
        //printf("%d\n",judge[i]);
    }
    //找出i
    if (x[0])
    {
        judge[0] ^= 1;
        judge[1] ^= 1;
    }
    for (int i = 1; i < 63; i++ )
    {
        if (x[i])
        {
            judge[i-1] ^= 1;
            judge[i+1] ^= 1;
            judge[i] ^= 1;
        }
    }
    if (x[63])
    {
        judge[63] ^= 1;
        judge[62] ^= 1;
    }
    for (int i = 0; i < 64; i++ )
    {
        if (judge[i])
        {
            num++;
            new_x[num-1] = i;
        }
    }
    printf("%d\n",num);
    for (int i = num -1; i >= 0; i--)
    {
        printf("%d ",new_x[i]);
    }
}