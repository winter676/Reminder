#include<stdio.h>
#include<string.h>
char key[10000000];
int main()
{
    int n,num,len;
    char food[10][2000],cNum[10000];
    scanf("%d\n",&n);
    for (int i = 0; i < n; i++ ){
        gets(food[i]);
    }
    
    gets(cNum);
    for (int i = 0; cNum[i] != '\0'; i++ ){
        int num = cNum[i] - '1';
        strcat(key,food[num]);
    }

    len = strlen(key);
    for (int i = len/2; i < len; i++ ){
        printf("%c",key[i]);
    }
    printf("\n");
    return 0;
}
