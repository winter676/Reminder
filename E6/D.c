#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,p,A[200][200],B[200][200],C[200][200] = {};
    scanf("%d%d%d",&n,&m,&p);
    for (int i = 0; i < n; i++ )
    {
        for (int j = 0; j < m; j++ )
        {
            scanf("%d",&A[i][j]);
        }
    }
    for (int i = 0; i < m; i++ )
    {
        for (int j = 0; j < p; j++ )
        {
            scanf("%d",&B[i][j]);
        }
    }
    for (int i = 0; i < n; i++ )
    {
        for (int j = 0; j < p ; j++ )
        {
            C[i][j]  = 0;
            for (int k = 0; k < m; k++ )
            {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++ )
    {
        for (int j = 0; j < p ; j++ )
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}