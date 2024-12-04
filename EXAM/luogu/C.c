#include<stdio.h>

int main()
{
    int n,na,nb,A[150],B[150],Awin=0,Bwin=0;
    scanf("%d%d%d",&n,&na,&nb);
    for (int i = 1; i <= na; i++ ){
        scanf("%d",&A[i]);
    }
    for (int i = 1; i <= nb; i++ ){
        scanf("%d",&B[i]);
    }
    for (int i = 1; i <= n; i++ ){
        int as , bs ;
        if (i % na == 0){
            as = A[na];
        }
        else{
            as = A[i % na];
        }
        if (i % nb == 0){
            bs = B[nb];
        }
        else{
            bs = B[i % nb];
        }
        if (as == bs){
            continue;
        }
        else if ((as == 0 && bs == 2) || (as == 2 && bs == 5) || (as == 5 && bs == 0)){
            Awin++;
        }
        else{
            Bwin++;
        }

    }
    if (Awin == Bwin){
        printf("draw\n");
    }
    else if (Awin > Bwin){
        printf("A\n");
    }
    else{
        printf("B\n");
        //printf("%d",Bwin);
    }

}