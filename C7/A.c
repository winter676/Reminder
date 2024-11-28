#include<stdio.h>


int main()
{
    char str[10];
    while(scanf("%s", str) != EOF) {
        if((str[0] == 'O') && (str[1] == 'T') && (str[2] == 'T') && (str[3] == 'E') && (str[4] == 'R') && (str[5] <= '9' && str[5] >= '0') && (str[6] <= '9' && str[6] >= '0') && (str[7] <= '9' && str[7] >= '0')) {
            int num = (str[5] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0');
            if(num >= 0 && num <= 256)
                printf("Valid\n");
            else
                printf("Invalid\n");
        } 
        else
            printf("Invalid\n");
}
}