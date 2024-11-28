#include<stdio.h>
#include<string.h>
int main()
{
    int n,j;
    char buf[1500],str[1500];
    char *p1 = buf,*p2 = str,*temp = NULL;
    gets(buf);
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++ ){
        gets(str);
        if (strstr(p1,p2) == NULL){
            printf("Spell Not Found!\n");
        }
        else{
            temp = strstr(p1,p2);
            j = (int)(temp - p1);
            printf("%d\n",j);
        }
    }

    return 0;
}