// main.c
#include <stdio.h>
#include "operation.h"
 
int main() {
    int a , b;
    printf("请输入两个值：");
    scanf("%d%d",&a,&b);
 
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division: %d / %d = %d\n", a, b, divide(a, b));
 
    return 0;
}