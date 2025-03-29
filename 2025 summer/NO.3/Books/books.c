#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp_by_name(const void *a,const void *b);

typedef struct book{
    char name[100];
    char writer[50];
    char publicer[50];
    char date[20];
    int visual;
}BOOK;

int main()
{
    int option,num=0;
    char find[100];
    BOOK books[600];
    FILE *in,*out;
    in = fopen("books.txt","r");
    out = fopen("ordered.txt","w");

    while (fscanf(in,"%s %s %s %s",books[num].name,books[num].writer,books[num].publicer,books[num].date) != EOF){
        num ++;
    }
    for (int i = 0; i < 600;i ++ ){
        books[i].visual = 1;
    }
    qsort(books,num,sizeof(books[0]),cmp_by_name);
    while (scanf("%d",&option) != EOF){
        getchar();
        if (option == 1){
            scanf("%s %s %s %s",books[num].name,books[num].writer,books[num].publicer,books[num].date);
            books[num].visual = 1;
            num++;
            qsort(books,num,sizeof(books[0]),cmp_by_name);
        }
        else{
            if (option == 2){
                scanf("%s",find);
                for (int i = 0; i < num; i++ ){
                    if (books[i].visual == 1 && strstr(books[i].name,find) != NULL){
                        printf("%-50s%-20s%-30s%-10s\n",books[i].name,books[i].writer,books[i].publicer,books[i].date);
                    }
                }
            }
            if (option == 3){
                scanf("%s",find);
                for (int i = 0; i < num; i++ ){
                    if (strstr(books[i].name,find) != NULL){
                        books[i].visual = 0;
                    }
                }
            }
            if (option == 0){
                for (int i = 0; i < num; i++ ){
                    if (books[i].visual == 0){
                        continue;
                    }
                    else{
                        fprintf(out,"%-50s%-20s%-30s%-10s\n",books[i].name,books[i].writer,books[i].publicer,books[i].date);
                    }
                }
                break;
            }
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}


int cmp_by_name(const void *a,const void *b)
{
    char *str1 = ((BOOK *)a)->name;
    char *str2 = ((BOOK *)b)->name;
    int result = strcmp(str1, str2);
    if (result == 0) {
        return 0; 
    }
    return result;
}