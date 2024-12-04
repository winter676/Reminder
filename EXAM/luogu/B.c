#include<stdio.h>
#include<string.h>
int main()
{
    int num = 0,temp;
    char s[10];
    gets(s);
    num = strlen(s);
    temp = num;
    for (int i = 0;  i < temp; i ++ ){
        if (s[i] == ' '){
            num--;
        }
    }
    printf("%d\n",num);

}