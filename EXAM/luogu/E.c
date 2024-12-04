#include<stdio.h>
int main()
{
    int n,judge=0,judge2 = 0;
    char temp;
    unsigned long long a = 0,b = 0,past_a,past_b,num,output[100];
    scanf("%d",&n);
    getchar();
    for (int i  = 0; i < n; i++  ){
        scanf("%c",&temp);
        a <<= 1;
        a += (unsigned long long)(temp - '0');
    }
    getchar();
    for (int i  = 0; i < n; i++  ){
        scanf("%c",&temp);
        b <<= 1;
        b += (unsigned long long )(temp - '0');
    }
    past_a = a;
    past_b = b;
    while((a != past_a) || b){
        past_a = a;
        past_b = b;
        a = past_a ^ past_b;
        b = (past_a & past_b)<<1;
    }
    int numout = 0;
    while (a){
        output[numout] = a % 2;
        a /= 2;
        numout++;
        if (output[numout] != 0){
            judge = 1;
        }
    }
    if (judge == 0){
        printf("0");
    }
    else{
        for (int i = numout-1; i >= 0 ;i--){
            if (judge2 == 0 && output[i] == 0){
                continue;
            }
            printf("%llu",output[i]);
            judge2 = 1;
        }
    }
    printf("\n");
}