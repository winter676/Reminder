#include<stdio.h>
#include<string.h>

int main(){
    int pointIndex=0 ,len,numofzero=1,unzeroindex;
    char num[200];
    fgets(num,200,stdin);
    len = strlen(num);
    num[len-1] = '\0';
    len -= 1;
    for (int i = 0; i < len; i++){
        if (num[i] == '.'){
            pointIndex = i;
            break;
        }
    }
    if (pointIndex == 1){
        if (num[0] != '0'){
            for (int i = 0; i < len; i++ ){
                printf("%c",num[i]);
            }
            printf("e0\n");
        }
        else{
            for (int i = 2; i < len;i++){
                if (num[i] != '0'){
                    unzeroindex = i;
                    break;
                }
                numofzero++;
            }
            printf("%c",num[unzeroindex]);
            for (int i = unzeroindex+1;i <len;i++){
                if(i == unzeroindex+1){
                    printf(".");
                }
                printf("%c",num[i]);
            }
            printf("e-%d\n",numofzero);
        }
    }
    else if (pointIndex == 0){
        printf("%c.",num[0]);
        for (int i = 1; i < len; i++ ){
            printf("%c",num[i]);
        }
        printf("e%d\n",len-1);
    }
    else{
        printf("%c.",num[0]);
        for (int i = 1; i < len; i++ ){
            if (i == pointIndex){
                continue;
            }
            printf("%c",num[i]);
        }
        printf("e%d\n",pointIndex-1);
    }
    return 0;
}