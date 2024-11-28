#include<stdio.h>
//int getMax(int a[][200],int start_n,int n,int start_m,int m);
int main()
{
    int n,m,p,q,A[200][200],max,n_times,m_times;
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for (int i = 0; i < n; i++ )
    {
        for (int j = 0; j < m; j++ )
        {
            scanf("%d",&A[i][j]);
        }
    }
    n_times = n / p;
    m_times = m / q;
    for (int i = 1; i <= n_times; i++ )
    {
        for (int j = 1; j <= m_times; j++ )
        {
            max = A[(i-1)*p][(j-1)*q]; 
            for (int i2 = (i-1)*p; i2 < p*i; i2++)
            {
                for (int j2 = (j-1)*q; j2 < q*j; j2++ )
                {
                    if (max < A[i2][j2])
                    {
                        max = A[i2][j2];
                    }
                }   
            }
            printf("%d ",max);
        }
        printf("\n");
    }
    return 0;
}

/*int getMax(int a[][200],int start_n,int n,int start_m,int m)
{
    int max = 0;
    for (int i = start_n-1; i < n + start_n-1; i++)
    {
        for (int j = start_m-1; j < m + start_m-1; j++ )
        {
            if (max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    return max;
}*/