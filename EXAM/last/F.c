#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char S[150000];
struct abc{
    int num;
    char S;
    char turn;
}x[1000];
int cmp2(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b ;	
    
}

int cmp(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b ;
}


char ex[50] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main()
{
    int len;
    gets(S);
    len = strlen(S);
    for (int i = 0; i < 26; i++ ){
        x[i].S = i+'a';
    }
    for (int i = 0; i < len; i++ ){
        if (S[i] <= 'z' && S[i] >= 'a'){
            x[S[i]-'a'].num ++;
        }
        if (S[i] <='Z' && S[i] >= 'A'){
            x[S[i]-'A'].num ++;
        }
    }
    qsort(x->num,26,sizeof(int),cmp);
    for (int i = 0;i < 26; i++ ){
        x[i].turn = ex[i];
    }
    qsort(x->S,26,sizeof(char),cmp2);
    
    for (int i = 0; i < len; i++ ){
        if (S[i] <= 'z' && S[i] >= 'a'){
            printf("%c",x[S[i]-'a'].turn-'A'+'a');
        }
        if (S[i] <= 'Z' && S[i] >= 'A'){
            printf("%c",x[S[i] -'A'].turn);
        }
    }
    printf("\n");
    return 0;


}