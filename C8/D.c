#include<stdio.h>
int main()
{
    unsigned int a,b,num,result;
    char op;
    while (scanf("%u %c %u",&a,&op,&b) != EOF){
        num = 0;
        if (op == '&'){
            result = a & b;
        }
        else if (op == '|'){
            result = a | b;
        }
        else {
            result = a ^ b;
        }
        for (int i = 0; i < 32; i++ ){
            if ((result >> i) & 1){
                num ++;
            }
        }
        printf("%u %u\n",result,num);
    }
}