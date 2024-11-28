#include<stdio.h>
#include<string.h>
int main()
{
    char a[10000];
    gets(a);
    if (!strcmp(a , "If one loses honesty, he will lose everything.")){
        printf("I promise I do not cheat in the exam.\n");
    }
    else if (!strcmp(a , "I promise I do not cheat in the exam.")){
        printf("If one loses honesty, he will lose everything.\n");
    }
}