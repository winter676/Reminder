#include<stdio.h>
int main()
{
    char X;
    int ISBN[20];
    int sum = 0,num;
    scanf("%d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",&ISBN[0],&ISBN[1],&ISBN[2],&ISBN[3],&ISBN[4],&ISBN[5],&ISBN[6],&ISBN[7],&ISBN[8],&X);
    for (int i = 0;  i < 9; i++ ){
        sum += (i+1)*ISBN[i];
    }
    num = sum % 11;
    if ((num == 10 && X == 'X') || (X - '0') == num){
        printf("Right");
    }
    else{
        if (num == 10){
            X = 'X';
        }
        else{
            X = num + '0';
        }
        printf("%d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c\n",ISBN[0],ISBN[1],ISBN[2],ISBN[3],ISBN[4],ISBN[5],ISBN[6],ISBN[7],ISBN[8],X);

    }
}