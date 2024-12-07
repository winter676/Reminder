#include<stdio.h>
#include<math.h>
int getasize(char type);
int main()
{
    int n,p,low,size;
    char type[200];
    long long address;
    gets(type);
    size = getasize(type[0]);
    //printf("%d\n\n\n",size)
    scanf("%d%d",&n,&p);
    for (int i = 0 ;i < p; i++ ){
        scanf("%d",&low);
        address = size*low;
        if (low >= n || low < 0){
            printf("Careless Otter!\n");
            continue;
        }
        else if ((address >> 32) >= 1){
            printf("Careless Otter!\n");
        }
        else{
            printf("0x%08llx\n", address);
        }
    }
    return 0;
}

int getasize(char type)
{
    if (type == 'i')//strstr(type,"int") != NULL
        return 4;
    if (type == 'c')
        return 1;
    if (type == 'f')
        return 4;
    if (type == 'd')
        return 8;
    if (type == 'l')
        return 8;
}