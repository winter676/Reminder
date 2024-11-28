#include<stdio.h>
int main()
{
    int n;
    long long a,temp = 0;
    scanf("%d",&n);
    scanf("%lld",&a);
    temp = a;
    printf("%lld ",a);
    for (int i =  1; i <n; i++ ){
        scanf("%lld",&a);
        if (a >= temp){
            printf("%lld ",a);
            temp = a;
        }
    }
    printf("\n");
}