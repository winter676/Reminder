#include<stdio.h>
#include<string.h>
int arrowjudge(char S[],int n);
int allis(char S[],int a,int b);
int main()
{
    int n,judge;
    char S[150];
    while (gets(S) != NULL){
        n = strlen(S);
        judge = arrowjudge(S,n);
        if (judge == 0){
            printf("Not an Arrow\n");
        }
        if (judge == 1){
            printf("Left Arrow\n");
        }
        if (judge == 2){
            printf("Right Arrow\n");
        }
        if (judge == 3){
            printf("Bidirectional Arrow\n");
        }
    }
    return 0;
}


int arrowjudge(char S[],int n)
{
    if (S[0] == '<' && allis(S,1,n-1)){
        return 1;
    }
    else if (S[n-1] == '>' && allis(S,0,n-2)){
        return 2;
    }
    else if (S[0] == '<' && S[n-1] == '>' && allis(S,1,n-2)){
        return 3;
    }
    else {
        return 0;
    }
}


int allis(char S[],int a,int b)
{
    for (int i = a; i <= b; i++ ){
        if (S[i] != '='){
            return 0;
        }
    }
    return 1;
}