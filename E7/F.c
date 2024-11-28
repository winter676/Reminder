#include<stdio.h>
#include<string.h>
void turnMatrix(char A[3500][3500],int n,int hang,int times);
char A[3500][3500], B[3500][3500];
int main()
{
    int n,times;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++ ){
        gets(A[i]);
        for (int j = 0; j  < n;j++ ){
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n/2; i++ ){
        times = (i+1)%4;
        turnMatrix(A,n,i+1,times);
    }
    for (int i = 0; i < n; i++ ){
        for (int j = 0; j < n; j++ ){
            printf("%c",A[i][j]);
        }
        printf("\n");
    }

}


void turnMatrix(char A[3500][3500],int n,int hang,int times)
{
    char top[3500];
    for (int j = 0; j < times; j++){
        int num = n - hang;
        for (int i = hang-1; i < num ; i++ ){
            top[i] = A[hang-1][i];
            A[hang-1][i] = A[n-i-1][hang-1];
            A[n-i-1][hang-1] =  A[n-hang][n-i-1];
            A[n-hang][n-i-1] = A[i][n-hang];
        }
        for (int i = hang-1; i < num; i++ ){
            A[i][n-hang] = top[i];
        }
    }
    return ;
}