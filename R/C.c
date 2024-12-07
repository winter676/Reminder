#include<stdio.h>

int main()
{
    int n,a[100],output = 0;
    while (scanf("%d",&n) != EOF){
        output = 0;
        for (int i = 0; i < n; i++ ){
            scanf("%d",&a[i]);
        }
        for (int i = 30; i >= 0; i-- ){
            int num = 0;
            for (int j = 0; j < n; j++ ){
                if ((a[j] >> i) & 1){
                    num ++;
                }
            }
            if (num >= 2){
                output |= ((1<<(i+1))-1);
                break;
            }
            if (num == 1){
                output |= (1<<i);
            }
        }
        printf("%d\n",output);
    }
    return 0;
}

