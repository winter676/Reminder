#include<stdio.h>
#include<string.h>

int main()
{
    char s[150];
    int num = 0,len = 0,judge = 1;
    while (gets(s) != NULL){
        judge = 1;
        len = strlen(s);
        if (s[0] == s[1]){
            for (int i = 2; i < len; i++){
                if (s[i] != s[0]){
                    printf("%d\n",i+1);
                    judge = 0;
                    break;
                }
            }
        }
        if (s[0] != s[1]){
            judge = 0;
            if (s[2] != s[0]){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
        if (judge)
        {
            printf("All characters are the same\n");
        }
    }
}