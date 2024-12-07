#include<stdio.h>
int main()
{
    unsigned long long a,num = 0;
    scanf("%llu",&a);
    for (int i = 0; i < 64; i++ ){
        if ((a>>i)&1){
            num ++;
        }
    }
    printf("%llu\n",(1ull<<num));
    return 0;
}