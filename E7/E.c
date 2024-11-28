#include<stdio.h>
#include<string.h>

void checkToPut(int a);
int main ()
{
    int len,num = 0,output[200],sum;
    char input[200];
    char *p1 = NULL,*p2 = NULL;

    while (scanf("%s",input) != EOF){
        len = strlen(input);
        p1 = input;
        p2 = input;

        while (*p1 && (*p1 < '0' || *p1 > '9')) {
            p1++;
        }

        while (*p2 && (*p2 >= '0' && *p2 <= '9')) {
            p2++;
        }
        while ( *p1 || *p2){
            sum = 0;
            if (p1 < p2 && *p1){
                while (p1 < p2 && *p1 >= '0'){
                   sum *= 10;
                   sum += (int) (*p1-'0');
                   p1++;
                }
                output[num] = sum;
                num++;
                while ((*p1 < '0' || *p1 > '9') && *p1){
                    p1 ++;
                }
            }
            else{
                while (p2 < p1 && (*p2 < '0' || *p2 > '9')){
                    sum += p2;
                    p2++;
                }
                output[num] = -sum;
                num++;
                while (*p2 && (*p2 >= '0' && *p2 <= '9') ){
                    p2 ++;
                }
            }
        }
        for (int i = 0; i < num ;i ++ ){
            checkToPut(output[i]);
        }
        printf("\n");
        num = 0;
    }
    return 0;
}

void checkToPut(int a)
{
    if (a <= 0){
            printf("%d",-a);
        }
        else{
            printf("%c",(char)a);
        }
}