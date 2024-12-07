#include<stdio.h>
#include<math.h>
int max(int a,int b);
int d(unsigned int a,unsigned int b);
int main()
{
    unsigned int x1,x2,x3,x4,x5,result;
    while (scanf("%u%u%u%u%u",&x1,&x2,&x3,&x4,&x5) != EOF)
    {
        result = max(d(x1,x2),d(x1,x3))  + max(d(x2,x4),d(x3,x4)) + max(d(x3,x5),d(x4,x5));
        printf("%u\n",result);
    }
}

int d(unsigned int a,unsigned int b)
{
    int num=0;
    for (int i = 0; i < 32; i++ )
    {
        if ((((a>>i) ^ (b>>i)) & 1) == 1)
        {
            num ++;
        }
    }
    return num;
}

int max(int a,int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}