#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char book[2000],key[2000];
    char *p1 = book,*p2 = key,*p3 = book;
    gets(book);
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++ ){
        fgets(key,sizeof(key),stdin);
        key[strlen(key) - 1] = '\0';
        p1 = book;
        p2 = key;
        if (strstr(p1,p2) == NULL){
            printf("Spell Not Found!");
        }
        else{
            while (strstr(p1,p2) != NULL){
                printf("%d ",(int)(strstr(p1,p2) - p3));
                p1 = strstr(p1,p2) + 1;
            }
        }
        printf("\n");
    }
    return 0;
}