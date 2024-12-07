#include<stdio.h>
#include<stdlib.h>
int acmp(const void *a, const void *b);
int oringin[600000];
int main()
{
    int n,t,num,judge = 1;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        scanf("%d",&oringin[i]);
    }
    scanf("%d",&t);
    for (int i = 0; i < t; i++ ){
        scanf("%d",&num);
        if (num > oringin[n-1]){
            printf("I'm not sure!\n");
        }
        else{
            int *ret = bsearch(&num,oringin,n,sizeof(int),acmp);
            if (ret == NULL){
                printf("It can't be a prime!\n");
            }
            else{
                printf("It must be %d-th prime!\n",ret-oringin+1);
            }
        }
    }
}

int acmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}