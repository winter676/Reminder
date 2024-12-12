#include<stdio.h>


int main()
{
    int n,x,a[1500];
    scanf("%d%d",&n,&x);
    for (int i = 0 ;i < n; i++ ){
        scanf("%d",&a[i]);
    }
    if (a[0] == x){
        printf("%d\n",a[n-1]);
    }
    else{
        for (int i = 1; i < n; i++ ){
            if (a[i] == x){
                printf("%d\n",a[i-1]);
                return 0;
            }
        }
        printf("-1\n");
    }
    return 0;
}