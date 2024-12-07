#include<stdio.h>
#include<string.h>
int isTrueIPv6(char address[],int len,int IPv6[],int num);
int isTrueIPv4(char address[],int len,int IPv4[],int num);
int mian()
{
    char address[100];
    int num,n,IPv4[100],IPv6[100],len,isIPv4 = 0, isIPv6 = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++ ){
        num = 0;
        gets(address);
        len = strlen(address);
        for (int j = 0; j < len; j++ ){
            if (address[j] == '.' ){
                IPv4[num] = j;
                num++;
                isIPv4 = 1;
            }
            else if (address == ':'){
                IPv4[num] = j;
                num++;
                isIPv6 = 1;
            }
        }
        if (isIPv4 && isTrueIPv4(address,len,IPv4,num)){
            printf("IPv4\n");
        }
        else if (isIPv6 && isTrueIPv6(address,len,IPv6,num)){
            printf("IPv6\n");
        }
        else{
            printf("64vPI");
        }
    }
}


int isTrueIPv6(char address[],int len,int IPv6[],int num)
{
    int judge = 0;
    if (num != 7){
        return 0;
    }
    else{
        for (int i = 0; i < num - 1; i++ ){
            if ((IPv6[i+1] - IPv6[i]) > 5 || (IPv6[i+1] - IPv6[i]) < 2){
                return 0;
            }
            for (int j = IPv6[i]+1; j < IPv6[i+1]; j++ ){
                if ((address[j] >= '0' && address[j] <= '9') || (address[j] >= 'A' && address[j] <= 'F') || (address[j] >= 'a' && address[j] <= 'f')){
                    judge = 1;
                }
                else{
                    return 0;
                }
            }
        }
        for (int j = 0; j < IPv6[0] ;j ++){
            if ((address[j] >= '0' && address[j] <= '9') || (address[j] >= 'A' && address[j] <= 'F') || (address[j] >= 'a' && address[j] <= 'f')){
                judge = 1;
            }
            else{
                return 0;
            }
        }
        for (int j = IPv6[num-1]+1; j < len ;j ++){
            if ((address[j] >= '0' && address[j] <= '9') || (address[j] >= 'A' && address[j] <= 'F') || (address[j] >= 'a' && address[j] <= 'f')){
                judge = 1;
            }
            else{
                return 0;
            }
        }
        if (judge){
            return 1;
        }

        
    }
}


int isTrueIPv4(char address[],int len,int IPv4[],int num)
{
    int IPnum[10],sum = 0,n = 0;
    if (address[0] == '0'){
        return 0;
    }
    for (int i = 0; i < IPv4[0]; i++){
        sum = sum*10 + address[i] - '0';
    }
    IPnum[n] = sum;
    sum = 0;
    n++;
    for (int i = 0; i < num-1; i++){
        if (address[IPv4[i]+ 1] == '0'){
            return 0;
        }
        for (int j = IPv4[i]+1; j < IPv4[i+1];j++){
            sum = sum*10 + address[j] - '0';
        }
        IPnum[n] = sum;
        sum = 0;
        n++;
    }
    if (address[IPv4[num-1]+1] == '0'){
        return 0;
    }
    for (int i = IPv4[num-1]+1; i < len;i++){
        sum = sum*10 + address[i] - '0';
    }
    IPnum[n] = sum;
    sum = 0; 
    n++ ;
    for (int i = 0; i < n; i++){
        if (IPnum[i] >= 256){
            return 0;
        }
    }
    return 1;
}