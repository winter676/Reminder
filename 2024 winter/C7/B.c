#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char dest[4000],src[4000],str[4000];
    int len;
    scanf("%s",dest);
    scanf("%s",src);
    strcat(src,dest);
    scanf("%s",&str);
    strcat(str,src);
    len = strlen(str);
    for (int i = len/2; i < len;i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}