#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,b,errorNum=0;
    double x;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ )
    {
        scanf("%d%d",&a,&b);
        if (a != b)
        {
            errorNum++;
        }
    }
    x = ((1.0*errorNum) / n)*100 ;
    printf("%.1f%\n",x);
}