#include<stdio.h>
#include<string.h>

int cmp(char a,char b);
void replace(FILE *in,FILE *out,char *old_char,char *new_char);
int main()
{
    int c,d;
    char old_char[100],new_char[100];
    FILE *in,*out;

    gets(old_char);
    gets(new_char);

    in = fopen("filein.txt","r");
    out = fopen("fileout.txt","w");

    replace(in,out,old_char,new_char);

    fclose(in);
    fclose(out);

    return 0;
}



void replace(FILE *in,FILE *out,char *old_char,char *new_char)
{
    char ch;
    int char_num = 0,isRight[10000];
    int len_new_char = strlen(new_char),len_old_char = strlen(old_char);
    char file_char[10000];
    
    for (int i = 0; i < 10000;i++){
        isRight[i]=0;
    }

    while((ch = fgetc(in))!=EOF){
        file_char[char_num++]=ch;
    }

    //记录与字符串匹配的初始位置
    for (int i = 0; i < char_num;i++ ){
        int same = 0;
        for (int j = 0; j < len_old_char; j++ ){
            if (cmp(file_char[i+j],old_char[j])==0){
                break;
            }
            else{
                same++;
            }
        }
        if (same == len_old_char){
            isRight[i] = 1;
        }
    }

    //读入到文件
    for (int i = 0; i < char_num;i++ ){
        if (isRight[i] == 1){
            for (int j = 0;j < len_new_char;j++){
                fputc(new_char[j],out);
            }
            i+=(len_old_char-1);
        }
        else{
            fputc(file_char[i],out);
        }
    }
}


int cmp(char a,char b)
{
    if (a == b){
        return 1;
    }
    if ((b - a) == 32 && (a<= 'Z' && a>= 'A')){
        return 1;
    }
    if ((a - b) == 32 && (a <= 'z' && a>= 'a')){
        return 1;
    }
    return 0;
}