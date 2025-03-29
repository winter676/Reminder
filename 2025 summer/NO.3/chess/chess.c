#include<stdio.h>

int contion[21][21];

int willWin(int player,int *ooutput_i,int *output_j);
int Check(int i, int j, int player);

int main()
{
    int output_i,output_j;
    for (int i = 0; i < 21; i++ ){
        for (int j = 0; j < 21; j++ ){
            contion[i][j] = 3;
        }
    }
    for (int i = 1; i <= 19; i++ ){
        for (int j = 1; j <= 19; j++ ){
            scanf("%d",&contion[i][j]);
        }
    }
    if (willWin(1,&output_i,&output_j)){
        printf("%d:%d,%d\n",1,output_i,output_j);
    }
    else if (willWin(2,&output_i,&output_j)){
        printf("%d:%d,%d\n",2,output_i,output_j);
    }
    else{
        printf("No\n");
    }
    return 0;
}

int willWin(int player,int *output_i,int *output_j)
{
    for (int i = 1; i <= 19; i++ ){
        for (int j = 1; j <= 19; j++ ){
            if (contion[i][j] == player){
                if(Check(i,j,player)){
                    *output_i = i;
                    *output_j = j;
                    return 1;
                }
            }
            else{
                continue;
            }
        }
    }
    return 0;
}



int Check(int i, int j, int player)
{
    int win = 1;
    //右边
    for (int k = j; k < j+4; k++ ){
        if (contion[i][k] != player){
            win = 0; 
            break;
        }
    }
    if (win){
        if ((contion[i][j-1] == 0) || (contion[i][j+4] == 0)){
            return 1;
        }
    }
    win = 1;

    //下边
    for (int k = i; k < i+4; k++ ){
        if (contion[k][j] != player){
            win = 0; 
            break;
        }
    }
    if (win){
        if (contion[i-1][j] == 0 || contion[i+4][j] == 0){
            return 1;
        }
    }
    win = 1;
    

    //右下
    for (int k = 0; k < 4; k++){
        if (contion[i+k][j+k] != player){
            win = 0; 
            break;
        }
    }
    if (win){
        if (contion[i-1][j-1] == 0 || contion[i+4][j+4] == 0){
            return 1;
        }
    }
    win = 1;

    //左下
    for (int k = 0; k < 4; k++ ){
        if (contion[i+k][j-k] != player){
            win = 0; 
            break;
        }
    }
    if (win){
        if (contion[i+1][j-1] == 0 || contion[i+4][j-4] == 0){
            return 1;
        }
    }
    win = 1;

    
    return 0;
}