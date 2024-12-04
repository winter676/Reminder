#include<stdio.h>
int main()
{
    int n;
    char temp;
    long long a = 0,b = 0,past_a,past_b,num,output[100];

    scanf("%d",&n);
    getchar();
    num = (1 << n)-1;
    for (int i  = 0; i < n; i++  ){
        scanf("%c",&temp);
        a <<= 1;
        a += (long long)(temp - '0');
    }
    getchar();
    for (int i  = 0; i < n; i++  ){
        scanf("%c",&temp);
        b <<= 1;
        b += (long long )(temp - '0');
    }
    past_a = a;
    past_b = b;
    while((a != past_a) || b){
        past_a = a;
        past_b = b;
        a = past_a ^ past_b;
        b = (past_a & past_b)<<1;
        b = b & num; 
    }
    int numout = 0;
    while (a){
        output[numout] = a % 2;
        a /= 2;
        numout++;
    }
    for (int i = numout-1; i >= 0 ;i--){
        printf("%lld",output[i]);
    }
    if (numout == 0){
        printf("0");
    }
    printf("\n");
}