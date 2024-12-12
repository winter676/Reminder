#include<stdio.h>

int main()
{
    int k;
    while(scanf("%d",&k) != EOF){
    if (k >= 1){
        printf("No legacy is so rich as honesty.\n");
    }
    if (k >= 2){
        printf("If one loses honesty, he will lose everything.\n");
    }
    if (k == 3){
        printf("I promise I do not cheat in the exam.\n");
    }
    }
    return 0;
}