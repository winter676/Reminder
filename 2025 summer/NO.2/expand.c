#include<stdio.h>

int main()
{
    char before=' ',now,after;
    while (scanf("%c",&now)!=EOF){
        if (now != '-'){
            printf("%c",now);
            before = now;
            continue;
        }
        if (now == '-' && before == ' '){
            printf("%c",now);
            before = now;
            continue;
        }
        scanf("%c",&after);
        if (('a'<=before && before <='z' && 'a'<=after && before<='z') || ('A'<=before && before<='Z' && 'A'<=after && after<='Z') || ('0'<=before && before<='9' && '0'<=after && after<='9')){
            for (int i = before+1; i <= after; i++ ){
                printf("%c",i);
            }
        }
        else{
            printf("%c%c",now,after);
        }
        before = after;
    }
    return 0;
}