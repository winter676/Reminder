#include <stdio.h>

void permute(int *arr, int N, int len, int *book) {
    if (len > N){
        for (int i = 1; i <= N; i++ ){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return ;
    }
    else{
        for (int i = 1; i <= N; i++ ){
            if (book[i] == 0){
                book[i]=1;
                arr[len] = i;
                permute(arr,N,len+1,book);
                book[i]=0;
            }
        }
    }
}

int main() {
    int N;
    
    scanf("%d", &N);

    int arr[20],book[20];
    for (int i = 0; i < 20; i++){
        arr[i] = 0;
        book[i] = 0; 
    }
    for (int i = 1; i <= N; i++) {
        arr[i] = i ;
    }

    permute(arr, N, 1, book);

    return 0;
}
