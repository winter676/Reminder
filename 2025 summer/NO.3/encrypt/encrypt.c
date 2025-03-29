#include<stdio.h>
#include<string.h>
int main()
{
    int isUsed[30],len=0;
    char secret[30],secret_char,in_char;
    for (int i = 0; i < 30; i++ ){
        isUsed[i] = 0;
    }
    while (scanf("%c",&secret_char) != EOF){
        if (secret_char == '\n') break;
        if (isUsed[secret_char-'a']){
            continue;
        }
        else{
            secret[len++] = secret_char;
            isUsed[secret_char-'a'] = 1;
        }
    }
    for (int i = 'z'; i >= 'a';i-- ){
        if (isUsed[i-'a']){
            continue;
        }
        else{
            secret[len++] = i;
        }
    }


    FILE *in,*out;
    in = fopen("encrypt.txt","r");
    out = fopen("output.txt","w");

    while ((in_char = fgetc(in)) != EOF){
        if (!(in_char >= 'a' && in_char <= 'z')){
            fputc(in_char,out);
        }
        else{
            fputc(secret[in_char-'a'],out);
        }
    }



    return 0;
}