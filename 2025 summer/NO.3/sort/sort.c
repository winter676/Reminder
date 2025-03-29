#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sort
{
    char name[100];
    char phonenum[20];
}SORT;
void bubble_sort(SORT arr[], int n);
int main()
{
    int n,num = 1,judge = 1;
    char lastname[100] = "";
    SORT person[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        scanf("%s %s",person[i].name,person[i].phonenum);
    }
    bubble_sort(person, n);
    for (int i = 0; i < n; i++ ){
        if (strcmp(lastname,person[i].name) != 0){
            printf("%s %s\n",person[i].name,person[i].phonenum);
            num = 1;
            strcpy(lastname,person[i].name);
        }
        else{
            judge = 1;
            for (int j = num; j > 0; j-- ){
                if (strcmp(person[i-j].phonenum,person[i].phonenum) == 0){
                    judge = 0;
                    break;
                }
            }
            if (judge){
                printf("%s_%d %s\n",person[i].name,num,person[i].phonenum);
                num++;
            }
        }
    }
    return 0;
}



void bubble_sort(SORT arr[], int n)
{
    int i, j;
    SORT temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j].name, arr[j+1].name) > 0) {
                // 交换元素
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}