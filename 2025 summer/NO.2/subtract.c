#include<stdio.h>
#include<string.h>

void removeZero(char *str);
int compare(char *a,char *b);
void subtract(char *a,char *b,char *result);

int main()
{
    char a[100],b[100],result[100];
    scanf("%s",a);
    scanf("%s",b);

    removeZero(a);
    removeZero(b);

    int comp = compare(a,b);
    if (comp < 0){ //a < b
        subtract(b,a,result);
        printf("-%s\n",result);
    }
    else if(comp > 0){
        subtract(a,b,result);
        printf("%s\n",result);
    }
    else{
        printf("0\n");
    }
    return 0;
}

void removeZero(char *str)
{
    int len = strlen(str);
    int i = 0; //i表示有效数字前0的个数
    while (i < len && str[i] == '0'){
        i++;
    }
    if (i == len){
        str[0] = '0';
        str[1] = '\0';
    }
    else{
        for (int j = 0; j < len - i; j++ ){
            str[j] = str[j+i];
        }
        str[len-i] = '\0';
    }
}

int compare(char *a,char *b)
{
    int lenofa = strlen(a);
    int lenofb = strlen(b);
    if (lenofa > lenofb){
        return 1;
    }
    if (lenofa < lenofb){
        return -1;
    }
    return strcmp(a,b);
}

void subtract(char *a,char *b, char *result)
{
    int lenofa = strlen(a);
    int lenofb = strlen(b);
    int carry = 0;
    int res[lenofa];

    for (int i = 0; i < lenofa; i++ ){
        res[i] = 0;
    }

    for (int i = lenofa - 1,j = lenofb -1; j >= 0 || i >= 0; i--,j--){
        int numa = a[i] - '0';
        int numb = j >= 0 ? b[j]-'0':0;
        int dif = numa-numb-carry;
        if (dif >= 0){
            carry = 0;
            res[i] = dif;
        }
        else{
            dif += 10;
            carry = 1;
            res[i] = dif;
        }
    }
    /*for (int i = 0; i < lenofa; i++){
        printf("%d\n",res[i]);
    }*/

    int start = 0;
    while (start < lenofa && res[start] == 0){
        start ++;
    }
    //printf("%d\n\n",start);
    if (start == lenofa){
        result[0] = '0';
        result[1] = '\0';
    }
    else{
        for (int i = start,j = 0; i < lenofa; i++,j++){
            result[j] = res[i] + '0';
        }
        result[lenofa-start] = '\0';
    }
}


/*void subtract(char *a, char *b, char *result) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0;
    int i, j, k;

    // 结果数组
    int res[maxLen + 1];
    for (i = 0; i <= maxLen; i++) {
        res[i] = 0;
    }

    // 从最低位开始减
    for (i = lenA - 1, j = lenB - 1, k = maxLen - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int digitA = i >= 0 ? a[i] - '0' : 0;
        int digitB = j >= 0 ? b[j] - '0' : 0;
        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res[k] = diff;
    }

    // 处理最高位的进位
    if (carry) {
        res[0] = 1;
    }

    for (int i = 0; i < maxLen+1; i++ ){
        printf("%d\n",res[i]);
    }
    // 将结果转换为字符串
    int start = 0;
    while (start < maxLen && res[start] == 0) {
        start++;
    }
    //printf("%d\n",start);
    if (start == maxLen) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        for (i = start, j = 0; i < maxLen; i++, j++) {
            result[j] = res[i] + '0';
        }
        result[j] = '\0';
    }
}*/