#include<stdio.h>
#include<math.h>
int main()
{
    int n,sum,numround,A[100]={0,1},B[100]={0};
    sacnf("%d",&n);
    if (n & 1)//奇数 
    {

    }
    else
    {
        sum = 1 + n;
        numround = n-1;
        for (int i = 1; i <= n/2; i++ )
        {
            A[i] = i;
            B[i] = sum - i;
        }
        for (int j = 1; j <= numround; j++)
        {
            printf("Round %d\n",j);
            
            for (int k = 1; k <= n/2; k++ )
            {
                printf("%d-%d\n",A[k],B[k]);
            }
        }
    }
    return 0;
}