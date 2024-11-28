#include<stdio.h>
#include<math.h>
void turn(int *a,int *b);
void permute(int *arr, int l, int r);
int a[10] = {1,2,3,4,5,6,7,8,9};
long long max = 0,min = 0,num = 0;
int main()
{
    int n; 
    long long sum=0,num=0;
    scanf("%d",&n);
    permute(a, 0, n-1);
    printf("%lld\n%lld\n%lld",num,min,max);
}


void turn(int *a,int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void permute(int *arr, int l, int r)
{
    if (l == r)
    {
        long long sum = 0;
        for (int i = 0; i <= r; i++)
        {
            sum += arr[i] * pow(10,r-i-1);
        }
        if (sum % 17 == 0)
        {
            num ++;
        }
        if (sum > max)
        {
            max = sum;
        }
        if (sum < min)
        {
            min = sum;
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            turn(&arr[l], &arr[i]);
            permute(arr, l + 1, r);
            turn(&arr[l], &arr[i]); // 回溯
        }
    }
}
























/*for (int i = 0; i < n; i++)
    {
        for ( int j = 0; j < n-1; j++ )
        {
            turn (a[j],a[j+1]);
            for (int k = 0; k < n; k++ )
            {
                sum += a[k] * pow(10,n-k-1);
            }
            if (sum % 17 == 0)
            {
                num++;
            }
        }
    }*/