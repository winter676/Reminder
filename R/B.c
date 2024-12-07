#include<stdio.h>
int a[250000];
int main()
{
    int n,k,sum_and ;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++ ){
        scanf("%d",&a[i]);
    }
    for (int i = 30; i >= 0; i-- ){
        int temp = sum_and | (1<<i),isUsed=0,sum_or = 0;
        for (int j = 0; j < n; j++ ){
            sum_or |= a[j];
            if ((sum_or&temp) >= temp ){
                isUsed++;
                sum_or = 0;
            }
            if (isUsed >= k){
                sum_and = temp;
            }
        }
    }

    printf("%d\n",sum_and);
    return 0;
}