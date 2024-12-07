#include<stdio.h>
int isboom(int a);
int main()
{
    int m,n,k,x,y,boomNum[100][100];
    for (int i = 0; i < 100; i ++){
        for (int j = 0; j < 100; j++ ){
            boomNum[i][j] = 0;
        }
    }

    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < k; i++ ){
        scanf("%d%d",&x,&y);
        boomNum[x][y] = -1;
    }
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (isboom(boomNum[i][j])){
                if (!isboom(boomNum[i-1][j-1]))
                    boomNum[i-1][j-1]++;
                if (!isboom(boomNum[i][j-1]))
                    boomNum[i][j-1]++;
                if (!isboom(boomNum[i+1][j-1]))
                    boomNum[i+1][j-1]++;
                if (!isboom(boomNum[i-1][j]))
                    boomNum[i-1][j]++;
                if (!isboom(boomNum[i+1][j]))
                    boomNum[i+1][j]++;
                if (!isboom(boomNum[i-1][j+1]))
                    boomNum[i-1][j+1]++;
                if (!isboom(boomNum[i][j+1]))
                    boomNum[i][j+1]++;
                if (!isboom(boomNum[i+1][j+1]))
                    boomNum[i+1][j+1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (boomNum[i][j] == -1){
                printf("*");
            }
            else {
                printf("%d",boomNum[i][j]);
            }
        }
        printf("\n");
    }
}


int isboom(int a)
{
    if (a == -1)
    {
        return 1;
    }
    return 0;
}